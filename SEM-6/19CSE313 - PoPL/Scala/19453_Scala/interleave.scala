def nestedInterleave(l1: List[Any], l2: List[Any]): List[Any] = {
  (l1, l2) match {
    case (Nil, Nil) => Nil
    case (Nil, _) => l2
    case (_, Nil) => l1
    case (h1::t1, h2::t2) => h1::h2::nestedInterleave(t1, t2)
  }
}
