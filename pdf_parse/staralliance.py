
from parse import read_pages, layout_columns, data_columns, text_elements, bbox
from airport import airport_code, AIRPORT_CODE_RE
from codecs import open
import re
from sys import argv

LAYOUT_COLS = [x - 13 for x in [36, 174, 311, 449]]
FLIGHT_COLS = [x + 13 for x in [-2, 20, 44, 74, 88, 112]]
START_PAGE = 4

def main():
    csv_out = open(argv[2], 'w', 'utf-8')

    to_airport = None
    from_airport = None
    for pg, page in enumerate(read_pages(argv[1], START_PAGE)):
        elements = text_elements(page)
        elements = bbox(elements, top=735, bottom=31)
        columns = layout_columns(elements, LAYOUT_COLS) 
        for i, col in enumerate(columns):
            this_flight = None
            operated_by = ''
            effective_from = ''
            effective_to = ''
            for flight in data_columns(col, FLIGHT_COLS, 1):
                all_text = ' '.join(flight).strip()
                #print all_text

                if flight[0].startswith('To '):
                    airport = airport_code(all_text)
                    if airport:
                        to_airport = airport
                    continue

                cnt = False

                match = AIRPORT_CODE_RE.match(flight[4])
                if match:
                    from_airport = match.groups()[0]
                    continue
                match = re.match('Operated By (.+?)( For .+|;.+)?$', all_text)
                if match:
                    operated_by = match.groups()[0]
                    cnt = True
                match = re.match('Above Eff. (\d+/\d+)(?: thru (\d+/\d+))?$', all_text)
                if match:
                    effective_from, effective_to = match.groups()
                    cnt = True
                match = re.match('Above Disc. (\d+/\d+)$', all_text)
                if match:
                    effective_to = match.groups()[0]
                    cnt = True
                match = re.match('Above Ops (\d+/\d+) Only$', all_text)
                if match:
                    effective_from = effective_to = match.groups()[0]
                    cnt = True

                if cnt:
                    continue
                
                if this_flight:
                    if effective_to is None:
                        effective_to = ''
                    print >> csv_out, ','.join([
                        #str(pg),
                        #str(i),
                        from_airport,
                        to_airport,
                        operated_by,
                        effective_from,
                        effective_to
                    ] + this_flight)
                    operated_by = ''
                    effective_from = ''
                    effective_to = ''
                this_flight = flight

if __name__ == '__main__':
    main()

