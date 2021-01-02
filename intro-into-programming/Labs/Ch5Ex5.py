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
i = 0
x = 0
while(i<n and array[i] != None):
    print(array)
    if(array[i] % 5 == 0):
        x = i
        while(x+1<n):
            array[x] = array[x+1]
            x += 1
        array[x] = None
    i += 1
print(array)