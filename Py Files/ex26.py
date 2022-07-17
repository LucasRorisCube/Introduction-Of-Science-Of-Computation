
Y = int(input())
res = 0
soma = 0
n = 0
m = 0
i = 0
while Y>=0:
  soma+=Y
  n+=1
  if Y>=18:
    m+=1
  if Y> 75:
    i +=1
  Y = int(input())
media = soma/n
porc = (i/n)*100
print("{:.2f}".format(media))
print(m)
print("{:.2f}%".format(porc))
