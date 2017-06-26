#https://www.hackerrank.com/challenges/security-encryption-scheme
import sys

def function(x):
    res = 1
    for i in range(x):
       res =res* (i+1)
    print(res)

z = int(input())

function(z)
