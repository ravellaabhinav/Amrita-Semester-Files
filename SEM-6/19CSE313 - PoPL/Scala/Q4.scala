/*
You are aware of the == that checks the equality of two lists. Write a functional
Scala program isEqual that accepts two lists (may even contain nested list
elements!!) and checks whether the two lists are equal? For example isEqual
(1,(2,3),(4,5,6)) (1, (2,3), (4,5)) should return False.
*/

def isEqual(l1:List[Any], l2:List[Any]):Boolean = {
  if (l1.length != l2.length) false
  else if (l1.isEmpty && l2.isEmpty) true
  else if (l1.head != l2.head) false
  else isEqual(l1.tail, l2.tail)
}
