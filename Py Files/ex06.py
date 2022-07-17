# ENTRADA:
n = int(input())
c = int(input())
m = int(input())
x = 0
res = 0
# PROCESSAMENTO:
while n>=c:
  n = n-c
  x += 1
  res += 1
while x >=m:
  x = x-m
  x +=1
  res += 1
# SAIDA:
print(res)