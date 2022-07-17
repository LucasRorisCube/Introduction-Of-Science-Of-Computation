# ENTRADA:
L = float(input())
M = float(input())
A = float(input())
V = float(input())

# PROCESSAMENTO:
res = 0
if V>L:
  res = ((V-L)*A)+M
# SAIDA:
print("{:.2f}".format(res))