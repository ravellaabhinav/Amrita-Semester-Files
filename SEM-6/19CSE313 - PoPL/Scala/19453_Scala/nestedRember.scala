object practice {
  def main(args: Array[String]): Unit = {
    val list = List(List(1, 2, 3), List(4, 5, 6), 4, List(7, 8, 9))
    println(nestedRember(list, 3))
  }

  def nestedRember(list: List[Any], element: Any): List[Any] = {
    list match {
      case Nil => Nil
      case head :: tail =>
        head match {
          case subList: List[Any] => nestedRember(subList, element) :: nestedRember(tail, element)
          case _ => if (head == element) nestedRember(tail, element) else head :: nestedRember(tail, element)
        }
    }
  }
}