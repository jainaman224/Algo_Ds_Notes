function solveHanoi(
    count: number,
    from: string,
    to: string,
    other: string,
    move: (from: string, to: string) => void
)
{
    if (count > 0) {
        solveHanoi(count - 1, from, other, to, move)
        move(from, to)
        solveHanoi(count - 1, other, to, from, move)
    }
}
// Example: six discs
var moveCount = 0
solveHanoi(6, "Left", "Right", "Middle", (from , to) => {
    ++moveCount
    console.log(moveCount + ": Move Disk from " + from + " to " + to + ".")
})
