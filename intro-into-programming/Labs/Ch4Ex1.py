#Adding input to array (list) for n times and then finding 2 biggest elements (done by bubble sorting)

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
        i -= 1

array.sort()

print(array)

print("Dwa największe elementy tablicy: " + str(array[-2]) + ", " + str(array[-1]))