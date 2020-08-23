class QueueNode():
    def __init__(self,data):
        self.data = data
        self.next = None

class Queue():
    def __init__(self):
        self.count = 0
        self.front = QueueNode(None)
        self.rear = QueueNode(None)

    def enqueue(self,data):
        newNode = QueueNode(data)
        if newNode != None:

            if(self.front.data == None):
                #if front.data is empty then newNode becomes front node
                self.front = newNode
            else:
                #rear node points to newNode
                self.rear.next = newNode
            #rear node becomes newNode
            self.rear = newNode
            self.count += 1
            return True
        else:
            return False

    def dequeue(self):
        if(self.front.data == None):
            return False
        dataOut = self.front.data
        self.front = self.front.next
        self.count -= 1
        return dataOut

    def isempty(self):
        if self.front.data == None:
            return True
        else:
            return False

    def peek(self):
        if self.isempty().__eq__(True):
            print("No item")
        else:
            print(self.front.data)

    def __del__(self):
        del self

    def count(self):
        return self.count




