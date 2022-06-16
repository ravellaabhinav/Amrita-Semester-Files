class BinHeap():
    def _init_(self):
        self.heapList = [0]
        self.currentSize = 0

    """ This method defines the upheap function when inserting an element
    """
    def upHeapp(self,i):
        #@start-editable@

        while i // 2 > 0:                    
            if self.heapList[i] < self.heapList[i // 2]: 
                self.heapList[i],self.heapList[i // 2] = self.heapList[i // 2],self.heapList[i]
            i= i // 2
			
			
	    #@end-editable@
            
    def insert(self,k):
        #@start-editable@

        self.heapList.append(k)
        self.currentSize+=1
        self.upHeapp(self.currentSize)	
			
	    #@end-editable@

    """ This method defines the downheap function when removing min
    """
    def downHeap(self,i):
        #@start-editable@

        while(i*2)<=self.currentSize:
            x=self.minChild(i)
            if self.heapList[i]>self.heapList[x]:
                self.heapList[i],self.heapList[x] = self.heapList[x],self.heapList[i]
            i=x	
			
	    #@end-editable@

    def minChild(self,i):
        #@start-editable@

        if(i*2)+1>self.currentSize:
            return i*2
        else:
            if self.heapList[i*2]<self.heapList[(i*2)+1]:
                return i*2
            else:
                return (i*2)+1	
			
	    #@end-editable@

    def delMin(self):
        #@start-editable@

        if len(self.heapList)==1:
            return
        r = self.heapList[1]
        self.heapList[1] = self.heapList[self.currentSize]
        *self.heapList, _= self.heapList
        self.currentSize-=1
        self.downHeap(1)
        return r	
			
	    #@end-editable@
    
    def combineking(self):
        #@start-editable@

        if self.currentSize == 1:
            return
        x = 0
        while self.currentSize > 1:
            if x == 1:
                print(self.heapList)
            x = 1
        
            first = self.delMin()
            print(self.heapList)
        
            second = self.delMin()
            print(self.heapList)
        
            print(str(first)+" "+str(second)+" are combined to give "+str(first+second))
            self.insert(first+second)
        print(self.heapList)	
			
	    #@end-editable@
        
    
    def buildHeap(self,alist):
        i = len(alist) // 2
        self.currentSize = len(alist)
        self.heapList = [0] + alist[:]
        while (i > 0):  #// \label{lst:bh:loop}
            self.downHeap(i)
            i = i - 1


    #create a method to print the contents of the heap in level order 
    def printHeap(self):
        print(self.heapList)

def main():
    heap = BinHeap()
    arraySize = int(input())
    arr = list(map(int, input().split()))
    heap.buildHeap(arr)
    heap.printHeap()
    heap.combineking()

if _name_ == '_main_':
    main()