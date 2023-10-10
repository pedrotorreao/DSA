"""
Given a string sentence containing English letters (lower- or upper-case), return true if sentence is a Pangram, or false otherwise.

A Pangram is a sentence where every letter of the English alphabet appears at least once.

Note: The given sentence might contain other characters like digits or spaces, your solution should handle these too.
"""


def is_pangram(sentence):
    if len(sentence) < 26:
        return False

    letter_map = set()

    for letter in sentence.lower():
        if letter.isalpha() and letter not in letter_map:
            letter_map.add(letter)
        if len(letter_map) == 26:
            return True

    return False


sentence = "TheQuickBrownFoxJumpsOverTheLazyDog"
print(f'"{sentence}" is a pangram: {is_pangram(sentence)}')

sentence = "This is not a pangram"
print(f'"{sentence}" is a pangram: {is_pangram(sentence)}')
