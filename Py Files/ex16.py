# ENTRADA:
n = int(input())
m = int(input())

# PROCESSAMENTO:
def mult(n,m):
  soma = 0
  for i in range(m):
    soma+=n
  return soma

res = 1
for i in range(m):
  res = mult(res,n)
# SAIDA:
print(res)
