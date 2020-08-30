import xlrd as xr
import xlsxwriter as xw

namewb = "input.xlsx"
filein = xr.open_workbook(namewb)
sheet = filein.sheet_by_index(0)

fileout = open("output.csv", mode="w")

for i in range(0, sheet.nrows):
    for j in range(0, sheet.ncols):
        fileout.write(str(sheet.cell_value(i, j))+",")
    fileout.write("\n")

fileout.close()
        