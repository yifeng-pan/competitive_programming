# https://open.kattis.com/problems/batterup

import sys

int(input())

ns = sys.stdin.readline().split()
ns = map(int, ns)
ns = list(filter(lambda a: a != -1, ns))

print(sum(ns) / len(ns))