class StackNode:
    def __init__(self,data):
        self.data = data
        self.next = None

class Stack():
    def __init__(self):
        #head index is 0.
        # data of self.head stores no. of Node
        self.head = StackNode(0)

    def push(self,data):
        newNode = StackNode(data)
        if newNode: #never use newNode == True as newNode doesn't anything so can't be compared.
            # making newNode to point to head's next node
            newNode.next = self.head.next
            #making head to point to newNode
            self.head.next = newNode
            # incrementing the no. of node by 1.
            self.head.data += 1
            #print(self.head.next.data, self.head.data, sep = '\t')
            return True
        else:
            return False

    def pop(self):
        if self.head.data == 0:
            return False
        else:
            #dataOut stores the data of 1st Node.
            firstNode = self.head.next
            dataOut = firstNode.data
            #joining the head node with 2nd Node.
            self.head.next = firstNode.next
            #deleting firstNode node
            del firstNode
            #decrementing no. of Node by 1.
            self.head.data-=1
            #print(dataOut,self.head.data, sep = '\t',end='\n')
            return dataOut

    def isempty(self):
        if self.head.data == 0:
            print("Empty stack")
            return True
        else:
            return False

    def peek(self):
        if self.head.data != 0:
            print("{}".format(self.head.next.data))
        else:
            print("None")


    def __del__(self):
        del self
        return None











