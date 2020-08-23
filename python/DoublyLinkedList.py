class Node():

    def __init__(self,data):

        self.data = data
        self.prev = None
        self.next = None

#Doubly Linked List
class DLL():

    def __init__(self):

        self.head = Node(None)

    def __length(self):

        NumOfelem = 0

        curNode = self.head

        while curNode.next != None:
            NumOfelem += 1
            curNode = curNode.next

        return NumOfelem

    def append(self,data):

        curNode = self.head

        while curNode.next != None:
            curNode = curNode.next
        newNode = Node(data)
        curNode.next = newNode
        newNode.prev = curNode

    def insert(self,index,data):

        #insering at the end of list
        if index == 0:
            newNode = Node(data)
            if self.head.next :
                auxilNode = self.head.next
                self.head.next = newNode
                newNode.prev = self.head.next
                newNode.next = auxilNode
                auxilNode.prev = newNode

            else:
                self.head.next = newNode
                newNode.prev = self.head

        else:

            curPos = -1
            while curPos != index and self.head.next != None:
                self.head = self.head.next
                curPos += 1

            #inserting in the middle.
            if(curPos == index):
                newNode = Node(data)
                auxilNode = self.head.prev
                newNode.next = self.head
                self.head.prev = newNode
                newNode.prev = auxilNode
                auxilNode.next = newNode
                return

            #inserting in the end
            elif (self.head.next == None):
                newNode = Node(data)
                self.head.next = newNode
                newNode.prev = self.head

    def delete(self,index):
        #deleting at begining
        curPos = -1
        curNode = self.head
        while curPos != index and curNode.next != None:
            curPos += 1
            curNode = curNode.next

        if(curPos == 0):
            auxilNode = curNode.next
            self.head.next = auxilNode
            auxilNode.prev = self.head
            curNode.next = None
            curNode.prev = None

        elif (curPos == index) and (curNode.next == None):
            auxilNode = curNode.prev
            curNode.prev = None
            auxilNode.next = None

        elif (curPos == index) and (curNode.next != None):
            auxilNode = curNode.prev
            auxilNode.next = curNode.next
            curNode.next.prev = auxilNode
            curNode.next = None
            curNode.prev = None


















       # if index.__lt__( (self.__length())-1 ):
















