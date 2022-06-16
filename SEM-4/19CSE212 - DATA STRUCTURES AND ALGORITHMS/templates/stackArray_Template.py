"""The code has been developed by Dr.Vidhya Balasubramanian as part of the CSE230 Data Structures Course, ASE Coimbatore.
   The code is being constantly improved, so please bring to notice any bugs to dsdaa.amrita@gmail.com

   Modified and updated by: M. Vamsee Krishna Kiran.
   
"""
class MyStack():
    def __init__(self,size):
        self.stack = []
        # this is the stack container called 'stack'
        self.max_stack_size = size
        for i in range(self.max_stack_size):
            self.stack.append(None)
        # define the stack size 'max_stack_size' and initialize it
        
        #print(self.stack)

    # define the push operation which  pushes the value into the stack, must throw a stack full exception
    def push(self, value):
        self.printStack()
        return
        

    # returns top element of stack if not empty, else throws stack empty exception
    def pop(self):
        return None
        
        
    # returns top element without removing it if the stack is not empty, else throws exception   
    def top(self):
        return None
        

    # returns True if stack is empty   
    def isEmpty(self):
        return 

    # returns the number of elements currently in stack 
    def size(self):
        return 

    def delMid(self):              
        return

    def reverseStack(self):              
        return

    def printStack(self):
        if (self.isEmpty()):
            print("Empty")
        else:
            for i in range(self.max_stack_size):
                if self.stack[i]!=None:
                    print(self.stack[i],end=" ")
            #print(self.stack)
        return

# Driver code.---------------------------------------------

def teststack():
    testcases=int(input())
    stacksize=int(input())
    st1 = MyStack(stacksize)
    inputs=int(input())
    while inputs>0:
        command=input()
        operation=command.split()
        if(operation[0]=="S"):
            print(st1.size())
        elif(operation[0]=="I"):
            print(st1.isEmpty())
        elif(operation[0]=="P"):
            st1.push(int(operation[1]))
        elif(operation[0]=="O"):
            print(st1.pop())
            st1.printStack()
        elif(operation[0]=="T"):
            print(st1.top())
        elif(operation[0]=="D"):
            st1.delMid()
        elif(operation[0]=="R"):
            st1.reverseStack()
        inputs-=1

def main():
    teststack()

if __name__ == '__main__':
    main()
