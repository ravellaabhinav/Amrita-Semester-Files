/*
You are aware that intersect method accepts two lists to give the elements
that are part of the lists. For example
List(List(1,2),3,4,5).intersect(List(List(7,8),List(1,2),4,5)
) returns List(List(1, 2), 4, 5). Write a functional Scala program common
that implements the intersect method that should work even for nested lists.
*/
def intersect[A](l1: List[A], l2: List[A]): List[A] = {
  l1.flatMap(x => l2.filter(y => x == y))
}

println(intersect(List(List(1,2),3,4,5), List(List(7,8),List(1,2),4,5)))