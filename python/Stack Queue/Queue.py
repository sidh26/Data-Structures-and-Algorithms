import numpy as np


class Queue:
    def __init__(self):
        self.arr = np.array([0] * 2, dtype=str)
        print("End to terminate the code\n")
        self.x = "abc"
        self.end = 0
        self.start = 0
        self.capacity = 2
    
    def enqueue(self, a):
        self.arr[self.end] = a
        self.end += 1
        if self.end == self.capacity - 1:
            self.resize(self.capacity * 2)
    
    def dequeue(self):
        print(self.arr[self.start])
        self.start += 1
        if self.end - self.start == self.capacity // 4:
            self.resize(self.capacity / 2)
    
    def resize(self, n):
        temp = np.array([0] * n, dtype=str)
        for i in range(self.start, self.end + 1):
            temp[i] = self.arr[i]
        del self.arr
        self.arr = temp


q = Queue()

while q.x.lower() != "end code":
    q.x = input()
    if q.x == "-":
        q.dequeue()
    else:
        q.enqueue(q.x)
