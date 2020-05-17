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
