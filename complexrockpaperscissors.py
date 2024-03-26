from random import random
import math

def main():
    playercount = int(input("How many players? "))
    if playercount != 1 and playercount != 2:
        print("Invalid number of players.")
        return 1
    pnames = ["placeholder", "Computer"]
    for i in range(playercount):
        pnames[i] = input("Welcome, entity. Enter your name, player: ")
    if playercount == 1:
        print(f"Welcome to the most convoluted version of rock paper scissors you've ever played, {pnames[0]}!")
    else:
        print(f"Welcome to the most convoluted version of rock paper scissors you've ever played, {pnames[0]} and {pnames[1]}!")
    scores = [0, 1]
    moves = [0, 1]
    avatars = ["rock", "paper", "scissors", "potato", "sailboat"] #thanks Schulze!
    # computer player case.
    for i in range(playercount):
        scores[i] = takequiz(pnames[i])
        moves[i] = avatars[scores[i]]
        print(f"Based on your quiz scores, {pnames[i]}, your spirit animal is a {moves[i]}.")
    if playercount == 1:
        scores[1] = math.floor(random() * 4)
        moves[1] = avatars[scores[1]]
        print(f"The computer has chosen {moves[1]}.")
    winner = calcwinner(moves)
    if (winner == 0):
        print(f"Congrats, {pnames[0]}! You beat {pnames[1]} with {moves[0]} over {moves[1]}.")
    elif (winner == 1):
        print(
            f"Unfortunately, you, {pnames[0]}, lost to {pnames[1]}. Their {moves[1]} beat your {moves[0]}.")
    else:
        print("You have met your matches! The two of you tied.")
    return 0


def calcwinner(moves):
    if moves[0] == "rock" and moves[1] == "scissors":
        print("The good old-fashioned rock beats scissors. A large, gray rock smashed a pair of scissors into oblivion.")
        return 0
    elif moves[0] == "rock" and moves[1] == "potato":
        print("A rock came sailing out of nowhere and splattered the starch of the potato everywhere. What a mess!")
        return 0
    elif moves[0] == "scissors" and moves[1] == "paper":
        print("The good old-fashioned scissors beats paper. The scissors viciously slice the paper to bits.")
        return 0
    elif moves[0] == "scissors" and moves[1] == "sailboat":
        print("A pair of scissors - incredibly sharp ones - wreaks havoc on a sailboat! It shreds the sails and splices the forestays.")
        return 0
    elif moves[0] == "paper" and moves[1] == "rock":
        print("Paper beats rock. It covers the rock on all sides, effectively blinding it.")
        return 0
    elif moves[0] == "paper" and moves[1] == "potato":
        print("Paper blinds the potato by completely wrapping it in an opaque sheet of... paper.")
        return 0
    elif moves[0] == "potato" and moves[1] == "scissors":
        print("A potato sails through the air and splatters all over the scissors, getting gunk stuck between its blades and rendering the scissors useless.")
        return 0
    elif moves[0] == "potato" and moves[1] == "sailboat":
        print("The potato, unfortunately, does not fit like a tennis ball in the back of the sailboat! Water drains in and the boat sinks.")
        return 0
    elif moves[0] == "sailboat" and moves[1] == "paper":
        print("Upon setting sail, a wave of water splashes into the boat, leaving the paper inside wet and limp.")
        return 0
    elif moves[0] == "sailboat" and moves[1] == "rock":
        print("The sailboat cheerily capsizes and turtles, dumping the rock into the water and letting it sink to the bottom of the lake.")
        return 0
    elif moves[1] == "rock" and moves[0] == "scissors":
        print("The good old-fashioned rock beats scissors. A large, gray rock smashed a pair of scissors into oblivion.")
        return 1
    elif moves[1] == "rock" and moves[0] == "potato":
        print("A rock came sailing out of nowhere and splattered the starch of the potato everywhere. What a mess!")
        return 1
    elif moves[1] == "scissors" and moves[0] == "paper":
        print("The good old-fashioned scissors beats paper. The scissors viciously slice the paper to bits.")
        return 1
    elif moves[1] == "scissors" and moves[0] == "sailboat":
        print("A pair of scissors - incredibly sharp ones - wreaks havoc on a sailboat! It shreds the sails and splices the forestays.")
        return 1
    elif moves[1] == "paper" and moves[0] == "rock":
        print("Paper beats rock. It covers the rock on all sides, effectively blinding it.")
        return 1
    elif moves[1] == "paper" and moves[0] == "potato":
        print("Paper blinds the potato by completely wrapping it in an opaque sheet of... paper.")
        return 1
    elif moves[1] == "potato" and moves[0] == "scissors":
        print("A potato sails through the air and splatters all over the scissors, getting gunk stuck between its blades and rendering the scissors useless.")
        return 1
    elif moves[1] == "potato" and moves[0] == "sailboat":
        print("The potato, unfortunately, does not fit like a tennis ball in the back of the sailboat! Water drains in and the boat sinks.")
        return 1
    elif moves[1] == "sailboat" and moves[0] == "paper":
        print("Upon setting sail, a wave of water splashes into the boat, leaving the paper inside wet and limp.")
        return 1
    elif moves[1] == "sailboat" and moves[0] == "rock":
        print("The sailboat cheerily capsizes, dumping the rock into the water and letting it sink to the bottom of the lake.")
        return 1
    else:
        print("It appears two identical things have tried to fight, resulting in a tie.")
        return 2

def takequiz(playername):
    # trivia source: https://www.signupgenius.com/groups/random-trivia-questions-for-everyone.cfm
    # or https://www.watercoolertrivia.com/trivia-questions/skiing-trivia-questions
    # some by myself.
    print(f"Your turn to test your knowledge of stupid things, {playername}!")
    questions = list()
    answers = list()
    score = 0
    with open("randomtrivia.txt") as file:
        for line in file:
            questions.append(line)
    with open("answers.txt") as file:
        for line in file:
            answers.append(line)
    #Question 1
    for i in range(4):
        print(f"Question {i + 1} is:")
        #select the question from the list w randomly generated index
        #compare user input to corresponding answer.
        number = math.floor(random() * 20)
        answer = input(f"{questions[number]}")
        if (answer.rstrip().lower() == answers[number].rstrip().lower()):
            print("Correct!")
            score += 1
        else:
            print("YOU FAILED.")
    return score

main()
