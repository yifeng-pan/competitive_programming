# https://acpc20d1.kattis.com/problems/acpc20.bestinvesting

import math
import sys


def update(C, B, R):
    Y = len(C)

    B[0] = C[0] * R
    for i in range(Y - 1):
        x = i + 1
        B[x] = (C[x] + B[x-1])*R
    return

rydw = [int(n) for n in input().split()]
# rydw = [7,100,1,100000]
# rydw = [100,10,1,200]

r = rydw[0]
y = rydw[1]
d = rydw[2]
w = rydw[3]

R = 1 + r / 100

# Years, Deposits, Withrdaws, money in bank by end of year
Y = y + 1
C = []
B = []
for i in range(Y):
    C.append(d)
    B.append(0)

update(C,B,R)


i = Y - 2
required = 0
while B[Y-1] > 0:
    if B[i] - required <= w:
        C[i + 1] = - B[i] + required
        required += C[i + 1]
    else:
        C[i + 1] = -w
        required += w
        i -= 1
        required /= R
    update(C,B,R)
    # print("test Case:")
    # print(C)
    # print(B)

print('%.20f' % -sum(C))
