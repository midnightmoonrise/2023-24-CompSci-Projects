# Given a user-entered list of numbers, return the second greatest one.
x = []
while True:
    z = input("Enter an integer, enter nothing to quit: ")
    if z == "":
        break
    x.append(int(z))
print(sorted(x)[-2])
