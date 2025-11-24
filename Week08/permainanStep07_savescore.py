#membuat fungsi untuk mengecek apakah user menang atau draw atau kalah
def aduJagoan(user, komputer):
    global scoreUser
    global scoreKomputer

    if(user == komputer):
        hasil="DRAW"
    elif((user==1 and komputer==2) or (user==2 and komputer==3) or (user==3 and komputer==1)):
        hasil="MENANG"
        scoreUser+=1
    else:
        hasil="KALAH"
        scoreKomputer+=1
    return hasil

#membuat fungsi untuk mengkonversi pilihan
def Konversi(angkapilihan):
    if(angkapilihan == 1):
        hasil = "Batu"
    elif(angkapilihan == 2):
        hasil = "Gunting"
    else:
        hasil = "Kertas"
    return hasil

import random

try:
    file = open("score.txt")
    scoreUser = int(file.readline().strip())
    scoreKomputer = int(file.readline().strip())
    file.close()
except:
    scoreUser=0
    scoreKomputer=0

i=0
while(1):
    i=i+1
    print()
    print("Kesempatan ke-", i, sep="")
    print("Batu - Gunting - Kertas")
    print("=======================")
    print("Pilih Jagoan Kamu (dengan memasukkan angka): \n 1. Batu \n 2. Gunting \n 3. Kertas")
    jagoanUser = input("Masukkan pilihan Anda ")
    jagoanKomputer = random.randint(1,3)

    if(int(jagoanUser)>3 or jagoanUser==""):
        print("Pilihan Anda salah!!")
        break
    else:
        print()
        print("*************************************************")
        print("Pilihan Anda:", Konversi(int(jagoanUser)))
        print("Pilihan Komputer:", Konversi(jagoanKomputer))
        print("*************************************************")
        print("Hasilnya adalah: ", aduJagoan(int(jagoanUser), jagoanKomputer))
        print("Score User vs Komputer = ",scoreUser," : ",scoreKomputer)
        print("*************************************************")

file = open("score.txt",'w')
file.write('%d\n%d\nMuhammad Nurul Puji - D6218' % (scoreUser,scoreKomputer))