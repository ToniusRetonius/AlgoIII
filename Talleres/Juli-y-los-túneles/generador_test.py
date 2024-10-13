# test de 200 000
n = 200000

# escribimos el archivo
with open('test_fuerte.txt', 'w') as txt:
    # 200000 aulas
    txt.write(f"{n}\n")

    # un numero al lado del otro
    for i in range(1,n):
        txt.write(f"{i} ")

