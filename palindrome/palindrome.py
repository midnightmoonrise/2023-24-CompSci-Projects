# Determine if a word is a palindrome.
def main():
    word = str(input("Gimme a word: "))
    if word == "":
        print("You did not give me a word! >:(")
        return
    wordlist = []
    for letter in word:
        if letter != ' ':
            wordlist.append(letter)
    length = len(wordlist)
    for i in range(length):
        if wordlist[i].lower() == wordlist[length - 1 - i].lower():
            continue
        else:
            print("This string is not a palindrome.")
            return

    print("This string is a palindrome.")
    return

main()
