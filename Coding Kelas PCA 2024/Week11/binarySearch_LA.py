def binarySearch(data, bataskiri, bataskanan, ygdicari):
    if bataskanan >= bataskiri:
        mid = bataskiri + (bataskanan - bataskiri) // 2
        if data[mid] == ygdicari:
            return mid
        elif data[mid] > ygdicari:
            return binarySearch(data, bataskiri, mid-1, ygdicari)
        else:
            return binarySearch(data, mid + 1, bataskanan, ygdicari)
    else:
        return -1
    
data = [2, 3, 5, 6, 7, 8]
ygdicari = 8
result = binarySearch(data, 0, len(data)-1, ygdicari)
print("Data yang dicari:",ygdicari)
print("Data yang dicari berada pada index ke:",result)