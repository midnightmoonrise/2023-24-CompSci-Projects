# swap the values of two integer variables x and y without the use of a third holding variable.
x = int(input("Enter first integer x: "))
y = int(input("Enter second integer y: "))
x,y = y,x
print(f"x = {x}, y = {y}")
