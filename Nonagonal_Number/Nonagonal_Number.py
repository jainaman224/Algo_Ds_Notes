'''
    NONAGONAL NUMBER

    These numbers define the number of dots(or, verices), when a few nonagons
    (9-sided polygons) sharing a common corner are placed together.

    The nth Nonagonal Number has the formula : n * (7 * n - 5) / 2
'''

def nonagon(num):
    return (num * ((7 * num) - 5)) // 2

num = int(input())
print("The Nonagonal Number at position" , num , "is:" , nonagon(num))

'''
    Input : num = 5
    Output : The Nonagonal Number at position 5 is: 75
'''
