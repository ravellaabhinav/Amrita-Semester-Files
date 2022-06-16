import math
class BinarySearchTree:
    """
    This defines the node class. The children can be individually declared or stored
    in a list. We are adding a pos value which stores the nodes position. root nodes pos value is 1
    """
    class node:
        def _init_(self):
            self.element = 0
            self.leftchild = None
            self.rightchild = None
            self.pos = -1
            self.parent = None
    """
        This initializes the binary search tree. ht is the height of the tree, sz is the
        number of nodes. You may define this appropriately.
    """
    def _init_(self):
        self.sz = 0
        self.root = None
        self.ht = 0

    """
        This method implements the functionality of finding an element in the tree. The function
        findElement(e) finds the node in the current tree, whose element is e. Depending on the
        value of e and in relation to the current element visited, the algorithm visits the left
        or the right child till the element is found, or an external node is visited. Your
        algorithm can be iterative or recursive

        Output: Returns the pointer to the node
    """
                 
    def findElement(self,e,curnode):
        #@start-editable@

        if curnode == None:
            return self.root
        if self.isExternal(curnode) or curnode.element == e:
            return curnode
        if e > curnode.element:
            return self.findElement(e, curnode.rightchild)
        if e < curnode.element:
            return self.findElement(e, curnode.leftchild)

        #@end-editable@
            
    """
        This method implements insertion of an element into the binary search tree. Using the
        findElement(e) method find the position to insert, and insert a node with element e,
        as left or right child accordingly. Make sure that you update the value of pos attribute.
        curnode.leftchild.pos = curnode.pos * 2
        curnode.rightchild.pos = curnode.pos * 2 + 1    
    """
    def insertElement(self,e):
    #@start-editable@

        if self.root == None:
            self.root = self.node()
            self.root.element = e
            self.root.pos = 1
            return
        else:
            newNode = self.node()
            newNode.element = e
    
            root = self.root
            temp = None
    
            while root != None:
                temp = root
                if e < root.element:
                    root = root.leftchild
                else:
                    root = root.rightchild
            
            if e < temp.element:
                newNode.parent = temp
                temp.leftchild = newNode
                temp.leftchild.pos = temp.pos*2
            else:
                newNode.parent = temp
                temp.rightchild = newNode
                temp.rightchild.pos = temp.pos*2 + 1

    #@end-editable@
    """
        This method inorderTraverse(self,v) performs an inorder traversal of the BST, starting
        from node v which is initially the root and prints the elements of the nodes as they
        are visited. Remember the inorder traversal first visits the left child, followed by
        the parent, followed by the right child. This could be used to print the tree.
    """
    def inorderTraverse(self,v):
    #@start-editable@

        if v == None:
            return None
        self.inorderTraverse(v.leftchild)
        print(v.element, end=' ')
        self.inorderTraverse(v.rightchild)

    #@end-editable@

    """
        Given a node v this will return the next element that should be visited after v in the
        inorder traversal. You can define this recursively
    """
    def returnNextInorder(self,v):
    #@start-editable@

        if v == None:
            return None
        if v.rightchild != None:
            while v.leftchild != None:
                v = v.leftchild
            return v
        if v.leftchild != None:
            return self.returnNextInorder(v.leftchild)
        else:
            return self.returnNextInorder(v.rightchild)

    #@end-editable@
    """
        This method deleteElement(self, e), removes the node with element e from the tree T.
        There are three cases:
            1. Deleting a leaf or external node:Just remove the node
            2. Deleting a node with one child: Remove the node and replace it with its child
            3. Deleting a node with two children: Instead of deleting the node replace with
                a) its inorder successor node or b)Inorder predecessor node
    """

    def deleteElement(self,e):
    #@start-editable@

        curnode = self.findElement(e,self.root)
        if (curnode.element != e):
            print ("No such element")
            return
        else:
            if self.isExternal(curnode):
                temp = curnode
                curnode.parent.leftchild = None
                curnode.parent.rightchild = None
                del temp
            elif curnode.leftchild != None and curnode.rightchild != None:
                inorder = self.returnNextInorder(curnode)
                curnode.element = inorder.element
                if inorder.parent.leftchild == inorder:
                    inorder.parent.leftchild = None
                    del inorder
                elif inorder.parent.rightchild == inorder:
                    inorder.parent.rightchild = None
                    del inorder
            else:
                if curnode.leftchild != None:
                    curnode.element = curnode.leftchild.element
                    temp = curnode.leftchild
                    del temp
                elif curnode.rightchild != None:
                    curnode.element = curnode.rightchild.element
                    temp = curnode.rightchild
                    del temp

    #@end-editable@
        
    """
        There are other support methods which maybe useful for implementing your functionalities.
        These include
            1. isExternal(self,v): which returns true if the node v is external
    """
    def isExternal(self,curnode):
        if (curnode.leftchild == None and curnode.rightchild == None):
            return True
        else:
            return False

    def getChildren(self, ele):
    #@start-editable@

        children = []
        curnode = self.findElement(ele,self.root)
        if curnode.leftchild != None and curnode.rightchild != None:
            children.extend([curnode.leftchild.element, curnode.rightchild.element])
        elif curnode.leftchild != None and curnode.rightchild == None:
            children.extend([curnode.leftchild.element, curnode.rightchild])
        elif curnode.leftchild == None and curnode.rightchild != None:
            children.extend([curnode.leftchild, curnode.rightchild.element])
        return children

    #@end-editable@
    
    def preorderTraverse(self,v):
    #@start-editable@

        if v == None:
            return None
        print(v.element, end=' ')
        self.preorderTraverse(v.leftchild)
        self.preorderTraverse(v.rightchild)

    #@end-editable@
        
    def postorderTraverse(self,v):
    #@start-editable@

        if v == None:
            return None
        self.postorderTraverse(v.leftchild)
        self.postorderTraverse(v.rightchild)
        print(v.element, end=' ')

    #@end-editable@

    def findDepthIter(self,v):
    #@start-editable@

        depth = 0
        temp = v
        while temp.parent != None:
            temp = temp.parent
            depth += 1
        return depth

	#@end-editable@
    
    def findDepth(self,ele):
        curnode = self.findElement(ele,self.root)
        if(curnode.element != ele):
            print("No such Element")
            return
        else:
            return self.findDepthIter(curnode)

    def findHeight(self,ele):
    #@start-editable@

        curnode = self.findElement(ele,self.root)
        if(curnode.element != ele):
            print("No such Element")
        else:
            q = []
            q.append(curnode)
            height = 0

            while True:
                count = len(q)
                if count == 0:
                    return height - 1
                height += 1

                while count > 0:
                    node = q[0]
                    q.pop(0)
                    if node.leftchild != None:
                        q.append(node.leftchild)
                    if node.rightchild != None:
                        q.append(node.rightchild)
                    count -= 1

	#@end-editable@
	
def main():
    tree = BinarySearchTree()
    #print("Array Size:")
    arraySize = int(input())
    #print("Array Elements:")
    arr = list(map(int, input().split()))
    for i in range(arraySize):
        tree.insertElement(arr[i])
    """tree.insertElement(50)
    tree.insertElement(20)
    tree.insertElement(70)
    tree.insertElement(1)
    tree.insertElement(10)
    tree.insertElement(90)
    tree.insertElement(15)
    tree.insertElement(30)
    tree.insertElement(60)
    tree.insertElement(61)
    tree.insertElement(62)
    tree.insertElement(65)
    tree.insertElement(8)
    tree.insertElement(100)"""
    inputs=int(input())
    while inputs>0:
        command=input()
        operation=command.split()
        if(operation[0]=="I"):
            tree.inorderTraverse(tree.root)
            print()
        elif(operation[0]=="P"):
            tree.preorderTraverse(tree.root)
            print()
        elif(operation[0]=="Post"):
            tree.postorderTraverse(tree.root)
            print()
        elif(operation[0]=="D"):
            tree.deleteElement(int(operation[1]))
        elif(operation[0]=="H"):
            print(tree.findHeight(int(operation[1])))
        elif(operation[0]=="Depth"):
            print(tree.findDepth(int(operation[1])))
        elif(operation[0]=='Find'):
            key = tree.findElement(int(operation[1]), tree.root)
            if(key.element == int(operation[1])):
                print("Element Found at", key.pos)
            else:
                print("Element not Found")
        elif(operation[0]=="GetC"):
            childs = tree.getChildren(int(operation[1]))
            print(childs)
        inputs-=1

if _name_ == '_main_':
    main()