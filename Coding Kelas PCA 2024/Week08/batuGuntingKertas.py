import random

def konversi(jagoanUser):
    if jagoanUser == 1:
        return "Batu"
    elif jagoanUser == 2:
        return "Gunting"
    elif jagoanUser == 3:
        return "Kertas"


def aduJagoan(jagoanUser, jagoanKomputer):
    if jagoanUser == jagoanKomputer:
        return "draw"
    elif jagoanUser == 1 and jagoanKomputer == 2:
        return "menang"
    elif jagoanUser == 2 and jagoanKomputer == 3:
        return "menang"
    elif jagoanUser == 3 and jagoanKomputer == 1:
        return "menang"
    else:
        return "kalah"


while True:
    print("Pilih Jagoan Kamu (masukkan angka):")
    print("1. Batu")
    print("2. Gunting")
    print("3. Kertas")

    jagoanUser = int(input("Pilihan kamu: "))

    if jagoanUser == 1:
        print("Jagoan pilihan Anda: ", konversi(jagoanUser))
    elif jagoanUser == 2:
        print("Jagoan pilihan Anda: ", konversi(jagoanUser))
    elif jagoanUser == 3:
        print("Jagoan pilihan Anda: ", konversi(jagoanUser))
    else:
        print("Pilihanmu salah..")

    jagoanKomputer = random.randint(1,3)
    print("Jagoan Komputer: ", konversi(jagoanKomputer))

    print("*******")
    print("Hasilnya Anda: ", aduJagoan(jagoanUser, jagoanKomputer))
    print("*******")