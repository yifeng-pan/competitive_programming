# https://acpc20d1.kattis.com/problems/acpc20.passwordrotation

import sys
import math

def rotation(str1, str2):
    if len(str1) != len(str2):
        return False
    str3 = str1 + str1
    if str3.count(str2) > 0:
        return True
    return str3[::-1].count(str2) > 0


N = int(input())
ns = []

for i in range(N):
    n = str(input())
    ns.append(n)
    # ns.append(n[::-1])

for a in range(len(ns) - 1):
    for b in range(a + 1, len(ns)):
        # print(ns[a])
        # print(ns[b])
        if(rotation(ns[a],ns[b])):
            print("Yes")
            sys.exit()
print("No")


# print(ns)
