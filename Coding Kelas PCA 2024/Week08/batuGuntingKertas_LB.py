def konversi(jagoanUser):
    if jagoanUser == 1:
        return "Batu"
    elif jagoanUser == 2:
        return "Gunting"
    elif jagoanUser == 3:
        return "Kertas"

def aduJagoan(user,komputer):
    if user == komputer:
        return "draw"
    elif user == 1 and komputer == 2:
        return "Menang"
    elif user == 2 and komputer == 3:
        return "Menang"
    elif user == 3 and komputer == 1:
        return "Menang"
    else:
        return "Kalah"


import random

while True:
    print("Permainan Batu Gunting Kertas")
    print("Pilih Jagoan Kamu (masukkan angka): ")
    print("1. Batu")
    print("2. Gunting")
    print("3. Kertas")

    print("---------------------------")

    jagoanUser=int(input("Masukkan pilihan (angka): "))

    if jagoanUser == 1:
        print("Jagoan Pilihan Anda: ", konversi(jagoanUser))
    elif jagoanUser == 2:
        print("Jagoan Pilihan Anda: ", konversi(jagoanUser))
    elif jagoanUser == 3:
        print("Jagoan Pilihan Anda: ", konversi(jagoanUser))
    else:
        print("Pilihanmu salah...")

    jagoanKomputer=random.randint(1,3)
    print("Jagoan Komputer: ", konversi(jagoanKomputer))

    print("Anda: ", aduJagoan(jagoanUser, jagoanKomputer))

    print("---------------------------")