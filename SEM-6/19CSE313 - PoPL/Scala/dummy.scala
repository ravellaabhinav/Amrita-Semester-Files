/*
Write a functional  Scala program interleave for 2 streams.
*/

object Interleave {
  def main(args: Array[String]): Unit = {
    val stream1 = Stream(1, 2, 3, 4, 5)
    val stream2 = Stream(6, 7, 8, 9, 10)
    val interleaved = interleave(stream1, stream2)
    println(interleaved.toList)
  }

  def interleave[A](stream1: Stream[A], stream2: Stream[A]): Stream[A] = {
    if (stream1.isEmpty) stream2
    else if (stream2.isEmpty) stream1
    else stream1.head #:: stream2.head #:: interleave(stream1.tail, stream2.tail)
  }
}

/*
object P03 {
  def main(args: Array[String]): Unit = {
    val list = List(List(1, 2, 3), List(1, 2, 3), 4, List(5, 6, 7))
    println(nestedRember(list, 1))
  }

  def nestedRember(list: List[Any], element: Any): List[Any] = {
    list.flatMap {
      case sublist: List[_] => nestedRember(sublist, element)
      case e if e == element => Nil
      case e => List(e)
    }
  }
*/  