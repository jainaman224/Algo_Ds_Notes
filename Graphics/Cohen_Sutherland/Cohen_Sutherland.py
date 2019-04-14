#!/usr/bin/env python
# Python program to implement Cohen Sutherland algorithm
# for line clipping.
import matplotlib.pyplot as plt
# Defining xmax,ymax and xmin,ymin for rectangle
xmax = 400.0
ymax = 400.0
xmin = 100.0
ymin = 100.0

# 4 bit code according to respective regions
inside = 0  # 0000
top = 8	    # 1000
bottom = 4  # 0100
right = 2   # 0010
left = 1    # 0001


# Function to find region code for a point(x,y)
def find_code(x, y):
    code = inside
    if x < xmin:        # to the left of rectangle
        code |= left
    elif x > xmax:		# to the right of rectangle
        code |= right
    if y < ymin:	 	# below the rectangle
        code |= bottom
    elif y > ymax:		# above the rectangle
        code |= top

    return code


# Implemention of Cohen Sutherland Algorithm
# In order to clip a line from P to Q
def CohenSutherlandClipping(x1, y1, x2, y2):

    # find region codes for P, Q
    p = find_code(x1, y1)  	# find code for P
    q = find_code(x2, y2)   # find code for Q
    accept = 0

    while True:
        if p == 0 and q == 0:  # If both points are inside the rectangle
            accept = 1
            break

        elif (p & q) != 0:    # If both points are outside rectangle
            break

        # Some portion of line lies inside the
        # rectangle and rest outside the rectangle
        else:

            # Line Needs clipping
            # At least one of the points is outside the rectangle,
            # therefore select it,
            x = 1.0
            y = 1.0
            if p != 0:
                point_out = p
            else:
                point_out = q

            # Find  the intersection point using formulas:
            #  y = y1 + slope * (x - x1),
            #  x = x1 + (1 / slope) * (y - y1)

            if point_out & top:
                # If line crosses ymin
                # point is above the clip rectangle
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1)
                y = ymax

            elif point_out & bottom:
                # If line crosses ymin
                # point is below the clip rectangle
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1)
                y = ymin

            elif point_out & right:
                # If line crosses xmax
                # point is to the right of the clip rectangle
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1)
                x = xmax

            elif point_out & left:
                # If line crosses xmin
                # point is to the left of the clip rectangle
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1)
                x = xmin

            # Now intersection point x,y is found so
            # We replace point outside clipping rectangle
            # by intersection point
            if point_out == p:
                x1 = x
                y1 = y
                p = find_code(x1, y1)

            else:
                x2 = x
                y2 = y
                q = find_code(x2, y2)
    if accept:
        print(" The line accepted from %.2f,%.2f to %.2f,%.2f" % (x1, y1, x2, y2))

    else:
        print("The line is rejected")


x1 = int(input("Enter x1"))
x2 = int(input("Enter x2"))
y1 = int(input("Enter y1"))
y2 = int(input("Enter y2"))

CohenSutherlandClipping(x1, x2, y1, y2)

# Sample Input 1
# CohenSutherlandClipping(120, 350, 60, 450)
# Output 1
# The line accepted from 120.00,350.00 to 100.00,383.33

# line before clipping
# https://drive.google.com/file/d/1xnz25GTDN-I7IjG4ia9Un1DEj_xE6gDU/view?usp=sharing
# line after clipping
# https://drive.google.com/file/d/1hQ0rzD-YAYYXx68x9ElwvOEY5t7QV5zu/view?usp=sharing

# Plotting the graph
plt.plot(x1, x2, y1, y2)
plt.show()
