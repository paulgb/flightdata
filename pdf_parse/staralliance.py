
from parse import read_pages, layout_columns, data_columns, text_elements, bbox
from airport import airport_code
from codecs import open

LAYOUT_COLS = [36, 174, 311, 449]
FLIGHT_COLS = [0, 20, 44, 74, 88, 112]
START_PAGE = 4

def main():
    csv_out = open('oneworld.csv', 'w', 'utf-8')

    for page in read_pages('../datasource/staralliance.pdf', START_PAGE, START_PAGE):
        elements = text_elements(page)
        elements = bbox(elements, top=735, bottom=31)
        columns = layout_columns(elements, LAYOUT_COLS) 
        for col in columns:
            for flight in data_columns(col, FLIGHT_COLS, 1):
                print flight

if __name__ == '__main__':
    main()
