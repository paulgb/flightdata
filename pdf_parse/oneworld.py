
from parse import read_pages, layout_columns, data_columns, text_elements, bbox
from airport import airport_code
from codecs import open

from sys import argv

LAYOUT_COLS = [34, 261]
FLIGHT_COLS = [0, 23, 45, 79, 98, 126, 162, 197]
CSV_COLS = ('valid_from', 'valid_to', 'valid_weekdays',
            'departure', 'arrival', 'flight_no',
            'aircraft', 'duration')
START_PAGE = 5

def main():
    csv_out = open(argv[2], 'w', 'utf-8')

    for page in read_pages(argv[1], START_PAGE):
        elements = text_elements(page)
        elements = bbox(elements, top=752)
        columns = layout_columns(elements, LAYOUT_COLS) 
        for col in columns:
            to_airport = ''
            from_airport = ''
            for flight in data_columns(col, FLIGHT_COLS):
                if flight[0].startswith('TO'):
                    to_airport = airport_code(flight[0])
                    continue
                if flight[0].startswith('FROM'):
                    from_airport = airport_code(flight[0])
                    continue
                if flight[0] == 'From-To':
                    continue
                if flight[0] == 'Validity':
                    continue
                if flight[2].startswith('Operated By'):
                    continue
                if flight[3].startswith('Operated By'):
                    continue
                if flight[1].startswith('Operated By'):
                    continue
                if flight[2] == 'Consult your travel agent for details':
                    continue
                if flight[2] == 'Schedules continue on following page':
                    continue
                if flight[0].startswith('('):
                    continue

                if from_airport is None:
                    continue

                flight = [from_airport, to_airport] + flight
                print >> csv_out, ','.join(flight)

if __name__ == '__main__':
    main()

