#Ch2Ex1 - Chapter 2 Exercise 1 "Rock Paper Scissors"
pierwszyGracz = input("Pierwszy gracz podaj wartość (papier - 0, kamien - 1, nożyce - 2): ")

if not(pierwszyGracz in ("0","1","2")):
    print("Błędna wartość")

drugiGracz = input("Drugi gracz podaj wartość (papier - 0, kamien - 1, nożyce - 2): ")

if not(drugiGracz in ("0","1","2")):
    print("Błędna wartość")

if(drugiGracz == pierwszyGracz):
    print("Remis")
elif (pierwszyGracz == "0" and drugiGracz == "1") or (pierwszyGracz == "1" and drugiGracz == "2") or (pierwszyGracz == "2" and drugiGracz == "0"):
    print("Wygrał pierwszy gracz!")
else:
    print("Wygrał drugi gracz!")