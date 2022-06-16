object practice{
    def main(args: Array[String])={
        println("Hello, world!")
        println(factorail(30))
        println(max(1,2))
    }
    def factorail(n:BigInt):BigInt={
        if(n==1) 1 else n*factorail(n-1)
    }    
    def max(x:Int,y:Int):Int={
        if(x>y) x else y
        
    }

}
