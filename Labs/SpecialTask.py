5
while(True):
    try:
        searchedIndex = int(input("Podaj n wyrazu którego szukasz: "))

        if(searchedIndex <= 0):
            print("To powinna być liczba dodatnia!")
            continue
        break
    except ValueError:
        print("Zła wartość, podaj jeszcze raz")
        continue

def FirstExercise(number,previousNumber):
    #print(number)
    if(number == searchedIndex):       
        return 2
    number += 1
    return FirstExercise(number,previousNumber+3)


print(str(FirstExercise(1,2)))