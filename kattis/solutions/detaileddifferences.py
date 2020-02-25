# https://open.kattis.com/problems/detaileddifferences

import sys

cases = int(input())

for i in range(cases):
    xs = str(sys.stdin.readline())
    ys = str(sys.stdin.readline())
    dif = ""
    for j in range(len(xs) - 1):
        dif += ('.' if (xs[j] == ys[j]) else '*')

    print(xs + ys + dif + '\n')