# ENTRADA:
L = float(input())
A = float(input())
C = float(input())
M = float(input())

# PROCESSAMENTO:
AREA = L*A
QL = AREA/M
if QL%1 != 0:
  QL = int(QL + 1)
else:
  QL = int(QL)
PREÇO = QL * C
# SAIDA:
print(QL)
print("{:.2f}".format(PREÇO))
