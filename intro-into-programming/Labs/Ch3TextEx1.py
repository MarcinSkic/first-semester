#Mini text board game 
from random import randint

playerTurn = 0
goodAnswer = False
playerPositions = [0,0,0,0]    #index defines which player, value on what position is
playersSpecialEfects = [0,0,0,0] #index defines which player, value defines what is happening to player
playersWaitTime = [0,0,0,0] #time counted in turns for how much player must wait, if -1 then special event
map = []

while(not goodAnswer):
    try:
        numberOfPlayers = int(input("Podaj ilość graczy (1 - 4): "))
    except ValueError:
        print("Zła wartość")
        continue
    if(numberOfPlayers < 0 or numberOfPlayers > 4):
        print("Zła liczba graczy")
        continue
    goodAnswer = True


for x in range(20):
    map.append(0)

map[2] = "a"
map[9] = "b"
map[13] = "e"
map[17] = "c"
map[19] = "d"
print(map)

def movePlayer(whichPlayerTurn,distance):

    playerPositions[whichPlayerTurn] += distance

    if(playerPositions[whichPlayerTurn] > 19):
        playerPositions[whichPlayerTurn] -= 20
    print("Gracz " + str(whichPlayerTurn+1) + " ląduje na polu: " + str(playerPositions[whichPlayerTurn]+1))



def turn(whichPlayerTurn):

    if(playersWaitTime[whichPlayerTurn] > 0):
        print("Gracz " + str(whichPlayerTurn+1) + " musisz czekać jeszcze " + str(playersWaitTime[whichPlayerTurn]) + " tur")
        playersWaitTime[whichPlayerTurn] -= 1
        return True

    if(playersWaitTime[whichPlayerTurn] == -1):

        input("Gracz " + str(whichPlayerTurn+1) + " wyrzuć kostką 4 żeby wydostać się z pułapki (naciśnij dowolny klawisz): ")
        diceRoll = randint(1,4)

        if(diceRoll == 4):
            print("Wyrzuciłeś 4, wychodzisz z pułapki!")
            playersWaitTime[whichPlayerTurn] = 0
        else:
            print("Wyrzuciłeś " + str(diceRoll) + ", zostajesz w pułapce")
            return True

    if(str(input("Gracz " + str(whichPlayerTurn+1) + " rzuć kostką żeby się ruszyć (kliknij dowolny klawisz lub wpisz 0 jeśli chcesz zakończyć program): ")) == "0"):
        print("Wyłączam grę")
        exit()
        
    diceRoll = randint(1,4)

    movePlayer(whichPlayerTurn,diceRoll)

    fieldValue = map[playerPositions[whichPlayerTurn]]

    if(fieldValue != 0):
        if(fieldValue == "d"):
            print("Wygrał gracz " + str(whichPlayerTurn+1) + "!")
            return False
        if(fieldValue == "b"):
            temp = randint(1,3)
            playersWaitTime[whichPlayerTurn] = temp
            print("Wylądowałeś na polu czekania, musisz poczekać jeszcze " + str(temp) + " tur")
        if(fieldValue == "c"):
            playerPositions[whichPlayerTurn] = 0
            print("Wylądowałeś na polu powrotu na start!")
        if(fieldValue == "a"):
            print("Wylądowałeś na polu bonusowym i zostajesz przemieszczony do przodu!")
            movePlayer(whichPlayerTurn,5)
        if(fieldValue == "e"):
            print("Wpadłeś w pułapkę!")
            playersWaitTime[whichPlayerTurn] = -1

    return True


while(turn(playerTurn)):    
    playerTurn += 1
    print("")
    if (playerTurn >= numberOfPlayers):
        playerTurn = 0       