'''
Leap year is an year with 366 days. Leap Year should be divisible by 4.
Also it should be divisible by 400 and not divisible by 100.
'''

def checkLeapYear(year):
    if year % 400 == 0:
        return 1

    if year % 100 == 0:
        return 0

    if year % 4 == 0:
        return 1

    return 0

year1 = int(input("Enter the first year:\n"))
year2 = int(input("Enter the second year:\n"))
print("The leap years between %d and %d are:" % (year1, year2))
for year in range(year1, year2):
    if checkLeapYear(year) == 1:
        print(year)

'''
Input:
2000
2050

Output:
The leap years between 2000 and 2050 are:
2000
2004
2008
2012
2016
2020
2024
2028
2032
2036
2040
2044
2048
'''
