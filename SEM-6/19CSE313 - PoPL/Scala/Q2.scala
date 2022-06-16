def occur(x:Int,xs:List[Int]):Int = {
  xs match {
    case Nil => 0
    case y::ys => if (y == x) 1 + occur(x,ys) else occur(x,ys)
  }
}

occur(5,List(1,2,5,2,5,2,5,2))
