#Finding two numbers (binary search) that are interval borders and tells what numbers are beetwen them in array (list)
try:
    n = int(input("Ile liczb chcesz podać: "))
    if(n <= 0):
        print("Wielkość tablicy powinna być liczbą dodatnią")
        exit()
except ValueError:
    print("Zła wartość")
    exit()

array = []


for i in range(n):
    try:
        array.append(float(input("Podaj "+ str(i+1) + " element tablicy: ")))
    except ValueError:
        print("Zła wartość")
        n -= 1
array = [56,23,123,45,908,128,43,12,53,56,54,65,433228,98120,412,1212,90,44,2,1,6,3,5]

array.sort()

print()
print(array)
print()
print(array[-1])

while(True):

    try:
        min = float(input("Podaj pierwszą liczbę przedziału: "))
        max = float(input("Podaj drugą liczbę przedziału: "))
        
        if(max < min):
            temp = min
            min = max
            max = temp
        break

    except ValueError:
        print("Zła wartość, podaj jeszcze raz")

i = 0
startIndex = 0
endIndex = 0
startFound = False
endFound = False

if(min <= array[0]):
    startIndex = 0
    startFound = True
if(max >= array[-1]):
    endIndex = 0
    endFound = True

while(not startFound or not endFound):
    if(not startFound and array[i] >= min):
        startFound = True
        startIndex = i
    if(not endFound and array[-1-i] <= max):
        endFound = True
        endIndex = i
    i += 1

print("Liczby spełniające zakres: " + str(array[startIndex:-1-endIndex]))

#Testing purpouses, not finalized version
def BinarySearch(searchedNumber):

    notFind = True
    lowerLimit = 0
    upperLimit = len(array)-1

    while(notFind):

        currentIndex = round((lowerLimit+upperLimit)/2)

        temp = array[currentIndex] 

        print("Aktualna liczba sprawdzana w tablicy " + str(temp))
        print("Aktualny sprawdzany index " + str(currentIndex))

        try:
            if(searchedNumber < array[currentIndex+1] and searchedNumber > array[currentIndex-1] and searchedNumber != temp):
                print("Tej liczby nie ma w tablicy!")
                return currentIndex
        except IndexError:
            print("Łups")
        

        if(searchedNumber == temp):

            print("Znaleziono!")
            return currentIndex

        elif(searchedNumber < temp):

            upperLimit = currentIndex

            if(upperLimit == 0):
                print("Tej liczby nie ma w tablicy!")
                return currentIndex
        else:

            lowerLimit = currentIndex

            if(lowerLimit == len(array)-1):
                print("Tej liczby nie ma w tablicy!")
                exit()

#BinarySearch(98120)   


