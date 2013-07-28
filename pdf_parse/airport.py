
import re

AIRPORT_CODE_RE = re.compile('\((.{3})\)')

def airport_code(st):
    '''
    >>> airport_code('FOO (BAR)')
    'BAR'
    >>> print airport_code('FOO')
    None
    '''
    #match = re.search('\((.{3})\)', st)
    match = AIRPORT_CODE_RE.search(st)
    if match:
        return match.groups()[0]
    return None

