from random import randint
class Colors:   #Class with color codes only to get data
    BOLD = '\033[1m'
    RESET = '\033[0m'
    RED = '\033[31m'
    WHITE = '\033[30m'
    GREEN = '\033[32m'
    LIGHTYELLOW = '\033[93m'
    BLUE = '\033[34m'
    YELLOW = '\033[33m'
    IGHTBLUE = '\033[94m'
    CYAN = '\033[96m'
    TEAL = '\033[36m'
    LESSRED = '\033[91m'
    PINK = '\033[35m'

class StaticData:   #Class with values for game only to get data
    experienceMultiplayer = 2
    hpMultiplayer = 1.5
    meleeWeaponMultiplayer = 2
    meleeDamageMultiplayer = 1.5
    magicDamageMultiplayer = 3
    weaponCostMultiplayer = 3
    baseXp = 7
    baseGold = 15
    baseEnemyHealth = 10 
    potionCost = 50

class EnemyType:    #Class with values about enemies
    def __init__(self,name,meleeVulnerability,magicVulnerability,difficulty,hp,damage,maxHP,maxDamage):
        self.name = name
        self.meleeVulnerability = meleeVulnerability
        self.magicVulnerability = magicVulnerability
        self.difficulty = difficulty
        self.hp = hp
        self.damage = damage
        self.maxHP = maxHP
        self.maxDamage = maxDamage

class PlayerData: #Class storing data about players statistics, changed during game

    def __init__(self):
        print("PlayerData:: Initialized")

    maxLife = 70
    currentLife = 70
    gold = 0
    level = 1
    experience = 0
    requiredExperience = 30
    weaponDamage = 5
    meleeSkill = 1
    meleeDamage = 5
    mageSkill = 1
    mageDamage = 3
    potionsAmount = 0
    weaponCost = 100

    def getData(self):
        data = Colors.YELLOW + "Życie: {}\nDoświadczenie: {}/{}\nSkill wręcz: {}\nObrażenia wręcz {}\nSkill magi: {}\nObrażenia magiczne: {}\nObrażenia broni {}\nLiczba mikstur: {}\nZłoto: {}" + Colors.RESET
        data = data.format(self.currentLife,self.experience,self.requiredExperience,self.meleeSkill,self.meleeDamage,self.mageSkill,self.mageDamage,self.weaponDamage,self.potionsAmount,self.gold)
        return data

class UI:   #class with methods for showing prompts and getting input from player
    
    def __init__(self,playerData):
        self.playerData = playerData
        print("UI:: Initialized")
    
    def skillAssigningOption(self):
        while(True):
            try:
                n = int(input("Wybierz czego skill chcesz zwiększyć (0 - Pokaż statystyki, 1 - skill wręcz, 2 - skill magi): "))
                print()
                if(n == 0):
                    self.showStatistics()
                    continue
                elif (n == 1):
                    return 1
                elif(n == 2):
                    return 2
                else:
                    print("Zła wartość")
                    continue
            except ValueError:
                print("Zła wartość")
                continue
    def fightOption(self):

        while(True):
            try:
                n = int(input(Colors.CYAN + "Wybierz ruch (0 - Pokaż statystyki, 1 - uderz mieczem, 2 - użyj magii, 3 - użyj mikstury, 4 - ucieknij): " + Colors.RESET))
                print()
                if(n == 0):
                    self.showStatistics()
                    continue
                elif(n == 1):
                    return 1
                elif(n == 2):
                    return 2
                elif(n == 3):
                    return 3
                elif(n == 4):
                    return 4
                else:
                    print("Zła wartość")
                    continue
            except ValueError:
                print("Zła wartość")
                continue      

    def damagePrompt(self,damageValue,enemyMaxHp):

        percentage = damageValue/enemyMaxHp

        if(percentage < 0.25):
            return "Słabe uderzenie"
        elif(percentage < 0.5):
            return "Średnie uderzenie"
        elif(percentage < 0.75):
            return "Silne uderzenie"
        else:
            return("Druzgoczące uderzenie")

    def showStatistics(self):
        print("\n"+self.playerData.getData()+"\n")

class PlayerMethods:    #class with methods for levelling up player

    def __init__(self,playerData,ui):
        self.playerData = playerData
        self.ui = ui
        print("PlayerMethods:: Initialized")
        

    def IncreaseExperience(self,acquiredExperience):

        self.playerData.experience += acquiredExperience

        while(self.playerData.experience >= self.playerData.requiredExperience):
            self.playerData.level += 1
            self.playerData.experience -= self.playerData.requiredExperience
            self.playerData.requiredExperience *= StaticData.experienceMultiplayer
            self.IncreaseLevel()

    def IncreaseLevel(self):

        self.playerData.maxLife *= StaticData.hpMultiplayer
        self.playerData.currentLife = self.playerData.maxLife

        if(self.ui.skillAssigningOption() == 1):
            self.playerData.meleeSkill += 1
            self.playerData.meleeDamage *= StaticData.meleeDamageMultiplayer
        else:
            self.playerData.mageSkill += 1
            self.playerData.mageDamage *= StaticData.magicDamageMultiplayer


class Fight:    #class with methods for fight between player and enemy

    def __init__ (self,playerData,ui,playerMethods):
        print("Fight:: Initialized")
        self.playerData = playerData
        self.ui = ui
        self.playerMethods = playerMethods
        self.enemies = [EnemyType("ork",1,1.3,1,12,5,12,5),EnemyType("ogr",0.5,2,2,15,7,15,7),EnemyType("minotaur",0.3,1,4,20,5,20,5),EnemyType("smok",0.5,0.5,5,40,10,40,10),EnemyType("czarodziej",2,0.1,3,10,7,10,7)]
        self.fightStrFormat = "Twoje życie: {}           Życie wroga: {}"

    def getRandomEnemy(self):
        index = 0
        los = randint(0,100)
        if(los < 40):
            index = 0
        elif(los < 60):
            index = 1
        elif(los < 80):
            index = 2
        elif(los < 90):
            index = 3
        else:
            index = 4
        enemy = self.enemies[index]
        enemy.difficulty += randint(1,6)
        return enemy

    def beginFight(self,enemyType):
        self.currentEnemy = enemyType

        self.currentEnemy.hp = self.currentEnemy.maxHP
        self.currentEnemy.damage = self.currentEnemy.maxDamage

        self.currentEnemy.hp *= ((enemyType.difficulty+5)/5)
        self.currentEnemy.damage *= ((enemyType.difficulty+3)/4)
        self.enemyMaxHp = self.currentEnemy.hp
        self.playerMaxHp = self.playerData.currentLife

        self.fightMachine()

    def fightMachine(self):
        while(True):
            stopFight = self.playerFightTurn()
            if(stopFight):
                break
            self.enemyFightTurn()

    def playerFightTurn(self):
        print("Twoja tura")
        print(self.fightStrFormat.format(Colors.GREEN + str(self.playerData.currentLife) + Colors.RESET, Colors.RED + str(self.currentEnemy.hp) + Colors.RESET)) 
        option = self.ui.fightOption()

        if(option == 1):
            damage = (self.playerData.meleeDamage + self.playerData.weaponDamage + randint(-1,1))*self.currentEnemy.meleeVulnerability

            print(self.ui.damagePrompt(damage,self.enemyMaxHp))
            print("Przeciwnik otrzymuje: " + str(damage))
            print()

            return self.dealDamageToEnemy(damage)           
        elif(option == 2):
            damage = (self.playerData.mageDamage + randint(-3,3))*self.currentEnemy.magicVulnerability
            
            print(self.ui.damagePrompt(damage,self.enemyMaxHp))
            print("Przeciwnik otrzymuje: " + str(damage) + " obrażeń\n")

            return self.dealDamageToEnemy(damage)
        elif(option == 3):
            if(self.playerData.potionsAmount >= 1):
                print("Wypiłeś potkę i odzyskałeś w pełni zdrowie")
                self.playerData.potionsAmount -= 1
                self.playerData.currentLife = self.playerData.maxLife
            else:
                print("Nie posiadasz potki i zmarnowałeś czas na jej szukanie, tracisz turę")

        elif(option == 4):
            print("Uciekłeś!\nTracisz połowę złota i doświadczenia")
            self.playerData.currentLife = self.playerData.maxLife
            self.playerData.experience /= 2
            self.playerData.gold /= 2
            return True
    def enemyFightTurn(self):
        print("Tura przeciwnika")
        damage = self.currentEnemy.damage + randint(-2,2)
        self.playerData.currentLife -= damage
        print("Otrzymujesz: " + str(damage) + " obrażeń\n")

        if(self.playerData.currentLife <= 0):
            print(Colors.RED + "Umarłeś!" + Colors.RESET)
            print("Koniec gry")
            exit()

    def dealDamageToEnemy(self,damage):
        if(damage < 0):
                damage = 0

        self.currentEnemy.hp -= damage

        return self.checkIfDead()

    def checkIfDead(self):
        if(self.currentEnemy.hp <= 0):
            return self.defeatEnemy()
        else:
            return False
    def defeatEnemy(self):

        print("Pokonałeś przeciwnika!")

        self.playerData.currentLife = self.playerData.maxLife
        self.playerMethods.IncreaseExperience(StaticData.baseXp*self.currentEnemy.difficulty)
        self.playerData.gold += StaticData.baseGold*self.currentEnemy.difficulty

        return True

class OtherMethods: #class with independent methods

    def __init__ (self):
        print("OtherMethods:: Initialized")
    
    def changeDifficultyToString(self,monsterDifficulty):
        if(monsterDifficulty < 3):
            return "Łatwy"
        elif(monsterDifficulty > 8):
            return "Trudny"
        else:
            return "Średni"

class Game: #main class with main game loop
    
    print("Loading game")
    playerData = PlayerData()
    ui = UI(playerData)
    playerMethods = PlayerMethods(playerData,ui)
    fight = Fight(playerData,ui,playerMethods)
    otherMethods = OtherMethods()

    currentEnemy = fight.getRandomEnemy()
    sleepTime = 0

    while(True):
        
        try:
            n = int(input("\nCo chcesz zrobić:\n0 - Pokaż statystyki\n1 - Zaatakuj przeciwnika: {} ({})\n2 - Prześpij się (pomiń przeciwnika)\n3 - Pójdź do sklepu\n4 - Wyjdź z gry\nTwój wybór: ".format(currentEnemy.name, otherMethods.changeDifficultyToString(currentEnemy.difficulty))))
            print()
            if(n == 0):
                ui.showStatistics()
                continue
            elif(n == 1):
                sleepTime = 0
                fight.beginFight(currentEnemy)

                currentEnemy = fight.getRandomEnemy()

            elif(n == 2):
                if(sleepTime < 2):
                    currentEnemy = fight.getRandomEnemy()
                    sleepTime += 1
                else:
                    print("Nie jesteś senny")
                    continue
            elif(n == 3):
                while(True):
                    try:
                        n = int(input("Co chcesz kupić? (Posiadane złoto: {})\n0 - Pokaż statystyki\n1 - Lepszy miecz {}\n2 - miksturę leczniczą {}\n3 - wyjdź ze sklepu\nTwój wybór: ".format(playerData.gold,playerData.weaponCost,StaticData.potionCost)))
                        print()
                        if(n == 0):
                            ui.showStatistics()
                            continue
                        elif(n == 1):
                            if(playerData.weaponCost <= playerData.gold):
                                playerData.gold -= playerData.weaponCost
                                playerData.weaponCost *= StaticData.weaponCostMultiplayer                                   
                                playerData.weaponDamage *= StaticData.meleeWeaponMultiplayer
                                
                            else:
                                print("Nie stać ciebie!")
                                continue
                        elif(n == 2):
                            if(StaticData.potionCost <= playerData.gold):
                                playerData.gold -= StaticData.potionCost
                                playerData.potionsAmount += 1
                            else:
                                print("Nie stać ciebie!")
                                continue
                        elif(n == 3):
                            break
                        else:
                            print("Zła wartość")
                            continue
                    except ValueError:
                        print("Zła wartość")
                        continue
                
            elif(n == 4):
                exit()
            else:
                print("Zła wartość")
                continue
        except ValueError:
            print("Zła wartość")
            continue