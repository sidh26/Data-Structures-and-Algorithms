# Python program for implementation of Shell Sort
# Version A
def shellSort(arr):
    # Start with a big gap, then reduce the gap
    n = len(arr)
    gap = n / 2
    
    # Do a gapped insertion sort for this gap size.
    # The first gap elements a[0..gap-1] are already in gapped
    # order keep adding one more element until the entire array
    # is gap sorted
    while gap > 0:
        
        for i in range(gap, n):
            
            # add a[i] to the elements that have been gap sorted
            # save a[i] in temp and make a hole at position i
            temp = arr[i]
            
            # shift earlier gap-sorted elements up until the correct
            # location for a[i] is found
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            
            # put temp (the original a[i]) in its correct location
            arr[j] = temp
        gap /= 2


# Driver code to test above
arr = [12, 34, 54, 2, 3]

n = len(arr)
print("Array before sorting:")
for i in range(n):
    print(arr[i]),

shellSort(arr)

print("\nArray after sorting:")
for i in range(n):
    print(arr[i]),

# Version B

from random import shuffle
import time

alist = [i for i in range(8)]
shuffle(alist)
n = len(alist)


def gaps(size):
    # uses the gap sequence 2^k - 1: 1, 3, 7, 15, 31, ...
    length = size.bit_length()
    for k in range(length - 1, 0, -1):
        yield 2 ** k - 1


def shell_sort(alist):
    def insertion_sort_with_gap(gap):
        for i in range(gap, len(alist)):
            temp = alist[i]
            j = i - gap
            while j >= 0 and temp < alist[j]:
                alist[j + gap] = alist[j]
                j = j - gap
            alist[j + gap] = temp
    
    for g in gaps(len(alist)):
        insertion_sort_with_gap(g)


shell_sort(alist)
print('Sorted list: ', end='')
print(alist)
