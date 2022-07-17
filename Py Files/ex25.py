A = int(input())
B = int(input())
C = int(input())

if A+B<C or A+C<B or B+C<A:
  res = "INVALIDO"
else:
  if A==B and B==C:
    res = "EQUILATERO"
  else:
    if A==B or B==C or A==C:
      res = "ISOSCELES"
    else:
      res = "ESCALENO"

print(res)