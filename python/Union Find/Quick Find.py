import numpy as np


class Qf():
    
    def __init__(self, n):
        self.n = n
        self.id = np.array([0] * n)
        for i in range(n):
            self.id[i] = i
        print(self.id)
    
    def connected(self, p, q):
        return self.id[p] == self.id[q]
    
    def union(self, p, q):
        if not self.connected(p, q):
            temp = self.id[p]
            for i in range(self.n):
                if self.id[i] == temp:
                    self.id[i] = self.id[q]


a = Qf(10)
a.union(1, 2)
a.union(3, 4)
a.union(9, 5)
a.union(3, 9)
print("2 and 3")
print(a.connected(2, 3))
print("3 and 5")
print(a.connected(3, 5))
