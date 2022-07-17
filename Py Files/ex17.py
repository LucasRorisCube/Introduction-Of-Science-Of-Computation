# ENTRADA:
a = int(input())
b = int(input())
c = int(input())

# PROCESSAMENTO:
if a>b:
  if a>c:
    res = a
  else:
    res = c
else:
  if b>c:
    res = b
  else:
    res = c
# SAIDA:
print(res)