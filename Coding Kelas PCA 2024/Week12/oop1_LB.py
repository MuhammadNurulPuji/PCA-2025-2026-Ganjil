import math

class Point:
    def __init__(self, a, b):
        self.x = a
        self.y = b

    def norm(self):
        return math.sqrt(self.x**2 + self.y**2)
    
    def sum(self):
        return self.x + self.y
    
    def __eq__(self, other):   
        return self.x == other.x and self.y == other.y
        # return "hello"
        # pass
    
P = Point(3, 4)
print(P.norm()) # 5.0
print(P.sum()) # 7


P1= Point(2,3)
P2= Point(2,3)

print(P1 == P2) # True

