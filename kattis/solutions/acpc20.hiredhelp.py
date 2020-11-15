# https://acpc20d1.kattis.com/problems/acpc20.hiredhelp

import math
import sys


NK = [int(n) for n in input().split()]
ds = [int(n) for n in input().split()]

# NK = [6,3]
# # ds = [1,1,2,2,1,2,3,2,1]
# # ds = [3,1,2,2,1,2,3,3,3,3,2,4]
# ds = [3,1,3,2,1,2]
# ds = [1,2,3,1,2,3]

N = NK[0]
K = NK[1]

# print(ds)
ds.sort()
ds = ds[::-1]
# print(ds)

ks = []
for i in range(K):
    ks.append(0)

ki = 0
i = 0
k = K
while i < len(ds):
    if ds[i] >= k:
        ks[ki] += 1
        i += 1
    else:
        k -= 1
        ki += 1

ks = ks[::-1]
# print(ks)
# print(ks[K-1])

count = 0

while True:
    need = 0
    i = 0

    while i < len(ks) and need < K - 1:
        if i >= need and ks[i] > 0:
            ks[i] -= 1
            need += 1
        else:
            i += 1

    # print(ks)

    if need == K - 1 and ks[K - 1] > 0:
        count += 1
        ks[K-1] -= 1
    else:
        print(count)
        sys.exit()

# while ks[K-1] > 0:
#     required = 0
#     i = 0
#
#     while i < len(ks):
#         if i >= required and ks[i] > 0:
#             ks[i] -= 1
#             required += 1
#         else:
#             i += 1
#
#     count += 1

# print(count)
