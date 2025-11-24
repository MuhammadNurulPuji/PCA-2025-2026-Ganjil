# print("hello world")

# nama = input("Masukkan nama: ")
# print("Halo", nama)

# x=5
# y=5%2
# print(x)
# print(y)
# print(divmod(x,2))


# x=5
# y=2

# c,z=divmod(x,y)
# print(c)
# print(z)

# print(pow(2,3))


# print(1<<2)

# x="""dkslfakfjdsa dfjskafjdks
# kdfaljfdkla"""
# print(x)

# x=[3, 4.5, "ello"]
# print(x)
# x.append(5)
# print(x)

# y=[1,2,3]
# x.extend(y)
# print(x)

# x=(1,2,3)
# y=((4,5,6), [7,8,9])
# print(y[1][1])
# y[1][1]=4

# print(y)

# y[0][0]=6

# x="hello"
# y=x.upper()
# print(y)
# print(x)

# x=[1,2,3]
# y=[4,5,6]
# z=x+y
# print(z)

# x="Muhammad Nurul Puji"
# # print(x[2:9:2])
# print(x[::-1])

# print(~4)

# x=7
# y=x

# # print(x)
# # print(y)

# y=88

# print(x)
# print(y)

# x=[1,2,3]
# y=x

# # print(x)
# # print(y)

# y[0]=99

# print(x)
# print(y)

# x=[1,2,3]
# y=x.copy()

# # print(x)
# # print(y)

# y[0]=99

# print(x)
# print(y)


# data = input("Masukkan data: ")
# if data.isnumeric():
#     print("Data adalah angka")
#     print("tes")
# else:
#     print("Data bukan angka")

# for i in range(5):
#     print(i)    

# data = [3, 5, 55, 6, 7]
# # data = "tes"

# for (index, x) in enumerate (data):
#     print(index, x)

# data=[]

# for i in range(5):
#     data.append(i**2)  

# print(data)

# data=[i**2 for i in range(5)]
# print(data)


# def tambah(a,b):
#     c=a+b

# x=tambah(3,4)
# print(x)

# def tambahkurang(a,b):
#     c=a+b
#     d=a-b
#     return (c,d)

# ret=tambahkurang(3,4)
# print(ret)


# def fungsikuadrat(x, a=1, b=3, c=7):
#     return a*x**2+b*x+c

# z=fungsikuadrat(a=8,x=0,c=1, b=2)
# print(z)


# import random   
# random.seed(8)
# print(random.random())
# print(random.randint(1,10))

# data = ["tim1", "tim2", "tim3"]
# print(random.choice(data))
# random.shuffle(data)
# print(data)

# x=5
# y=3

# def fungsikuadrat(x):
#     global y
#     y=2
#     print (x**y)

# fungsikuadrat(x)
# print(y)


def outer():
    x="local"
    
    def inner():
        # nonlocal x
        x="nonlocal"
        print("inner:", x)
    
    inner()
    print("outer:", x)

outer()