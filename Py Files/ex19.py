# ENTRADA:
idade = int(input())

# PROCESSAMENTO:
if idade <16:
  res = "DISPENSADO"
else:
  if idade <18:
    res = "FACULTATIVO"
  else:
    if idade < 70:
      res = "OBRIGATORIO"
    else:
      res = "DISPENSADO"
# SAIDA:
print (res)