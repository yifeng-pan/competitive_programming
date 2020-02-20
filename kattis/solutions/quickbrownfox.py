# https://open.kattis.com/problems/quickbrownfox

cases = int(input())

for i in range(cases):
    text = input()
    missing = ""
    for i in range(26):
        c = chr(ord('a') + i)
        C = chr(ord('A') + i)
        if text.find(c) == -1 & text.find(C) == -1:
            missing += c
    print("pangram" if len(missing) == 0 else "missing " + missing)