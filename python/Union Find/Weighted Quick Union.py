import numpy as np

size = 0
id = np.array([])
branch = np.array([])


def constr(N):
    global size
    size = N
    global id
    id = np.array([0] * N)
    global branch
    branch = np.array([0] * N)
    for i in range(N):
        id[i] = i
        branch[i] = 1
    print(id, branch)


def root(id, p):
    while p != id[p]:
        p = id[p]
    return p


def connected(id, p, q):
    return root(id, p) == root(id, q)


def union(id, p, q):
    if not connected(id, p, q):
        if branch[root(id, p)] < branch[root(id, q)]:
            id[root(id, p)] = id[root(id, q)]
            branch[root(id, q)] += branch[root(id, p)]
        else:
            id[root(id, q)] = id[root(id, p)]
            branch[root(id, p)] += branch[root(id, q)]


constr(10)
union(id, 1, 2)
union(id, 3, 4)
union(id, 9, 5)
union(id, 3, 9)
print("2 and 3")
print(connected(id, 2, 3))
print("3 and 5")
print(connected(id, 3, 5))
