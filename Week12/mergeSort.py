def merge(arrayKiri, arrayKanan):
    hasil=[]

    while len(arrayKiri) != 0 and len(arrayKanan) != 0:
        if arrayKiri[0] < arrayKanan[0]:
            hasil.append(arrayKiri[0])
            arrayKiri.remove(arrayKiri[0])
        else:
            hasil.append(arrayKanan[0])
            arrayKanan.remove(arrayKanan[0])
    
    if len(arrayKiri) == 0:
        hasil += arrayKanan # Use += to extend the list, not append (which creates nested lists)
    else:
        hasil += arrayKiri

    return hasil

def mergeSort_gab(array):
    if len(array) == 1:
        return array
    
    mid = len(array) // 2
    arrayKiri = array[:mid]
    arrayKanan = array[mid:]
    
    arrayKiri = mergeSort_gab(arrayKiri)
    arrayKanan = mergeSort_gab(arrayKanan)
    
    return merge(arrayKiri, arrayKanan)


array = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
print("Array sebelum sorting:", array)
array = mergeSort_gab(array)
print("Array setelah sorting:", array)  