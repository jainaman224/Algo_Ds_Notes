# Spiral Array

Spiral Array Algorithm traverses an array in a spiral order.

## Example

![Spiral Array](http://1.bp.blogspot.com/-CD9C_7oeI3I/VgwL3AO-IeI/AAAAAAAACBc/EG-WAf-y_7E/s1600/spiral-circular-matrix.jpg)

## Algorithm

```
Step-1 : Traverse the topmost row of array in left to right.
Step-2 : Increment the top variable.
Step-3 : Traverse the rightmost column of array from top to bottom.
Step-4 : Decrement the right variable.
Step-5 : Traverse the bottommost row of array from right to left.
Step-6 : Decrement the bottom variable.
Step-7 : Traverse the leftmost row of array from bottom.
Step-8 : Increment the left variable.
```

## Sample I/O

### INPUT

```
3 3
1 2 3
4 5 6
7 8 9
```

### OUTPUT

```
1 2 3 6 9 8 7 4 5
```
