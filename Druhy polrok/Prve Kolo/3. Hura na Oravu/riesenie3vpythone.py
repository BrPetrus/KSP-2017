# Instrukcia
instrukcia = str(input())

# Premenne
sucet = 0
base = 0
nHviezdiciek = 0
rad = 0

for i in reversed(instrukcia):
    if i == 'P':
        base += 1 << rad
    elif i == '*':
        sucet += 1 << rad
        nHviezdiciek += 1
    rad += 1

min = 2**len(instrukcia)
odpoved = (min+base)*(2**nHviezdiciek)
if nHviezdiciek > 0:
    odpoved += sucet*(2**(nHviezdiciek-1))
print(odpoved % 1000000007)