def counting_sort(input):
    output = [0] * len(input)
    max = input[0]
    min = input[0]

    for i in range(1, len(input)):
        if input[i] > max:
            max = input[i]
        elif input[i] < min:
            min = input[i]

    k = max - min + 1

    count_list = [0] * k

    for i in range(0, len(input)):
        count_list[input[i] - min] += 1

    for i in range(1, k):
        count_list[i] += count_list[i - 1]

    for i in range(0, len(input)):
        output[count_list[input[i] - min] - 1] = input[i]
        count_list[input[i] - min] -= 1

    for i in range(0, len(input)):
        input[i] = output[i]


input = [1, 5, 2, 7, 3, 4, 4, 1, 5]

counting_sort(input)

print("Sorted list :", end = " ")
for i in range(0, len(input)):
    print(input[i], end = " ")


''' Output

Sorted list : 1  1  2  3  4  4  5  5  7

'''
