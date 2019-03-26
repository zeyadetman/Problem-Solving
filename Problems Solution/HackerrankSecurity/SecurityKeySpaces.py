#https://www.hackerrank.com/challenges/security-key-spaces
import os
import hashlib
import sys

F = {}
Fi = {}
S = []
Y = input()
n = int(input())

for i in range(len(Y)):
    F[i] = (int(n) + int(Y[i])) % 10
    sys.stdout.write(str(F[i]))
