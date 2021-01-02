#Find biggest numnber


try:
    firstNumber = int(input("Podaj pierwszą liczbę dodatnią: "))
except ValueError:
    print("Zła wartość!")
    exit()

if firstNumber <= 0:
    print("Ta liczba nie jest dodatnia")
    exit()

try:
    secondNumber = int(input("Podaj drugą liczbę dodatnią: "))
except ValueError:
    print("Zła wartość!")
    exit()

if secondNumber <= 0:
    print("Ta liczba nie jest dodatnia")
    exit()

try:
    thirdNumber = int(input("Podaj trzecią liczbę dodatnią: "))
except ValueError:
    print("Zła wartość!")
    exit()

if thirdNumber <= 0:
    print("Ta liczba nie jest dodatnia")
    exit()

print(max(firstNumber,secondNumber,thirdNumber))