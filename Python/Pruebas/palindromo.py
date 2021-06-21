def palindrom(word):
    reversed_word = ''
    if ' ' in word:
        word = word.replace(" ", "")
        reversed_word = word[::-1]
        reversed_word = reversed_word.replace(" ", "")
        return True if reversed_word == word else False

    else:
        reversed_word = word[::-1]
        return True if reversed_word == word else False

while True:
    word = input('Inserta una palabra>: ')
    print("La palabra es un palindromo" if palindrom(word) == True else "La palabra no es un palindromo")
