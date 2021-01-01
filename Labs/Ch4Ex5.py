#Some weird shit
try:
    n = int(input("Ile liczb chcesz podać: "))
    if(n < 4):
        print("Wielkość tablicy powinna być liczbą dodatnią")
        exit()
except ValueError:
    print("Zła wartość")
    exit()

array = []

i = 0
while(i < n):
    try:
        array.append(float(input("Podaj "+ str(i+1) + " element tablicy: ")))
        i += 1
    except ValueError:
        print("Zła wartość")

        