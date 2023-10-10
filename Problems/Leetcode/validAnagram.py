"""
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
"""


def is_valid_anagram_1(s, t):
    if len(s) != len(t):
        return False

    hash_map = dict()

    for c in s:
        if c not in hash_map:
            hash_map[c] = 1
        else:
            hash_map[c] += 1

    for c in t:
        if c not in hash_map:
            return False

        hash_map[c] -= 1

        if hash_map[c] == 0:
            hash_map.pop(c)

    return len(hash_map) == 0


def is_valid_anagram_2(s, t):
    if len(s) != len(t):
        return False

    hash_map = dict()

    for i in range(0, len(s)):
        if s[i] not in hash_map:
            hash_map[s[i]] = 1
        else:
            hash_map[s[i]] += 1

        if t[i] not in hash_map:
            hash_map[t[i]] = -1
        else:
            hash_map[t[i]] -= 1

    for ch in hash_map:
        if hash_map[ch] != 0:
            return False

    return True


s = "listen"
t = "silent"
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_1(s,t)}')
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_2(s,t)}')
print("\n")

s = "rat"
t = "car"
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_1(s,t)}')
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_2(s,t)}')
print("\n")

s = "hello"
t = "world"
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_1(s,t)}')
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_2(s,t)}')
print("\n")

s = "abcdefghijklm"
t = "cfadgebmilkjh"
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_1(s,t)}')
print(f'string "{t}" is a valid anagram of "{s}": {is_valid_anagram_2(s,t)}')
print("\n")
