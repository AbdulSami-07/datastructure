class linkedListNode:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        #head node's data stores number of nodes.
        self.head = linkedListNode(0)
        self.rear = linkedListNode(None)

    def append(self,data):
        newNode = linkedListNode(data)
        if newNode:
            if self.head.data == 0:
                self.head.next = newNode
                self.rear = newNode
            else:
                self.rear.next = newNode
            self.rear = newNode
            #no. of nodes incremented by 1.
            self.head.data += 1
            print(newNode.data,self.head.data,sep = '\t')

    def insert(self, index, data):
        if (self.head.data >= index):
            curNode = self.head
            for pos in range(index + 1):
                if pos == index:
                    auxilNode = curNode.next
                    newNode = linkedListNode(data)
                    curNode.next = newNode
                    newNode.next = auxilNode
                    #print("Inserted {}".format(value))
                    return
                else:
                    curNode = curNode.next
        #print("No such index")

    def length(self):
        return self.head.data

    def delete(self, data):
        curNode = self.head
        while curNode.next != None:
            if curNode.next.data == data:
                auxilNode = curNode.next.next
                curNode.next = None
                curNode.next = auxilNode
                #print("Deleted %d" % value)
                return

            else:
                curNode = curNode.next
