#!/usr/bin/python

from collections import defaultdict
from bisect import bisect

from pdfminer.pdfparser import PDFParser, PDFDocument
from pdfminer.pdfinterp import PDFResourceManager, PDFPageInterpreter
from pdfminer.pdfdevice import PDFDevice
from pdfminer.layout import LAParams, LTTextLineHorizontal, LTChar, LTAnon
from pdfminer.converter import PDFPageAggregator

from sys import stderr


def split_text(text_line):
    segments = list()
    segment = ''
    loc = None
    for char in text_line:
        if loc == None:
            loc = (int(char.x0), int(char.y0))
        if isinstance(char, LTAnon):
            if segment.strip() != '':
                segments.append((loc, segment.strip()))
            segment = ''
            loc = None
        else:
            segment += char.get_text()
    return segments


def text_elements(layout):
    if isinstance(layout, LTTextLineHorizontal):
        for i in split_text(layout):
            yield i
    else:
        try:
            for a in layout:
                for x in text_elements(a):
                    yield x
        except TypeError:
            pass


def which_col(col_splits, x):
    '''
    >>> which_col([0, 10], 0)
    0
    >>> which_col([0, 10], 11)
    1
    >>> which_col([0, 10], 10)
    1
    >>> which_col([0, 10, 20, 30], 25)
    2
    >>> which_col([0, 10, 20, 30], 30)
    3
    '''
    i = bisect(col_splits, x)
    if i < 1:
        #print x, col_splits
        return None
    return i - 1


def bbox(elements, left=None, right=None, top=None, bottom=None):
    '''
    Yield elements whose x, y origin falls within or on the edges of
    a given bbox. Return elements with coordinates relative to the
    bottom-left of the given bbox. All bounds of the bbox are optional.
    
    >>> from itertools import product
    >>> a = product(product(range(10), range(10)), 'x')
    >>> list(bbox(a, 2, 4, 7, 6)) # doctest: +NORMALIZE_WHITESPACE
    [((0, 0), 'x'),
     ((0, 1), 'x'),
     ((1, 0), 'x'),
     ((1, 1), 'x'),
     ((2, 0), 'x'),
     ((2, 1), 'x')]
    '''
    for (x, y), text in elements:
        if left is not None and x < left:
            continue
        if right is not None and x > right:
            continue
        if top is not None and y > top:
            continue
        if bottom is not None and y < bottom:
            continue
        if left is not None:
            x -= left
        if bottom is not None:
            y -= bottom
        yield ((x, y), text)


def layout_columns(elements, col_splits):
    num_cols = len(col_splits)
    cols = list(list() for x in range(num_cols))
    for ((x, y), text) in elements:
        c = which_col(col_splits, x)
        if c is None:
            print >> stderr, x, text
        else:
            col_left = (col_splits)[c]
            cols[c].append(((x - col_left, y), text))
    for col in cols:
        col.sort(key=lambda ((x, y), text): (-y, x))
    return cols


def data_columns(elements, col_splits, error=0):
    '''
    >>> dat = data_columns([
    ...     ((0, 10), 'Jim'),
    ...     ((10, 10), 'Smith'),
    ...     ((40, 10), 'Vancouver'),
    ...     ((0, 20), 'Jane'),
    ...     ((5, 20), 'H.'),
    ...     ((10, 20), 'Scott'),
    ...     ((40, 20), 'Ottawa')],
    ...     (0, 10, 40))
    >>> dat.next()
    ['Jim', 'Smith', 'Vancouver']
    >>> dat.next()
    ['Jane H.', 'Scott', 'Ottawa']
    '''
    last_y = None
    row = [''] * len(col_splits)
    for (x, y), text in elements:
        if last_y is not None:
            if y < last_y - error:
                yield row
                row = [''] * len(col_splits)
        last_y = y
        c = which_col(col_splits, x)
        if c is None:
            print >> stderr, x, text
        if row[c]:
            #print x, text
            row[c] += ' '
        row[which_col(col_splits, x)] += text
    yield row
    

def read_pages(pdf_file, start_page=None, end_page=None):
    fp = open(pdf_file, 'rb')

    parser = PDFParser(fp)
    doc = PDFDocument()
    parser.set_document(doc)
    doc.set_parser(parser)
    doc.initialize()
    rsrcmgr = PDFResourceManager()
    laparams = LAParams()
    device = PDFPageAggregator(rsrcmgr, laparams=laparams)
    interpreter = PDFPageInterpreter(rsrcmgr, device)

    for i, page in enumerate(doc.get_pages()):
        if start_page is not None and i < start_page:
            continue
        if end_page is not None and i > end_page:
            break
        #print i, '----------------------------'
        interpreter.process_page(page)
        layout = device.get_result()
        yield layout

