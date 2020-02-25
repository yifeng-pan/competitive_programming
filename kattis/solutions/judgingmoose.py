# https://open.kattis.com/problems/judgingmoose

import sys

for i in sys.stdin:
    lr = i.split()
    l = int(lr[0])
    r = int(lr[1])

if (l == 0) & (r == 0):
    output = "Not a moose"
elif l != r:
    output = "Odd " + str(max(l,r) * 2)
else:
    output = "Even " + str(l + r)

print(output)