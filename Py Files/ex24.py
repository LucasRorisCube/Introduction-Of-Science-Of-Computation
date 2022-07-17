X = int(input())
c = 0
maior = 0
menor = 0
soma = 0
for i in range (X):
  Y=int(input())
  if c ==1:
    if Y>maior:
      maior = Y
    if Y<menor:
      menor = Y
    soma += Y
  else:
    soma = Y
    maior = Y
    menor = Y
    c+=1
print(maior)
print(menor)
print(soma)