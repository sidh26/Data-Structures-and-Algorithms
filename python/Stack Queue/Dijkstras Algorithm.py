import numpy as np


def val_push(a):
    global val_end
    val[val_end] = a
    val_end += 1
    if val_end == val_capacity:
        val_resize(val_capacity * 2)


def val_pop():
    global val_end
    if val_end <= 0:
        print("queue is empty, equation is incorrected inputted")
        return
    temp = val[val_end - 1]
    val_end -= 1
    return temp


def op_push(a):
    global op_end
    op[op_end] = a
    op_end += 1
    if op_end == op_capacity:
        op_resize(op_capacity * 2)


def op_pop():
    global op_end
    if op_end <= 0:
        print("queue is empty, equation is incorrected inputted")
        return
    temp = op[op_end - 1]
    op_end -= 1
    return temp


def val_resize(n):
    global val
    global val_end
    global capacity
    temp = np.array([0] * n, dtype=int)
    for i in range(val_end):
        temp[i] = val[i]
    del val
    val = temp
    capacity = n


def op_resize(n):
    global op
    global op_end
    global op_capacity
    temp = np.array([0] * n, dtype="<U10")
    for i in range(op_end):
        temp[i] = op[i]
    del op
    op = temp
    op_capacity = n


def do_operation(a, b, op):
    switcher = {
        '+': b + a,
        '-': b - a,
        '*': b * a,
        '/': b / a,
        '^': b ^ a,
    }
    
    # get() method of dictionary data type returns
    # value of passed argument if it is present
    # in dictionary otherwise second argument will
    # be assigned as default value of passed argument
    return switcher.get(op)


val = np.array([0] * 2, dtype=int)
op = np.array([0] * 2, dtype="<U10")
val_end = 0
op_end = 0
val_capacity = 2
op_capacity = 2

exp = input("Enter the Expression: ")
i = 0

while i < len(exp):
    c = 0
    if exp[i].isdigit():
        c = c * 10 + (ord(exp[i]) - 48)
        j = i + 1
        while exp[j].isdigit():
            c = c * 10 + (ord(exp[j]) - 48)
            j += 1
        val_push(c)
        i = j
    
    else:
        if exp[i] != '(' and exp[i] != ')':
            op_push(exp[i])
        if exp[i] == ')':
            a = val_pop()
            b = val_pop()
            oper = op_pop()
            val_push(do_operation(a, b, oper))
        i += 1
print("Result = " + str(val_pop()))
