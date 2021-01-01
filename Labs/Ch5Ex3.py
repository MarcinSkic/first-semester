def CountSumOfDigits(number):
    suma = 0
    while(number > 0):
        suma += number%10
        number = int(number/10)
    return suma

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
targetArray = []
while(i<n):
    try:
        array.append(int(input("Podaj " + str(i+1) + " element tablicy: ")))
        i += 1
    except ValueError:
        print("Błędna wartość")
last = array[-1]
for x in array:
    if(CountSumOfDigits(x) > last):
        targetArray.append(x)

print(targetArray)
print("Ilość liczb których suma cyfr jest większa od ostatniego elementu "+ str(len(targetArray)))