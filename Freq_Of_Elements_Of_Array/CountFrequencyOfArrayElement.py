"""
Problem Statement
Given a list of elements find the frequency of each element
"""
from collections import defaultdict


def count_frequency(arr: list) -> dict:
    """
    >>> from collections import Counter
    >>> LIST = [1,2,2,3,4,5,1]
    >>> count_dict = count_frequency(LIST)
    >>> all(count_dict[ele] == count for ele, count in Counter(LIST).items())
    True
    """
    # Initializing default dictionary for frequency storage
    frequency = defaultdict(int)
    for element in arr:
        frequency[element] += 1
    return frequency


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    print("Element \t Frequency")
    for ele, freq in count_frequency(arr).items():
        # Printing Frequencies
        print(f"{ele} \t\t {freq}")


"""
Input :
1 2 3 2 3 4 6 2
Output :
Element          Frequency
1                1
2                3
3                2
4                1
6                1
"""
