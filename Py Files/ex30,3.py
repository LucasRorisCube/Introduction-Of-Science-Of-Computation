import math
X = int(input())
m1 = -math.inf
m2 = -math.inf
for i in range (X):
  Y = int(input())
  if Y>=m1:
    m2 = m1
    m1 = Y
  else:
    if Y>m2:
      m2 = Y
if m2 == -math.inf:
  m2 = m1
print(m1)
print(m2)