# A script to manipulate input file so that we don't
# really have to change anything

import os

f = open('18.in').readlines()
os.system('g++ 18-2.cpp -o 18 -g -O3 -std=gnu++20')

res = 0
for i, a in enumerate(f):
    for j, b in enumerate(f):
        if i == j:
            continue
        nf = a + b
        open('18-2.in', 'w').write(nf)
        os.system('./18')
        x = open('18-2.out').read().rstrip('\n')
        res = max(res, int(x))

print(res)