# Egg Drop problem

# Function for recursive approach
def eggDropRecursive(egg, floor):
    if floor == 0:
        return 0
    if egg == 1:
        return floor
    min = 999999
    for i in range(1, floor+1):
        sol = max(eggDropRecursive(egg-1, i-1), eggDropRecursive(egg, Floor-i)) + 1
        if sol < min:
            min = sol
    return min

# Function for recursive dynamic programming approach
def eggDropRecursiveDP(egg, floor, mem):
    if floor == 0:
        return 0
    if egg == 1:
        return floor
    if mem[egg][floor] != 0:
        return mem[egg][floor]
    min = 999999
    for i in range(1, floor + 1):
        sol = max(eggDropRecursiveDP(egg-1, i-1, mem), eggDropRecursiveDP(egg, floor-i, mem)) + 1
        if sol < min:
            min = sol
    mem[egg][floor] = min
    return min

# Function for iterative dynamic programming approach
def eggDropIterativeDP(eggs, floors, mem):
    for e in range(1, eggs+1):
        for f in range(1, floors+1):
            if f == 0:
                mem[e][f] = 0
            elif e == 1:
                mem[e][f] = f
            else:
                min = 999999
                for i in range(1, f+1):
                    sol = max(mem[e-1][i-1], mem[e][f-i]) + 1
                    if sol < min:
                        min = sol
                mem[e][f] = min;
    return mem[eggs][floors]

# Taking the user input for the number of eggs and floors
egg = int(input("Enter the number of eggs: "))
floor = int(input("Enter the number of floors: "))
mem = [[0 for i in range(0, floor+2)] for j in range(0, egg+2)]
print(eggDropIterativeDP(egg, floor, mem))

#Sample Output
#Enter the number of eggs: 5
#Enter the number of floors: 100
