#https://www.hackerrank.com/challenges/security-bijective-functions
import os
import hashlib
import sys

n = int(input())
X = {}

for i in range(n):
    X[i+1] = 1

Y = input()
Y = Y.split(' ')

for i in range(len(Y)):
    try:
        if X[int(Y[i])] == 1:
            X[int(Y[i])] = 0
            continue
        else:
            print('NO\n')
            exit()
    except KeyError:
        print('NO\n')
        exit()

print('YES\n')
