# nama = input("Masukkan nama: ")
# print("Halo", nama)
# if nama == "Mario":
#     print("Mario Super")

# s='tes'
# print(s,end=' ')

# ss = "tes 2"
# print(ss)

# sss = """tes 3 hell9
# fsflsajfkdl
# world tes 4"""
# print(sss)

# print(str(1.0))

# s= [1, "tes", 3.0]
# print(s)
# s.append(4)
# print(s)
# s.insert(1, "tess")
# print(s)
# print(s[2])

# s[2] = "tes 3"
# print(s)

# s.pop()
# print(s)


# tuples= (1, "tes", 3.0)
# print(tuples)
# print(tuples[2])
# # tuples[2] = "tes 3"

# tuples.append(4)    

# tuple dan list
# tes = ([1,2,3], (4,5,6))
# print(tes)

# print(tes[0][1])
# tes[0][1] = 10
# print(tes)

# tes[1][1] = 50
# print(tes)


# tes = "hello apappun"
# print(tes)

# print(tes.upper())

# print(tes)


# print(tes+" tes")
# print(tes)  


# tes = "hello python"
# print(tes)
# print(tes[0:6:2])
# print(tes[::-1])


# print(tes[2::1])


# a= 4
# print(a)
# b=a
# print(b)
# b=5
# print(a)
# print(b)


# list_a= [1,2,3]
# list_b= list_a
# print(list_a)
# print(list_b)

# list_b[1]= 10

# print(list_a)
# print(list_b)

# list_c= [1,3,5]
# list_d= list_c[:]
# print(list_c)
# print(list_d)

# list_d[1]= 10

# print(list_c)
# print(list_d)


# a = input("Masukkan angka: ")

# if int(a) % 2 == 0:
#     print("genap")
# elif int(a) % 2 == 1:
#     print("ganjil")
# else: print("bukan angka")

# Data = ["apple", "banana", "cherry", "grape", "orange"]
# for x in Data:
#     print(x)

# for i, x in enumerate(Data):
#     print(i, x)

# for i in range(0,5):
#     print(Data[i])


# i=0
# while i < 5:
#     print(Data[i])
#     i+=1


# list comprehension
# data=[]
# for i in range(0,5):
#     data.append(i**2)
# print(data)

# data2= [i**2 for i in range(0,5)]
# print(data2)

# def jumlahkurang (a,b):
#     jumlah= a+b
#     kurang= a-b
#     return (jumlah, kurang)

# hasil= jumlahkurang(5,3)
# print(hasil)

# jumlah, kurang= jumlahkurang(5,3)
# print(jumlah)
# print(kurang)

#none function
# def printHello():
#     print("Hello")

# printHello()
# tes= printHello()
# print(tes)


# def linear (x,m=2.7,c=0.6):
#     y= m*x+c
#     return y

# y=linear(m=6,x=3)
# print(y)

# import random
# random.seed(10)
# print(random.random())
# print(random.random())
# print(random.randint(1,3))
# namakelompok=["anggur","jeruk","apel"]
# random.shuffle(namakelompok)
# print(random.choice(namakelompok))

# x = 6

# def tes():
#     global x
#     x=7+25
#     print(x)

# tes()
# print(x)


def inner():
    x= 10
    def sub_inner():
        nonlocal x
        x= 20
        print(x)
    sub_inner()
    print(x)

inner()