def nestedSetUnion(list1: List[Any], list2: List[Any]): List[Any] = {
  (list1, list2) match {
    case (Nil, _) => list2
    case (_, Nil) => list1
    case (x :: xs, y :: ys) =>
      if (x == y) nestedSetUnion(xs, ys)
      else x :: nestedSetUnion(xs, ys)
  }
}

println(nestedSetUnion(((1,2),3,4), ((1,2),(3,4))))
