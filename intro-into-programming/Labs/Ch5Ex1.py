countToAverage = False
suma = 0
i = 0
print("Program liczący średnią dziwnie, wpisz 0 aby zmienić tryb")
while(True):
    try:
        n = int(input("Podaj liczbę: "))
    except ValueError:
        print("Zła wartość")
        continue
    if(n == 0):
        countToAverage = not countToAverage
        if(countToAverage):
            print("Zmieniono tryb na licz średnią")
        else:
            print("Zmieniono tryb na nie licz średniej")
        continue
    if(countToAverage):
        suma += n
        i += 1
    else:
        if(n<0):
            break
if(suma == 0):
    print("Żadna liczba nie została podana do liczenia średniej")
print("Średnia wynosi: " + str(suma/i))