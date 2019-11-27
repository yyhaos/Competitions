
import xlrd
def read(filename, sheetNO=0):
    book = xlrd.open_workbook(filename)
    sh=book.sheet_by_index(sheetNO)
    cols=sh.ncols
    rows=sh.nrows
    print('open file:' ,'cols=',cols,'rows=',rows)
    return sh
marked_useful_sh= read('marked_useful_sh.xlsx')
