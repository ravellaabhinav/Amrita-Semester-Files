class node:
     def __init__(self,e=None,next=None):
          self.element = e
          self.next = next
          
class SLList:
     def __init__(self):
          self.head = None 
          self.sz = 0
          
          
     def insertLast(self,e):
         
         return

     def insertFirst(self,e):
          
          return

    
     
     def deleteFirst(self):
          
          return

     def deleteLast(self):
          
          return

          
     def printList(self):
          tnode = self.head
          while tnode!= None:
               print(tnode.element,end=" ")
               tnode = tnode.next
          print("")
          return
     
     def findNode(self, val):
          curnode = self.head
          while curnode!=None:
               if curnode.element == val:
                    return curnode
               curnode = curnode.next
          return None
     
     def isEmpty(self):
          return self.sz==0

     def size(self):
          return self.sz


     
def testSLL():
    sll = SLList()
    inputs=int(input())
    while inputs>0:
        command=input()
        operation=command.split()
        if(operation[0]=="S"):
            print(sll.size())
        elif(operation[0]=="I"):
            print(sll.isEmpty())
        elif(operation[0]=="IF"):
            sll.insertFirst(int(operation[1]))
            sll.printList()
        elif(operation[0]=="IL"):
            sll.insertLast(int(operation[1]))
            sll.printList()
        elif(operation[0]=="DF"):
            sll.deleteFirst()
            sll.printList()
        elif(operation[0]=="DL"):
            sll.deleteLast()
            sll.printList()
        elif(operation[0]=="RO"):
            sll.rotate(int(operation[1]))
            sll.printList()
        elif(operation[0] == "OSEM"): # 1 means odd , 0 means even
            print(sll.oddSumEvenMul(int(operation[1])))

           
        
        inputs-=1


def main():
    testSLL()

if __name__ == '__main__':
    main()
