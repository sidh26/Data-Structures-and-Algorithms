import numpy as np


class Stack:
    def __init__(self):
        self.arr = np.array([0] * 2, dtype="<U10")
        self.end = 0
        self.capacity = 2
    
    def push(self, a):
        self.arr[self.end] = a
        self.end += 1
        if self.end == self.capacity:
            self.resize(self.capacity * 2)
            print("resize")
    
    def pop(self):
        if self.end == 0:
            print("queue is empty")
            return
        print(self.arr[self.end - 1])
        self.end -= 1
    
    def resize(self, n):
        temp = np.array([0] * n, dtype="<U10")
        for i in range(self.end):
            temp[i] = self.arr[i]
        del self.arr
        self.arr = temp
        self.capacity = n


s = Stack()
x = "a"
while x.lower() != "end code":
    x = input()
    if x == "-":
        s.pop()
    else:
        s.push(x)
