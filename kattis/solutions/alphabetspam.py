# https://open.kattis.com/problems/alphabetspam

import sys
import math

xs = input()

white = 0
lower = 0
higher =0
other = 0

for i in xs:
    if i == '_':
        white += 1
    elif ('a' <= i) & (i <= 'z'):
        lower += 1
    elif ('A' <= i) & (i <= "Z"):
        higher += 1
    else:
        other += 1

print(white / len(xs))
print(lower / len(xs))
print(higher /len(xs))
print(other / len(xs))