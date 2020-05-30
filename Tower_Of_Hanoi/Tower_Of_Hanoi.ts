function solveHanoi(
    count: number,
    from: string,
    to: string,
    other: string,
    move: (from: string, to: string) => void
)
{
    if (count > 0) {
        //shift plat "from" to "to" using "other" plate
        solveHanoi(count - 1, from, other, to, move)
        move(from, to)
        //shift plat "other" to "from" using "to" plate
        solveHanoi(count - 1, other, to, from, move)
    }
}
/**/
// Example: six discs
var moveCount = 0
solveHanoi(6, "Left", "Right", "Middle", (from , to) => {
    ++moveCount
    console.log(moveCount + ": Move Disk from " + from + " to " + to + ".")
})

//output for 3
/*
1: Move Disk from Left to Right.
2: Move Disk from Left to Middle.
3: Move Disk from Right to Middle.
4: Move Disk from Left to Right.
5: Move Disk from Middle to Left.
6: Move Disk from Middle to Right.
7: Move Disk from Left to Right.
*/

//output for 4
/*
1: Move Disk from Left to Middle.
2: Move Disk from Left to Right.
3: Move Disk from Middle to Right.
4: Move Disk from Left to Middle.
5: Move Disk from Right to Left.
6: Move Disk from Right to Middle.
7: Move Disk from Left to Middle.
8: Move Disk from Left to Right.
9: Move Disk from Middle to Right.
10: Move Disk from Middle to Left.
11: Move Disk from Right to Left.
12: Move Disk from Middle to Right.
13: Move Disk from Left to Middle.
14: Move Disk from Left to Right.
15: Move Disk from Middle to Right.
*/

//output for 6
/*
1: Move Disk from Left to Middle.
2: Move Disk from Left to Right.
3: Move Disk from Middle to Right.
4: Move Disk from Left to Middle.
5: Move Disk from Right to Left.
6: Move Disk from Right to Middle.
7: Move Disk from Left to Middle.
8: Move Disk from Left to Right.
9: Move Disk from Middle to Right.
10: Move Disk from Middle to Left.
11: Move Disk from Right to Left.
12: Move Disk from Middle to Right.
13: Move Disk from Left to Middle.
14: Move Disk from Left to Right.
15: Move Disk from Middle to Right.
16: Move Disk from Left to Middle.
17: Move Disk from Right to Left.
18: Move Disk from Right to Middle.
19: Move Disk from Left to Middle.
20: Move Disk from Right to Left.
21: Move Disk from Middle to Right.
22: Move Disk from Middle to Left.
23: Move Disk from Right to Left.
24: Move Disk from Right to Middle.
25: Move Disk from Left to Middle.
26: Move Disk from Left to Right.
27: Move Disk from Middle to Right.
28: Move Disk from Left to Middle.
29: Move Disk from Right to Left.
30: Move Disk from Right to Middle.
31: Move Disk from Left to Middle.
32: Move Disk from Left to Right.
33: Move Disk from Middle to Right.
34: Move Disk from Middle to Left.
35: Move Disk from Right to Left.
36: Move Disk from Middle to Right.
37: Move Disk from Left to Middle.
38: Move Disk from Left to Right.
39: Move Disk from Middle to Right.
40: Move Disk from Middle to Left.
41: Move Disk from Right to Left.
42: Move Disk from Right to Middle.
43: Move Disk from Left to Middle.
44: Move Disk from Right to Left.
45: Move Disk from Middle to Right.
46: Move Disk from Middle to Left.
47: Move Disk from Right to Left.
48: Move Disk from Middle to Right.
49: Move Disk from Left to Middle.
50: Move Disk from Left to Right.
51: Move Disk from Middle to Right.
52: Move Disk from Left to Middle.
53: Move Disk from Right to Left.
54: Move Disk from Right to Middle.
55: Move Disk from Left to Middle.
56: Move Disk from Left to Right.
57: Move Disk from Middle to Right.
58: Move Disk from Middle to Left.
59: Move Disk from Right to Left.
60: Move Disk from Middle to Right.
61: Move Disk from Left to Middle.
62: Move Disk from Left to Right.*/
