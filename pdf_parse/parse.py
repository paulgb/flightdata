#!/usr/bin/python

from __future__ import print_function
from collections import defaultdict
import re

from pdfminer.pdfparser import PDFParser, PDFDocument
from pdfminer.pdfinterp import PDFResourceManager, PDFPageInterpreter
from pdfminer.pdfdevice import PDFDevice
from pdfminer.layout import LAParams, LTTextLineHorizontal, LTChar, LTAnon
from pdfminer.converter import PDFPageAggregator

def airport_code(st):
    '''
    >>> airport_code('FOO (BAR)')
    'BAR'
    '''
    return re.search('\((.{3})\)', st).groups()[0]

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

def iter_elements(layout):
    if isinstance(layout, LTTextLineHorizontal):
        for i in split_text(layout):
            yield i
    else:
        try:
            for a in layout:
                for x in iter_elements(a):
                    yield x
        except TypeError:
            pass

def which_col(col_splits, x):
    '''
    >>> which_col([0, 10], 0)
    0
    >>> which_col([0, 10], 11)
    1
    >>> which_col([0, 10, 20, 30], 25)
    2
    '''
    col_splits = list(enumerate(col_splits))
    while col_splits:
        (i, c) = col_splits.pop(0)
        if c > x:
            return i - 1
    return i


def column_split(elements, col_splits):
    num_cols = len(col_splits)
    cols = list(list() for x in range(num_cols))
    for ((x, y), text) in elements:
        c = which_col(col_splits, x)
        col_left = (col_splits)[c]
        cols[c].append(((x - col_left, y), text))
    return cols


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
        interpreter.process_page(page)
        layout = device.get_result()
        yield layout

FLIGHT_COLS = [0, 22, 45, 78, 97, 126, 197]

def process_flights(col):
    from_airport = ''
    to_airport = ''
    flights = defaultdict(lambda: [''] * 7)

    for ((x, y), text) in col:
        #print(x, y, text)
        if y in [752, 739] and x < 2:
            try:
                if text.startswith('TO'):
                    to_airport = airport_code(text)
                elif text.startswith('FROM'):
                    from_airport = airport_code(text)
            except AttributeError:
                break
        elif text.startswith('Operated By'):
            pass
        elif text.startswith('Schedules continue'):
            pass
        elif text.startswith('Consult your'):
            pass
        elif y <= 706:
            col = which_col(FLIGHT_COLS, x)
            flights[y][col] += text

    for flight in flights.values():
        flight[2] = flight[2].replace(' ', '')
        yield tuple([from_airport, to_airport] + flight)

def main():
    for page in read_pages('oneworld.pdf', 5):
        elements = iter_elements(page)
        #for elem in elements:
        #    print(elem)
        columns = column_split(elements, [35, 262])
        for col in columns:
            for flight in process_flights(col):
                print(','.join(flight))

if __name__ == '__main__':
    main()

