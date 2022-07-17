X = int(input())
n = 0
n2 = 0
for i in range (X):
  Y = int(input())
  if Y>=n:
    n2 = n
    n = Y
  else:
    if Y>n2:
      n2 = Y
print(n)
print(n2)