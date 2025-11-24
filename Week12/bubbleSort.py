def bubblesort(array):
    global total_iter
    for i in range(len(array)-1,0,-1):
        cek = 0
        for j in range(i):
            total_iter += 1
            if array[j]>array[j+1]: #if inverted than swap
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
                cek = 1
        if cek == 0:
            break

total_iter = 0
# data = [64, 34, 25, 12, 22, 11, 90]
data = [1,2,3,4,5,6,7,8,9,10]

print("(Before) Unsorted array is:")
print(data)
print()

bubblesort(data)
print("(After) Sorted array is:")
print(data)
print("Total iteration:", total_iter)