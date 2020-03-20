# https://open.kattis.com/problems/oddmanout

import sys

def case(G):
    gs = sys.stdin.readline().split()
    gs.sort()

    for i in range(int(len(gs) / 2)):
        if(gs[2*i] != gs[2*i + 1]):
            return gs[2*i]
    
    return gs[len(gs) - 1]

N = int(input())
for i in range(N):
    G = int(input())
    print("Case #" + str(i + 1) + ": " + str(case(G)))