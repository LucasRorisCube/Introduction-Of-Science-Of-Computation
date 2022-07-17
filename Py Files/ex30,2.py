X = int(input())
m1 = -100000
m2 = -100000
for i in range (X):
  Y = int(input())
  if Y>=m1:
    m2 = m1
    m1 = Y
  else:
    if Y>m2:
      m2 = Y

print(m1)
print(m2)