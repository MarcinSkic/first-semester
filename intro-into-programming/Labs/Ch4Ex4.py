array = []
repeated = []

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


array = [1,1,56,1,44,1,1253,5,4,23,56,78,8,7,2,5,2,2,9,65,2,2,3,3,5]
array.sort()

print(array)
print()


#array.__contains__(temp)

while(len(array) > 0):
    temp = array.pop()
    if(temp == array[-1]):
        repeated.append(temp)
        while(len(array) > 0 and temp == array[-1]):
            array.remove(temp)

print(repeated)
