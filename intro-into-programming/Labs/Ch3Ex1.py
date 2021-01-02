#Improved rock paper scissors

firstTime = True
isDraw = True

while isDraw:
    if(firstTime):
        print("Witaj w grze papier, kamień, nożyce")
        firstTime = False
    else:
        print("Zagraj jeszcze raz!")

    pierwszyGracz = input("Pierwszy gracz podaj wartość (papier - 0, kamien - 1, nożyce - 2): ")

    if not(pierwszyGracz in ("0","1","2")):
        print("Błędna wartość")
        continue

    drugiGracz = input("Drugi gracz podaj wartość (papier - 0, kamien - 1, nożyce - 2): ")

    if not(drugiGracz in ("0","1","2")):
        print("Błędna wartość")
        continue

    if(drugiGracz == pierwszyGracz):
        print("Remis")       
        continue
    elif (pierwszyGracz == "0" and drugiGracz == "1") or (pierwszyGracz == "1" and drugiGracz == "2") or (pierwszyGracz == "2" and drugiGracz == "0"):
        print("Wygrał pierwszy gracz!")
        isDraw = False
    else:
        print("Wygrał drugi gracz!")
        isDraw = False