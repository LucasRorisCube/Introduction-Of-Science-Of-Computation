X = float(input())
V1 = float(input())
V2 = float(input())
A = float(input())

if A<=X:
  res = A*V1
else:
  res = A*V2

print("{:.2f}".format(res))