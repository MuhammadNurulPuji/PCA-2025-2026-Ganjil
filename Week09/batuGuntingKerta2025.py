def pilihanUser(x):
    if x==1:
        return "Batu"
    elif x==2:
        return "Gunting"
    elif x==3:
        return "kertas"
    else:
        return "Pilihanmu salah"
    
def randomPilihanKomputer():
    return random.choices([1,2,3])

def aduJagoan(pilihanUser, pilihanKomputer):
    if pilihanUser == pilihanKomputer:
        return "Seri"
    elif (pilihanUser == 1 and pilihanKomputer == 2) or (pilihanUser == 2 and pilihanKomputer == 3) or (pilihanUser == 3 and pilihanKomputer == 1):
        return "User"
    else:
        return "Komputer"


def scoreBoard(winner):
    global scoreUser, scoreKomputer
    if winner == "User":
        scoreUser += 1
    elif winner == "Komputer":
        scoreKomputer += 1
    print("Score User: ", scoreUser, " | ", end="")
    print("Score Komputer: ", scoreKomputer)

import random

scoreUser = 0
scoreKomputer = 0
while True:
    print("Permainan Batu Gunting Kertas")
    print("Pilih Jagoan Kamu (masukkan angka):")
    print("1. Batu")
    print("2. Gunting")
    print("3. Kertas")
    jagoanUser = int(input("Masukkan pilihan: "))
    print("Jagoan Pilihan Anda: " + pilihanUser(jagoanUser))
    jagoanKomputer = randomPilihanKomputer()
    print("Jagoan Pilihan Komputer: " + pilihanUser(jagoanKomputer[0]))

    pemenang = aduJagoan(jagoanUser, jagoanKomputer[0])
    print("----------------------------")
    print("Pemenang: " + pemenang)
    scoreBoard(pemenang)
    print("****************************")
    print()