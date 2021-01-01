array = []
while(len(array) < 10):
    try:
        number  = int(input("Podaj liczbę: "))
        if(number == 0):
            break
        array.append(number)
    except ValueError:
        print("Błędna wartość")
        continue
print(array)
lewy = 0
prawy = len(array)-1
while(lewy < prawy):
    liczba = array[lewy]
    if(liczba % 2 == 0):
        lewy += 1
    else:
        array[lewy] = array[prawy]
        array[prawy] = liczba
        prawy -= 1
print(array)