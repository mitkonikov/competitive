score = 0

def R():
    return 1

def P():
    return 2

def S():
    return 3

def game(him, me):
    if him == 'A': # ROCK
        if me == 'X': # LOSE
            return 0 + S()
        elif me == 'Y': # DRAW
            return 3 + R()
        elif me == 'Z': # WIN
            return 6 + P()
    elif him == 'B': # PAPER
        if me == 'X': # LOSE
            return 0 + R()
        elif me == 'Y': # DRAW
            return 3 + P()
        elif me == 'Z': # WIN
            return 6 + S()
    elif him == 'C': # SCISSORS
        if me == 'X': # LOSE
            return 0 + P()
        elif me == 'Y': # DRAW
            return 3 + S()
        elif me == 'Z': # WIN
            return 6 + R()

    return 0

while (True):
    try:
        him, me = input().split(' ')
        score += game(him, me)
    except:
        break

print(score)