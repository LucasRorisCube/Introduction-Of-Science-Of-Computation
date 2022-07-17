# ENTRADA:
a = int(input())
b = int(input())

# PROCESSAMENTO:
while b != 0:
  temp = b
  b = a%b
  a = temp
res = a 

# SAIDA:
print(res)