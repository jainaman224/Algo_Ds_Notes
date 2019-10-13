class Animal(object):            
    def __init__(self, name, age):    
        self.name = name 
        self.age = age 
    def display(self): 
        print(self.name) 
        print(self.age) 
class Dog(Animal):            
    def __init__(self, name, age, breed): 
        self.breed = breed  
        Animal.__init__(self, name, age)  
a = Animal("Bruno", 8)
a.display()
