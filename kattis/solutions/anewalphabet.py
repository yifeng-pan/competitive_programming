# https://open.kattis.com/problems/anewalphabet

import sys

alphabet = ["@", "8", "(", "|)", "3", "#",
            "6", "[-]", "|", "_|", "|<", "1",
            "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z",
            "$", "']['", "|_|", "\\/", "\\/\\/", "}{",
            "`/", "2"
            ]

text = sys.stdin.readline()
new_text = ""

a = ord('a')
z = ord('z')
A = ord('A')
Z = ord('Z')

for c in text:
    oc = ord(c)
    if a <= oc & oc <= z:
        new_text += alphabet[oc - a]
    elif A <= oc & oc <= Z:
        new_text += alphabet[oc - A]
    else:
        new_text += c

print(new_text)