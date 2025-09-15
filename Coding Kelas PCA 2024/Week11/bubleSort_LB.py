def bubleSort(data):
    total_iterasi = 0
    # swapped = False
    for step in range (len(data)-1,0,-1):
        swapped=False
        for sub_step in range(step):
            total_iterasi+=1
            if data[sub_step]>data[sub_step+1]:
                swapped = True
                #swap
                temp = data[sub_step]
                data[sub_step] = data[sub_step+1]
                data[sub_step+1] = temp
        if not swapped:
            break
    print("Total iterasi:",total_iterasi)

# datalist = [17, 20, 9, 13, 5, 11]
datalist = [5, 9, 11, 13, 17, 20]
bubleSort(datalist)
print(datalist)