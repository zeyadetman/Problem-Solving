#https://www.hackerrank.com/challenges/security-inverse-of-a-function/
import os
import hashlib
import sys

n = int(input())
F = {}
S = {}
Y = input()
Y = Y.split(' ')

for i in range(len(Y)):
    F[i+1] = int(Y[i])
    S[int(Y[i])] = i+1

for i,j in S.items():
    print(j)
