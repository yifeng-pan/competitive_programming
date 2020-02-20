# https://open.kattis.com/problems/cetvrta

import sys

xs = []
ys = []

for i in sys.stdin:
    xy = i.split()
    x = int(xy[0])
    y = int(xy[1])
    xs.append(x)
    ys.append(y)

xs.sort()
ys.sort()

print(xs[2] if xs[0] == xs[1] else xs[0])
print(ys[2] if ys[0] == ys[1] else ys[0])