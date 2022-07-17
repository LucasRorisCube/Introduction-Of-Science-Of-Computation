Y = int(input())
soma = 0
while Y >= 10:
  soma += Y%10
  Y = int(Y/10)
soma += Y
print(soma)