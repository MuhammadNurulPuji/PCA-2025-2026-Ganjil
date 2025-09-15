import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def akarKuadrat(self):
        return math.sqrt(self.x**2 + self.y**2)
    
    def jumlah(self):
        return self.x + self.y
    
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

object1 = Point(3, 4)
print("Nilai akar kuadrat: ", object1.akarKuadrat())
print("Nilai totalnya adalah: ", object1.jumlah())

object2 = Point(3, 4)
print(object1 == object2)

print(object1.__eq__(object2))
