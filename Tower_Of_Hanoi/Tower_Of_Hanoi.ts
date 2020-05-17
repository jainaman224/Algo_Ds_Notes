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

//output for 6
/*
[LOG]: 1: Move from Left to Middle. 
[LOG]: 2: Move from Left to Right. 
[LOG]: 3: Move from Middle to Right. 
[LOG]: 4: Move from Left to Middle. 
[LOG]: 5: Move from Right to Left. 
[LOG]: 6: Move from Right to Middle. 
[LOG]: 7: Move from Left to Middle. 
[LOG]: 8: Move from Left to Right. 
[LOG]: 9: Move from Middle to Right. 
[LOG]: 10: Move from Middle to Left. 
[LOG]: 11: Move from Right to Left. 
[LOG]: 12: Move from Middle to Right. 
[LOG]: 13: Move from Left to Middle. 
[LOG]: 14: Move from Left to Right. 
[LOG]: 15: Move from Middle to Right. 
[LOG]: 16: Move from Left to Middle. 
[LOG]: 17: Move from Right to Left. 
[LOG]: 18: Move from Right to Middle. 
[LOG]: 19: Move from Left to Middle. 
[LOG]: 20: Move from Right to Left. 
[LOG]: 21: Move from Middle to Right. 
[LOG]: 22: Move from Middle to Left. 
[LOG]: 23: Move from Right to Left. 
[LOG]: 24: Move from Right to Middle. 
[LOG]: 25: Move from Left to Middle. 
[LOG]: 26: Move from Left to Right. 
[LOG]: 27: Move from Middle to Right. 
[LOG]: 28: Move from Left to Middle. 
[LOG]: 29: Move from Right to Left. 
[LOG]: 30: Move from Right to Middle. 
[LOG]: 31: Move from Left to Middle. 
[LOG]: 32: Move from Left to Right. 
[LOG]: 33: Move from Middle to Right. 
[LOG]: 34: Move from Middle to Left. 
[LOG]: 35: Move from Right to Left. 
[LOG]: 36: Move from Middle to Right. 
[LOG]: 37: Move from Left to Middle. 
[LOG]: 38: Move from Left to Right. 
[LOG]: 39: Move from Middle to Right. 
[LOG]: 40: Move from Middle to Left. 
[LOG]: 41: Move from Right to Left. 
[LOG]: 42: Move from Right to Middle. 
[LOG]: 43: Move from Left to Middle. 
[LOG]: 44: Move from Right to Left. 
[LOG]: 45: Move from Middle to Right. 
[LOG]: 46: Move from Middle to Left. 
[LOG]: 47: Move from Right to Left. 
[LOG]: 48: Move from Middle to Right. 
[LOG]: 49: Move from Left to Middle. 
[LOG]: 50: Move from Left to Right. 
[LOG]: 51: Move from Middle to Right. 
[LOG]: 52: Move from Left to Middle. 
[LOG]: 53: Move from Right to Left. 
[LOG]: 54: Move from Right to Middle. 
[LOG]: 55: Move from Left to Middle. 
[LOG]: 56: Move from Left to Right. 
[LOG]: 57: Move from Middle to Right. 
[LOG]: 58: Move from Middle to Left. 
[LOG]: 59: Move from Right to Left. 
[LOG]: 60: Move from Middle to Right. 
[LOG]: 61: Move from Left to Middle. 
[LOG]: 62: Move from Left to Right. 
[LOG]: 63: Move from Middle to Right. 
[LOG]: 1: Move Disk from Left to Middle. 
[LOG]: 2: Move Disk from Left to Right. 
[LOG]: 3: Move Disk from Middle to Right. 
[LOG]: 4: Move Disk from Left to Middle. 
[LOG]: 5: Move Disk from Right to Left. 
[LOG]: 6: Move Disk from Right to Middle. 
[LOG]: 7: Move Disk from Left to Middle. 
[LOG]: 8: Move Disk from Left to Right. 
[LOG]: 9: Move Disk from Middle to Right. 
[LOG]: 10: Move Disk from Middle to Left. 
[LOG]: 11: Move Disk from Right to Left. 
[LOG]: 12: Move Disk from Middle to Right. 
[LOG]: 13: Move Disk from Left to Middle. 
[LOG]: 14: Move Disk from Left to Right. 
[LOG]: 15: Move Disk from Middle to Right. 
[LOG]: 16: Move Disk from Left to Middle. 
[LOG]: 17: Move Disk from Right to Left. 
[LOG]: 18: Move Disk from Right to Middle. 
[LOG]: 19: Move Disk from Left to Middle. 
[LOG]: 20: Move Disk from Right to Left. 
[LOG]: 21: Move Disk from Middle to Right. 
[LOG]: 22: Move Disk from Middle to Left. 
[LOG]: 23: Move Disk from Right to Left. 
[LOG]: 24: Move Disk from Right to Middle. 
[LOG]: 25: Move Disk from Left to Middle. 
[LOG]: 26: Move Disk from Left to Right. 
[LOG]: 27: Move Disk from Middle to Right. 
[LOG]: 28: Move Disk from Left to Middle. 
[LOG]: 29: Move Disk from Right to Left. 
[LOG]: 30: Move Disk from Right to Middle. 
[LOG]: 31: Move Disk from Left to Middle. 
[LOG]: 32: Move Disk from Left to Right. 
[LOG]: 33: Move Disk from Middle to Right. 
[LOG]: 34: Move Disk from Middle to Left. 
[LOG]: 35: Move Disk from Right to Left. 
[LOG]: 36: Move Disk from Middle to Right. 
[LOG]: 37: Move Disk from Left to Middle. 
[LOG]: 38: Move Disk from Left to Right. 
[LOG]: 39: Move Disk from Middle to Right. 
[LOG]: 40: Move Disk from Middle to Left. 
[LOG]: 41: Move Disk from Right to Left. 
[LOG]: 42: Move Disk from Right to Middle. 
[LOG]: 43: Move Disk from Left to Middle. 
[LOG]: 44: Move Disk from Right to Left. 
[LOG]: 45: Move Disk from Middle to Right. 
[LOG]: 46: Move Disk from Middle to Left. 
[LOG]: 47: Move Disk from Right to Left. 
[LOG]: 48: Move Disk from Middle to Right. 
[LOG]: 49: Move Disk from Left to Middle. 
[LOG]: 50: Move Disk from Left to Right. 
[LOG]: 51: Move Disk from Middle to Right. 
[LOG]: 52: Move Disk from Left to Middle. 
[LOG]: 53: Move Disk from Right to Left. 
[LOG]: 54: Move Disk from Right to Middle. 
[LOG]: 55: Move Disk from Left to Middle. 
[LOG]: 56: Move Disk from Left to Right. 
[LOG]: 57: Move Disk from Middle to Right. 
[LOG]: 58: Move Disk from Middle to Left. 
[LOG]: 59: Move Disk from Right to Left. 
[LOG]: 60: Move Disk from Middle to Right. 
[LOG]: 61: Move Disk from Left to Middle. 
[LOG]: 62: Move Disk from Left to Right. 
[LOG]: 63: Move Disk from Middle to Right. 
[LOG]: 1: Move Disk from Left to Middle. 
[LOG]: 2: Move Disk from Left to Right. 
[LOG]: 3: Move Disk from Middle to Right. 
[LOG]: 4: Move Disk from Left to Middle. 
[LOG]: 5: Move Disk from Right to Left. 
[LOG]: 6: Move Disk from Right to Middle. 
[LOG]: 7: Move Disk from Left to Middle. 
[LOG]: 8: Move Disk from Left to Right. 
[LOG]: 9: Move Disk from Middle to Right. 
[LOG]: 10: Move Disk from Middle to Left. 
[LOG]: 11: Move Disk from Right to Left. 
[LOG]: 12: Move Disk from Middle to Right. 
[LOG]: 13: Move Disk from Left to Middle. 
[LOG]: 14: Move Disk from Left to Right. 
[LOG]: 15: Move Disk from Middle to Right. 
[LOG]: 16: Move Disk from Left to Middle. 
[LOG]: 17: Move Disk from Right to Left. 
[LOG]: 18: Move Disk from Right to Middle. 
[LOG]: 19: Move Disk from Left to Middle. 
[LOG]: 20: Move Disk from Right to Left. 
[LOG]: 21: Move Disk from Middle to Right. 
[LOG]: 22: Move Disk from Middle to Left. 
[LOG]: 23: Move Disk from Right to Left. 
[LOG]: 24: Move Disk from Right to Middle. 
[LOG]: 25: Move Disk from Left to Middle. 
[LOG]: 26: Move Disk from Left to Right. 
[LOG]: 27: Move Disk from Middle to Right. 
[LOG]: 28: Move Disk from Left to Middle. 
[LOG]: 29: Move Disk from Right to Left. 
[LOG]: 30: Move Disk from Right to Middle. 
[LOG]: 31: Move Disk from Left to Middle. 
[LOG]: 32: Move Disk from Left to Right. 
[LOG]: 33: Move Disk from Middle to Right. 
[LOG]: 34: Move Disk from Middle to Left. 
[LOG]: 35: Move Disk from Right to Left. 
[LOG]: 36: Move Disk from Middle to Right. 
[LOG]: 37: Move Disk from Left to Middle. 
[LOG]: 38: Move Disk from Left to Right. 
[LOG]: 39: Move Disk from Middle to Right. 
[LOG]: 40: Move Disk from Middle to Left. 
[LOG]: 41: Move Disk from Right to Left. 
[LOG]: 42: Move Disk from Right to Middle. 
[LOG]: 43: Move Disk from Left to Middle. 
[LOG]: 44: Move Disk from Right to Left. 
[LOG]: 45: Move Disk from Middle to Right. 
[LOG]: 46: Move Disk from Middle to Left. 
[LOG]: 47: Move Disk from Right to Left. 
[LOG]: 48: Move Disk from Middle to Right. 
[LOG]: 49: Move Disk from Left to Middle. 
[LOG]: 50: Move Disk from Left to Right. 
[LOG]: 51: Move Disk from Middle to Right. 
[LOG]: 52: Move Disk from Left to Middle. 
[LOG]: 53: Move Disk from Right to Left. 
[LOG]: 54: Move Disk from Right to Middle. 
[LOG]: 55: Move Disk from Left to Middle. 
[LOG]: 56: Move Disk from Left to Right. 
[LOG]: 57: Move Disk from Middle to Right. 
[LOG]: 58: Move Disk from Middle to Left. 
[LOG]: 59: Move Disk from Right to Left. 
[LOG]: 60: Move Disk from Middle to Right. 
[LOG]: 61: Move Disk from Left to Middle. 
[LOG]: 62: Move Disk from Left to Right. 
[LOG]: 63: Move Disk from Middle to Right. 
[ERR]: Executed JavaScript Failed: 
[ERR]: import declarations may only appear at top level of a module 
[LOG]: 1: Move Disk from Left to Middle. 
[LOG]: 2: Move Disk from Left to Right. 
[LOG]: 3: Move Disk from Middle to Right. 
[LOG]: 4: Move Disk from Left to Middle. 
[LOG]: 5: Move Disk from Right to Left. 
[LOG]: 6: Move Disk from Right to Middle. 
[LOG]: 7: Move Disk from Left to Middle. 
[LOG]: 8: Move Disk from Left to Right. 
[LOG]: 9: Move Disk from Middle to Right. 
[LOG]: 10: Move Disk from Middle to Left. 
[LOG]: 11: Move Disk from Right to Left. 
[LOG]: 12: Move Disk from Middle to Right. 
[LOG]: 13: Move Disk from Left to Middle. 
[LOG]: 14: Move Disk from Left to Right. 
[LOG]: 15: Move Disk from Middle to Right. 
[LOG]: 16: Move Disk from Left to Middle. 
[LOG]: 17: Move Disk from Right to Left. 
[LOG]: 18: Move Disk from Right to Middle. 
[LOG]: 19: Move Disk from Left to Middle. 
[LOG]: 20: Move Disk from Right to Left. 
[LOG]: 21: Move Disk from Middle to Right. 
[LOG]: 22: Move Disk from Middle to Left. 
[LOG]: 23: Move Disk from Right to Left. 
[LOG]: 24: Move Disk from Right to Middle. 
[LOG]: 25: Move Disk from Left to Middle. 
[LOG]: 26: Move Disk from Left to Right. 
[LOG]: 27: Move Disk from Middle to Right. 
[LOG]: 28: Move Disk from Left to Middle. 
[LOG]: 29: Move Disk from Right to Left. 
[LOG]: 30: Move Disk from Right to Middle. 
[LOG]: 31: Move Disk from Left to Middle. 
[LOG]: 32: Move Disk from Left to Right. 
[LOG]: 33: Move Disk from Middle to Right. 
[LOG]: 34: Move Disk from Middle to Left. 
[LOG]: 35: Move Disk from Right to Left. 
[LOG]: 36: Move Disk from Middle to Right. 
[LOG]: 37: Move Disk from Left to Middle. 
[LOG]: 38: Move Disk from Left to Right. 
[LOG]: 39: Move Disk from Middle to Right. 
[LOG]: 40: Move Disk from Middle to Left. 
[LOG]: 41: Move Disk from Right to Left. 
[LOG]: 42: Move Disk from Right to Middle. 
[LOG]: 43: Move Disk from Left to Middle. 
[LOG]: 44: Move Disk from Right to Left. 
[LOG]: 45: Move Disk from Middle to Right. 
[LOG]: 46: Move Disk from Middle to Left. 
[LOG]: 47: Move Disk from Right to Left. 
[LOG]: 48: Move Disk from Middle to Right. 
[LOG]: 49: Move Disk from Left to Middle. 
[LOG]: 50: Move Disk from Left to Right. 
[LOG]: 51: Move Disk from Middle to Right. 
[LOG]: 52: Move Disk from Left to Middle. 
[LOG]: 53: Move Disk from Right to Left. 
[LOG]: 54: Move Disk from Right to Middle. 
[LOG]: 55: Move Disk from Left to Middle. 
[LOG]: 56: Move Disk from Left to Right. 
[LOG]: 57: Move Disk from Middle to Right. 
[LOG]: 58: Move Disk from Middle to Left. 
[LOG]: 59: Move Disk from Right to Left. 
[LOG]: 60: Move Disk from Middle to Right. 
[LOG]: 61: Move Disk from Left to Middle. 
[LOG]: 62: Move Disk from Left to Right. 
[LOG]: 63: Move Disk from Middle to Right. 
Popular Documentation Pages
*/
