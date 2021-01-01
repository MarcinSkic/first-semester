#Getting numbers from user until their sum > 255 or product > 50000 and then counting mathematic average from them 

suma = 0
iloczyn = 1
amount = 0
while suma < 255 and iloczyn < 50000:
    try:
        n = int(input("Podaj liczbę: "))
        amount += 1
        suma += n
        iloczyn *= n
    except ValueError:
        print("Zła wartość, spróbuj jeszcze raz")
        continue

print(suma/amount)