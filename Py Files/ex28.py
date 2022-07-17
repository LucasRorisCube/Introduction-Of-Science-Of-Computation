X1 = int(input())
V1 = int(input())
X2 = int(input())
V2 = int(input())

tempo = 0
if V2-V1==0:
  if X1 == X2:
    res = "SIM"
  else:
    res = "NAO"
else:
  tempo = (X1-X2)/(V2-V1)
  if tempo < 0:
    res = "NAO"
  else:
    if tempo == int(tempo):
      res = "SIM"
    else:
      res = "NAO"

print (res)
