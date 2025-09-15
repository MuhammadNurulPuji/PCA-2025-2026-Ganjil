def bubleSort1(input):
    total_iterasi = 0
    for step in range (len(input)-1,0,-1):
        for sub_step in range(step):
            total_iterasi += 1
            if input[sub_step]>input[sub_step+1]:
                #swap
                temp = input[sub_step]
                input[sub_step] = input[sub_step+1]
                input[sub_step+1] = temp
    print("Total iterasi:",total_iterasi)


# data = [5,3,8,6,7,2]
data = [2, 3, 5, 6, 7, 8]
bubleSort1(data)
print(data)