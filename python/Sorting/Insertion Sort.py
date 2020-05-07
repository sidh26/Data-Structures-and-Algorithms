from random import shuffle
import time


def insertionSort(arr):
    for i in range(1, len(arr)):
        
        key = arr[i]
        
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


# Driver code to test above #200000
arr = list(range(200))
shuffle(arr)
st = time.clock()
insertionSort(arr)
print(time.clock() - st)
