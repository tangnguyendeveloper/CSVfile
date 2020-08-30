import xlrd as xr
import xlsxwriter as xw

outfile = xw.Workbook("output.xlsx")
outsheet = outfile.add_worksheet()

f = open("input.csv", mode="r")
s = list(f.read())
f.close()

j = 0
k = 0
strs = str("")
for i in s:
    if i != "," and i != "\n":
        strs += i
    if i == ",":
        outsheet.write(j, k, strs)
        strs = ""
        k += 1
    if i == "\n":
        outsheet.write(j, k, strs)
        strs = ""
        j += 1
        k = 0
        
outfile.close()

