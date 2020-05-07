from random import shuffle
import time


def partition(arr, lo, hi):
    high = hi
    low = lo + 1
    lo += 1
    p = lo - 1
    while True:
        try:
            while arr[p] > arr[lo] and lo != high + 1:
                lo += 1
        # if lo == high:
        #     return high
        except IndexError:
            pass
        while arr[p] < arr[hi] and hi != low - 1:
            hi -= 1
        # if hi == low:
        # return 0
        
        if not (lo < hi):
            arr[lo - 1], arr[p] = arr[p], arr[lo - 1]
            return lo - 1
        
        arr[lo], arr[hi] = arr[hi], arr[lo]


def quicksort(arr, lo, hi):
    if lo < hi:
        pi = partition(arr, lo, hi)
        if pi == 0:
            quicksort(arr, pi + 1, hi)
        elif pi == hi:
            quicksort(arr, lo, pi - 1)
        else:
            quicksort(arr, lo, pi - 1)
            quicksort(arr, pi + 1, hi)


arr = list(range(1000000))
shuffle(arr)

# arr = [0, 9, 3, 1, 4, 5, 2, 8, 7, 6]#[9, 1, 3, 0, 4, 5, 2, 8, 7, 6][0, 1, 3, 9, 4, 5, 2, 8, 7, 6][8, 1, 3, 9, 4, 5, 2, 0, 7, 6]
p = 0
lo = p
hi = len(arr) - 1

st = time.clock()
quicksort(arr, lo, hi)
print(time.clock() - st)
if arr == list(range(200000)):
    print(True)
pass
