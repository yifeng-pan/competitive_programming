# https://open.kattis.com/problems/quickestimate

import sys
import math

N = int(input())

for i in range(N):
    n = int(input())
    if n == 0:
        print(1)
    else:
        print(math.floor(math.log10(n)) + 1)