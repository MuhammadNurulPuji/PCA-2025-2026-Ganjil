def factorial_nonRecursif(n):
    res = 1
    while n > 1:
        res *= n
        n -= 1 
    return res

def factorial_recursive(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial_recursive(n-1)


print(factorial_nonRecursif(5)) # 120
print(factorial_recursive(5)) # 120