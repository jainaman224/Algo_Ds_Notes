class LinearRegression():
    """Initialize arr_x and arr_y"""
    def __init__(self , arr_x , arr_y , n):
        self.__arr_x = arr_x
        self.__arr_y = arr_y    
        self.__n = n
    """ calculate the intercept of line"""
    def intercept(self):
        xy = 0
        x = 0
        y = 0
        sqr_x = 0
        for i in range(n):
            xy = xy + self.__arr_y[i] * self.__arr_x[i]
            x = x + self.__arr_x[i]
            y = y + self.__arr_y[i]
            sqr_x = sqr_x + self.__arr_x[i] * self.__arr_x[i]
        
        a1 = (self.__n * xy - x*y) / (self.__n * sqr_x - x * x)
        return a1
    """calculate the the slope of line"""
    def slope(self):
        xy = 0
        x = 0
        y = 0
        sqr_x = 0
        for i in range(n):
            xy = xy + self.__arr_y[i] * self.__arr_x[i]
            x = x + self.__arr_x[i]
            y = y + self.__arr_y[i]
            sqr_x = sqr_x + self.__arr_x[i] * self.__arr_x[i]
        
        a0 = (y * sqr_x - x * xy) / (self.__n * sqr_x - x * x)
        return a0
    """return the value using line of equation: y = m * x + c"""
    def prediction(self , x):
        y = self.slope() + self.intercept() * x
        return y
    
if __name__ == "__main__":
    n = int(input("Enter size: "))
    arr_x = list(map(int , input("Enter x array: ").strip().split(',')))
    arr_y = list(map(float , input("Enter y array: ").strip().split(',')))
    
    if(n == len(arr_x) and n == len(arr_y)):
        ls = LinearRegression(arr_x , arr_y , n)
        print("Calculated intercept: ", ls.intercept())
        print("Calculated slope: ", ls.slope())
        
        while(True):
            flag = str(input("Do you want to predict values(y/n): "))
            if(flag == "n"):
                print("System Exit")
                break
            elif(flag == "y"):
                c = int(input("Enter value for prediction: "))
                print("Predicted value: ", ls.prediction(c))
            else:
                print("Invalid Option, Try Again")
    else:
        print("Invalid Input Format")
        
#Enter size: 7
#Enter x array: 1,2,3,4,5,6,7
#Enter y array: 0.5,2.5,2.0,4.0,3.5,6.0,5.5
#Calculated intercept:  0.8392857142857143
#Calculated slope:  0.07142857142857142
#Do you want to predict values(y/n): y
#Enter value for prediction: 4
#Predicted value:  3.428571428571429
#Do you want to predict values(y/n): n
