X = int(input())
res = 0
velamaior = 0
for i in range (X):
  Y = int(input())
  if Y == velamaior:
    res = res + 1
  if Y > velamaior:
    res = 0
    res = res + 1
    velamaior = Y
  

print(res)