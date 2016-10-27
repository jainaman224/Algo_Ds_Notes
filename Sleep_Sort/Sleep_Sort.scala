object SleepSort {
  def sort(nums:Seq[Int])=nums foreach {n =>
    scala.concurrent.ops.spawn{
      Thread.sleep(500*n)
      print(n+" ")
    }
  }
 
  def main(args:Array[String])={
    sort(args map (_.toInt))
  }
}

/*
Output:
> scala SleepSort 1 9 8 7 6 5 3 4 5 2 0
0 1 2 3 4 5 5 6 7 8 9
*/
