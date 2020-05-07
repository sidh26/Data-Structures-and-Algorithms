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
            print("Stack is empty")
            return
        self.end -= 1
        return self.arr[self.end]
    
    def resize(self, n):
        temp = np.array([0] * n, dtype="<U10")
        for i in range(self.end):
            temp[i] = self.arr[i]
        del self.arr
        self.arr = temp
        self.capacity = n


def do_op(a, b, opr):
    switcher = {
        '+': b + a,
        '-': b - a,
        '*': b * a,
        '/': b / a,
        '^': b ^ a,
    }
    return switcher[opr]


exp = input("Enter the Expression: ")
exp = list(exp.split(" "))
op = Stack()
val = Stack()
for i in exp:
    if i.isdigit():
        val.push(int(i))
    elif i == "(":
        pass
    elif i == ")":
        res = do_op(int(val.pop()), int(val.pop()), op.pop())
        val.push(str(res))
    else:
        op.push(i)

print(val.pop())
