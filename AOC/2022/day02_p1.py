score = 0

def game(him, me):
    if him == 'A': # ROCK
        if me == 'X': # ROCK
            return 1 + 3
        elif me == 'Y': # PAPER
            return 2 + 6
        elif me == 'Z': # SCISSORS
            return 3 + 0
    elif him == 'B': # PAPER
        if me == 'X': # ROCK
            return 1 + 0
        elif me == 'Y': # PAPER
            return 2 + 3
        elif me == 'Z': # SCISSORS
            return 3 + 6
    elif him == 'C': # SCISSORS
        if me == 'X': # ROCK
            return 1 + 6
        elif me == 'Y': # PAPER
            return 2 + 0
        elif me == 'Z': # SCISSORS
            return 3 + 3

    return 0

while (True):
    try:
        him, me = input().split(' ')
        score += game(him, me)
    except:
        break

print(score)