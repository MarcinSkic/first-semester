while(True):
    try:
        n = int(input("Podaj wielkość tablicy: "))
        if(n<=0):
            print("Wielkość tablicy musi być dodatnia, podaj jeszcze raz")
            continue
        break
    except ValueError:
        print("Błedna wartość")
i = 0
array = []
while(i<n):
    try:
        array.append(int(input("Podaj " + str(i+1) + " element tablicy: ")))
        i += 1
    except ValueError:
        print("Błędna wartość")

last = array[-1]

array.sort()

print(array)
i = array.index(last)

while(True):
    if(i+1 >= len(array)):
        print("Nie istnieją liczby większe od elementu ostatniego")
        exit()
    if(array[i+1] != last):
        break
    print("Powtórka")
    i += 1

amount = len(array[i+1:len(array)])
suma = sum(array[i+1:len(array)])

print("Suma liczb większych od ostatniego elementu: " + str(suma))
print("Średnia arytmetyczna liczb większych od ostatniego elementu: " + str(suma/amount))

