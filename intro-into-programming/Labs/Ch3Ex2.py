#Sum of squares of numbers in interval <10,50>. Amount of numbers is told by user

try:
    n = int(input("Ile liczb chcesz podać? "))
    if(n < 0):
        print("To powinna być liczba dodatnia")
        exit()
except ValueError:
    print("Zła wartość")
    exit()
suma = 0
temp = n    

while(temp > 0):
    try:
        number = int(input("Podaj " + str(n - temp + 1) + " liczbę z przedziału 10/50: "))
        if(number < 10 or number > 50):
            print("Zły przedział, podaj jeszcze raz")
            continue
        temp -= 1
        suma += pow(number,2)

    except ValueError:
        print("Zła wartość, podaj jeszcze raz")
        continue

print (suma)

