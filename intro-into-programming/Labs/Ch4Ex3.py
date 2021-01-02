
array = []

#Adding numbers until user types 0
while(True):   
    try:
        number = float(input("Podaj liczbę do tablicy: "))
        if(number == 0):
            break
        array.append(number)
        print("Dodano: " + str(number))
    except ValueError:
        print("Zła wartość, podaj jeszcze raz")
        continue
print(array)
print()

i = 0
while(len(array)/2 > i):
    if(array[i] != array[-1-i]):
        print("Ta tablica nie jest symetryczna!")
        break
    i += 1
else:
    print("Ta tablica jest symetryczna")