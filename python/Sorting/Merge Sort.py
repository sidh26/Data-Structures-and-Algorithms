# merge array
from random import shuffle
import time


def createarr(size):
    a = [[i] for i in range(size)]
    shuffle(a)
    return a


def comblist(arr1, arr2):
    len_arr1 = len(arr1)
    len_arr2 = len(arr2)
    i = 0
    j = 0
    l = []
    while True:
        if arr1[i] < arr2[j]:
            l.append(arr1[i])
            i += 1
        
        else:
            # print(arr[j],end= " ")
            # print("low:{} high:{} {}".format(i, j+1, arr))
            l.append(arr2[j])
            j += 1
        
        if i == len_arr1:
            # print("As the second sub array is done printing the rest ")
            for x in arr2[j:]:
                l.append(x)
            break
        
        elif j == len_arr2:
            
            for x in arr1[i:]:
                l.append(x)
            break
        
        else:
            continue
    return l


def listdist(arr):
    x = []
    if len(arr) == 1:
        print(arr[0])
    else:
        for i in range(0, len(arr), 2):
            try:
                x.append(comblist(arr[i], arr[i + 1]))
            except IndexError:
                x.append(arr[i])
        
        listdist(x)


a = createarr(100)
print(a)
print()
st = time.clock()
listdist(a)
print(a)
print(time.clock() - st)
