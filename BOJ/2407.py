import sys
n, m = map(int, sys.stdin.readline().split())

factorial = [1, 1, 2]
for i in range(3, n+1):
  factorial.append(factorial[i-1]*i)

print(factorial[n]//(factorial[m]*factorial[n-m]))