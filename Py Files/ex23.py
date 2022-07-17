
X = int(input())
res = 0
c = 0
for i in range (X):
  Y=int(input())
  if c ==1:
    if Y>res:
      res = Y
  else:
    res = Y
    c+=1
print(res)