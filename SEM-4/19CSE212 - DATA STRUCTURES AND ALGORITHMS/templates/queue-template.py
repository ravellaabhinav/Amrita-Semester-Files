"""The code has been developed by Dr.Vidhya Balasubramanian as part of the CSE230 Data Structures Course, ASE Coimbatore.
   The code is being constantly improved, so please bring to notice any bugs to dsdaa.amrita@gmail.com

Code Modifed by: Vamsee Krishna Kiran M 
Date: 30-June-2019.
    
"""

class MyQueue():
    
    def __init__(self,size):
        # this is the queue container called 'queue'
        self.queue = []
        # front and back indexes
 
        # define the 'max_queue_size' and initialize it
        
        #code here


        for i in range(0,self.max_queue_size):
            self.queue.append(None)
  

    # define the enqueue operation which inserts the value into the queue, must throw a queue full exception
    def enqueue(self, value):
        #code here
        self.printQueue()
        return
                
    # returns first elt of the queue if not empty, else throws queue empty
    # exception
    
    def dequeue(self):
        #code here
            return element #element is the the popped out item.
       
    
    # returns front element without removing it if the queue is not empty, else throws exception   
    def front(self):
        #code here also, handle queue empty condition
     
    # returns True if queue is empty
    def isEmpty(self):
        return #code here

    # returns the number of elements currently in queue
        
    def size(self):
        return #code here
    
    def printQueue(self):
        if (self.isEmpty()):
            print ("Queue Empty Exception")
        else:
            for i in range(self.max_queue_size):
                if self.queue[i]!=None:
                    print(self.queue[i],end=" ")
            print(" ")

def testqueue():
    queuesize=int(input())
    q1 = MyQueue(queuesize)
    inputs=int(input())
    while inputs>0:
        command=input()
        operation=command.split()
        if(operation[0]=="S"):
            print(q1.size())
        elif(operation[0]=="I"):
            print(q1.isEmpty())
        elif(operation[0]=="E"):
            q1.enqueue(int(operation[1]))
            q1.printQueue()
        elif(operation[0]=="D"):
            print(q1.dequeue())
        elif(operation[0]=="F"):
            print(q1.front())
        
        inputs-=1


def main():
    testqueue()

if __name__ == '__main__':
    main()
