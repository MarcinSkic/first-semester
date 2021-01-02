#Finding number digits and writing them and their sum

try:
    number = int(input("Podaj liczbę w przedziale <0 - 999>: "))
except ValueError:
    print("Zła wartość!")
    exit()

if number < 0 or number > 999:
    print("Ta liczba nie należy do przedziału!")
    exit()

suma = 0
digit = []
while(number > 1):
    digit.append(int(number%10))
    suma += int(number%10)
    number /= 10
digit.append(0)
digit.append(0)
answer = "Suma cyfr: {}, setki: {}, dziesiątki: {}, jedności: {}".format(suma,digit[2],digit[1],digit[0])
print(answer)
