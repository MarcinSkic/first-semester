#Calculator of Quadratic equations

from math import sqrt

print("Kalkulator równań postaci ax^2 + bx + c = 0")

notQuadratic = False

try:    #przypisuje wartość współczynnika i sprawdza poprawność
    a = float(input("Podaj współczynnik a: "))
except ValueError:
    print("Zła wartość!")
    exit()

if(a == 0): #sprawdza czy współczynnik nie jest 0, jeśli jest to obliczenia zostaną zmienione
    notQuadratic = True
    xTwo = ""
else:
    notQuadratic = False
    xTwo = str(a)+"x^2 + "  #Przypisuje ładne wyświetlanie użytkownikowi aktualnego równania

print(xTwo + "bx + c = 0")  #Wyświetla aktualne równanie

try:    
    b = float(input("Podaj współczynnik b: "))
except ValueError:
    print("Zła wartość!")
    exit()

if(b == 0 and a == 0):
    print("To jest równanie bez x, koniec programu")
    exit()
elif(b==0):
    xOne = ""
else:
    xOne = str(b)+"x + "

print(xTwo + xOne + "c = 0")

try:    
    c = float(input("Podaj współczynnik c: "))
except ValueError:
    print("Zła wartość!")
    exit()

if(notQuadratic):
    result = -c/b
    print("Wynikiem równania jest: " + str(result))
else:

    delta = pow(b,2) - 4*a*c

    if(delta < 0):
        print("To równanie nie ma rozwiązań")

    elif(delta == 0):
        result = -b/2*a
        print("Wynikiem równania jest: " + str(result))

    else:
        firstResult = (-b-sqrt(delta))/(2*a)
        secondResult = (-b+sqrt(delta))/(2*a)
        print("Wynikami równania są: " + str(firstResult) + " i " + str(secondResult))
