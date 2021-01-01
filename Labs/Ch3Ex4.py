#

n = 2
minimum = 100000000000
maximum = 0
power = 1
while n % 2 == 0:
    try:
        n = int(input("Podaj liczbę: "))
        if(n < 0 or not(n % 2 == 0)):
            continue
        if(minimum > n):
            minimum = n
        elif(maximum < n):
            maximum = n
    
    except ValueError:
        print("Zła wartość, spróbuj jeszcze raz")
        continue

for x in range(maximum):
    power *= minimum
    
    
print(power)