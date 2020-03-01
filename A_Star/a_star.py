import numpy as np
import math

elements = {}
closed = {}
new_closed = {}
element_list = []
closed_list = []
new_closed_list = []
neighbours = []
path = []
visited_nodes = []

map = [[0,1,1,1,0,0,0,0],[0,1,0,1,0,0,0,0],[0,1,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0]]

def calc_heuristic(n1, n2):
    n1_x, n1_y = get_x_y(n1)
    n2_x, n2_y = get_x_y(n2)
    h = math.sqrt((n1_x - n2_x)**2 + (n1_y - n2_y)**2)
    return h

def calc_distance(n1, n2):
    n1_x, n1_y = get_x_y(n1)
    n2_x, n2_y = get_x_y(n2)
    d = math.sqrt((n1_x - n2_x)**2 + (n1_y - n2_y)**2)
    if(d > 1):
        d = 1
    return d

start = '7 7'
end = '0 0'

def get_x_y(node):
    node_x = ''
    node_y = ''
    x = True
    for i in node:
        if(i == ' '):
            x = False
            continue
        if(x == True):
            node_x += i
        else:
            node_y += i
    node_x = int(node_x)
    node_y = int(node_y)
    return node_x,node_y

x,y = get_x_y(start)
mila = 0
h = calc_heuristic(start,end)

def get_neighbours(node):
    curr_x, curr_y = get_x_y(node)
    neighbours = []
    for i in range(-1,2):
        if(((curr_x + i) < 0) or ((curr_x + i) > 7)):
                continue
        for j in range(-1,2):
            # if(i == j):
            #     continue
            # if(i == -1 and j == 1):
            #     continue
            # if(i == 1 and j == -1):
            #     continue
            if(i == 0 and j == 0):
                continue
            if(((curr_y + j) < 0) or ((curr_y + j) > 7)):
                continue
            if((str(curr_x + i)+' '+str(curr_y + j)) in closed):
                continue
            if(map[curr_x + i][curr_y+j] == 0):
                neighbours.append(str(curr_x + i)+' '+str(curr_y + j))
    return neighbours

def get_neighbours_trace(node):
    curr_x, curr_y = get_x_y(node)
    neighbours = []
    for i in range(-1,2):
        if(((curr_x + i) < 0) or ((curr_x + i) > 7)):
            continue
        for j in range(-1,2):
            # if(i == j):
            #     continue
            # if(i == -1 and j == 1):
            #     continue
            # if(i == 1 and j == -1):
            #     continue
            if(i == 0 and j == 0):
                continue
            if(((curr_y + j) < 0) or ((curr_y + j) > 7)):
                continue
            if(map[curr_x + i][curr_y+j] == 0):
                neighbours.append(str(curr_x + i)+' '+str(curr_y + j))
    return neighbours

def get_d_h(value):
    value_d = ''
    value_h = ''
    d = True
    for i in value:
        if(i == ' '):
            d = False
            continue
        if(d == True):
            value_d += i
        else:
            value_h += i
    value_d = float(value_d)
    value_h = float(value_h)
    return value_d,value_h

def astar_planning():
    elements[start] = '0 '+str(calc_heuristic(start,end))
    element_list.append(start)
    max_dist = 100
    while elements:
        print(element_list)
        print(elements)
        print()
        temp_elements = element_list
        max_dist = 1000
        for node in temp_elements:
            temp_d, temp_h = get_d_h(elements[node])
            total_d_h = temp_d + temp_h
            if(total_d_h < max_dist):
                max_dist = total_d_h
                main_node = node
        node_curr = main_node
        print(node_curr)
        element_list.remove(node_curr)
        node_curr_val = elements.pop(node_curr)
        closed[node_curr] = node_curr_val
        new_closed[node_curr] = node_curr_val
        closed_list.append(node_curr)
        new_closed_list.append(node_curr)
        if node_curr == end:
            break
        neighbours = get_neighbours(node_curr)
        for node in neighbours:
            base_d,_ = get_d_h(node_curr_val)
            d = calc_distance(node,node_curr)
            h = calc_heuristic(node,end)
            total_dist = base_d+d+h
            if(node in elements):
                curr_d, curr_h = get_d_h(elements[node])
                curr_total = curr_d + curr_h
                if(curr_total < total_dist):
                    elements.pop(node)
                    element_list.remove(node)
                    elements[node] = str(base_d + d) +' '+str(h)
                    element_list.append(node)
                continue
            elements[node] = str(base_d + d) +' '+str(h)
            element_list.append(node)    

def trace_path(start, end, closed, closed_list):
    node_test = end
    main_node = end
    path.append(main_node)
    hain = False
    while True:
        min_dist = 1000000
        print(node_test)
        print(path)
        print(closed_list)
        print()
        for i in closed_list:
            if(i == node_test):
                hain = True
        
        if hain == True:
            closed_list.remove(node_test)
            closed.pop(node_test)
        if hain == False:
            path.clear()
            new_closed_list.remove(node_test)
            closed_list = new_closed_list
            new_closed.pop(node_test)
            closed = new_closed
            node_test = end
            path.append(end)
            closed_list.remove(node_test)
            closed.pop(node_test)
        hain = False
        neighbours = get_neighbours_trace(node_test)
        for node_curr in neighbours:
            if(node_curr in closed_list):
                dist_d, dist_h = get_d_h(node_curr)
                total_dist = dist_d + dist_h
                if(total_dist < min_dist):
                    min_dist = total_dist
                    main_node = node_curr
        path.append(main_node)
        node_test = main_node
        if(main_node == start):
            break

astar_planning()
print(closed_list)
# new_closed = closed
# new_closed_list = closed_list[:]
trace_path(start, end, closed, closed_list)
print(path)