"""
class lcrsNode:
    #lcrs meanslcrsNode.
    def __init__(self,data):
        self.data = data
        self.leftChilde = None
        self.rightSibling = None
        
class LCRStree:
    def __init__(self):
        self.root =lcrsNode(None)
        #indexing root node as 1.
        self.height = 1
        self.numOfNode = 1
        #level of root node is 0.
        self.maxlevel = 0
        
    def append(self,data):
        if self.maxlevel == 0:
            self.root.data = data
            return
        else:
            newNode =lcrsNode(data)
            if newNode:
                curNode = self.root
                while curNode.
"""

class childList():
    self.nextChild = No



class treeNode:
    def __init__(self,data):
        self.data = data
        self.child = childList()

        
        