/*
Write a scala program for round-robin scheduling alogorithm.
*/

object RoundRobin {
  def main(args: Array[String]): Unit = {
    val n = 5
    val bt = Array(1, 2, 6, 7, 9)
    val quantum = 3
    val wt = Array(0, 0, 0, 0, 0)
    val tat = Array(0, 0, 0, 0, 0)
    var t = 0
    var flag = true
    var i = 0
    while (flag) {
      if (bt(i) > 0) {
        t += 1
        if (bt(i) > quantum) {
          bt(i) -= quantum
          wt(i) += t - 1
        } else {
          wt(i) += t - 1
          tat(i) = t + bt(i) - 1
          bt(i) = 0
        }
      }
      if (bt(i) == 0) {
        i += 1
        if (i == n) {
          i = 0
        }
      }
      if (i == n - 1 && bt(n - 1) != 0) {
        flag = false
      }
    }
    println("Process\tBurst Time\tWaiting Time\tTurn Around Time")
    for (i <- 0 to n - 1) {
      print(i + "\t\t" + bt(i) + "\t\t" + wt(i) + "\t\t" + tat(i) + "\n")
    }
  }
}
