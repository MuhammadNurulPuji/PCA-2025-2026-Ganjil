print("Factorial Calculator")
x = input("Enter a number: ")
x = int(x)

#recursive
def factorial_recursive(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial_recursive(n-1)
    
#non recursive
def factorial_nonRecursive(n):
    fact = 1
    for i in range(2,n+1):
        fact = fact * i
    return fact

print("Factorial of",x,"using recursive method is",factorial_recursive(x))
print("Factorial of",x,"using non-recursive method is",factorial_nonRecursive(x))