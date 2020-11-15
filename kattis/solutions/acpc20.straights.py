# https://acpc20d1.kattis.com/problems/acpc20.straights

import math
import sys

N = int(input())
# ns = []
ns = [int(n) for n in input().split()]

# for i in range(N):
#     n = int(input())
#     ns.append(n)

# ns = [1,8,3,6,5,7,2,1]
# ns = [1,2,3]
# ns = [1,2,3,4,5,5]
# ns = [1,2,3,5,5,6,7]

ns.sort()

# print(ns)


turns = 0
while len(ns) > 0:
    i = 0
    n = ns[i]
    del ns[i]
    while i < len(ns) and (ns[i] <= n + 1):
        if ns[i] == n:
            i += 1
        elif ns[i] == n + 1:
            n += 1
            del ns[i]
    # print(ns)
    turns += 1

print(turns)
