import scala.collection.mutable.ArrayBuffer


class Employee(val empname: String, val empage: String , val empsalary: String) {
   var name: String = empname
   var age: String = empage
   var salary: String = empsalary
}

var database:Array[Employee] = new Array[Employee](100)


object Crud{

    def Menu():Int = {
        println("=======Menu========")
        println("1. Insert")
        println("2. Update")
        println("3. Delete")
        println("4. read")
        println("5. Exit")
        println("===================")
        println("\nEnter your choice: ")
        var choice = scala.io.StdIn.readInt()
        return choice
    }

    def insert() = {
        var i = 0
        print("\nEnter name: ")
        var name = scala.io.StdIn.readLine()
        print("\nEnter age: ")
        var age = scala.io.StdIn.readLine()
        print("\nEnter salary: ")
        var salary =  scala.io.StdIn.readLine()
        var obj = new Employee(name, age, salary)
        database(i) = obj
        database(i+1) = null
        i += 1
    }

    def update() = {
        var i = 0
        print("\nEnter name : ")
        var name = scala.io.StdIn.readLine()
        print("\nEnter age : ")
        var age = scala.io.StdIn.readLine()
        print("\nEnter salary : ")
        var salary = scala.io.StdIn.readLine()
        while(database(i) != null){
            if(database(i).name == name){
                database(i).age = age
                database(i).salary = salary
            }
            i += 1
        }
        
    }

    def delete()= {
        var i = 0
        print("\nEnter name : ")
        var name = scala.io.StdIn.readLine()
        //delete name from database
        while(database(i) != null){
            if(database(i).name == name){
                database(i) = null
            }
            i += 1
        }
    }

    def read():Unit = {
        var i = 0
        while(i < database.length) {
            if(database(i) != null) {
                println("\nName: " + database(i).name)
                println("Age: " + database(i).age)
                println("Salary: " + database(i).salary)
            }else{
                return
            }
            i += 1
        }
    }

    def main(args: Array[String]):Unit = {

        var choice = Menu()
        while(choice != 5){
            if(choice == 1){
                insert()
            }else if(choice == 2){
                update()
            }else if(choice == 3){
                delete()
            }else if(choice == 4){
                read()
            }else if(choice == 5){
                println("\nExiting...")
            }else{
                println("\nInvalid choice")
            }
            choice = Menu()
        }
    }
}