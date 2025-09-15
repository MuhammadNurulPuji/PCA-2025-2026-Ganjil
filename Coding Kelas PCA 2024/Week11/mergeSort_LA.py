def merge_sort(unsorted_data):
    if len(unsorted_data) <= 1:
        return unsorted_data
    middle = len(unsorted_data) // 2
    left_list = unsorted_data[:middle]
    right_list = unsorted_data[middle:]
    left_list = merge_sort(left_list)
    right_list = merge_sort(right_list)
    return list(merge(left_list, right_list))

def merge(data_kiri, data_kanan):
    res = []
    while len(data_kiri)!=0 and len(data_kanan)!=0:
        if data_kiri[0] < data_kanan[0]:
            res.append(data_kiri[0])
            data_kiri.remove(data_kiri[0])
        else:
            res.append(data_kanan[0])
            data_kanan.remove(data_kanan[0])          
    if len(data_kiri) == 0:
        res += data_kanan
    else:
        res+= data_kiri
    return res

data=[5,3,8,6,7,2]
print("Data yang akan diurutkan:",data)
print("Data yang sudah diurutkan:",merge_sort(data))