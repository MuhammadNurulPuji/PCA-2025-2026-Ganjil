def binarySearch(data, left, right, target):
    if right>=left:
        mid = left + (right-left)//2
        if data[mid]==target:
            return mid
        elif data[mid]>target:
            return binarySearch(data, left, mid-1, target)
        else:
            return binarySearch(data, mid+1, right, target)
    else:
        return -1
    
datalist = [5, 9, 11, 13, 17, 20]       #ini harus data yg sudah diurutkan
target = 17
result = binarySearch(datalist, 0, len(datalist)-1, target)
print("Data ditemukan pada index ke-",result)