# rekursif
def faktorial(n):
    if n == 2:
        return 2
    else:
        return n * faktorial(n - 1)

print("metode rekursif")
print(faktorial(5))  # Output: 120

# iteratif
def faktorial_iteratif(n):
    hasil = 1
    for i in range(n, 1, -1):
        hasil *= i
    
    return hasil

print("metode iteratif")
print(faktorial_iteratif(5))  # Output: 120
