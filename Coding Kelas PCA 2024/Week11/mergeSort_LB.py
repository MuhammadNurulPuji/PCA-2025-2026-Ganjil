def merge_sort(data):
    if len(data)<=1:
        return data
    
    mid = len(data)//2
    left = data[:mid]
    right = data[mid:]

    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left,right))

def merge(dataLeft,dataRight):
    result = []

    while len(dataLeft)>0 and len(dataRight)>0:
        if dataLeft[0]<dataRight[0]:
            result.append(dataLeft[0])
            dataLeft.remove(dataLeft[0])
        else:
            result.append(dataRight[0])
            dataRight.remove(dataRight[0])
    
    if len(dataLeft)==0:
        result += dataRight
    else:
        result += dataLeft
    return result

datalist = [17, 20, 9, 13, 5, 11]
print(merge_sort(datalist))