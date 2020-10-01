object GCD extends App {
  def GCD(num1: Int, num2: Int): Int = {
    def iterate(a: Int, b: Int): Int = {
      if (b == 0) {
        return a
      } else {
        return iterate(b, a % b)
      }
    }
    return iterate(num1, num2)
  }

  GCD(30, 105) // res1: Int = 15
  GCD(105, 30) // res2: Int = 15
}
