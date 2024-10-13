# test de 200 000
n = 200000

# escribimos el archivo
with open('test_fuerte.txt', 'w') as f:
    # 200000 aulas
    f.write(f"{n}\n")

    # un numero al lado del otro
    for i in range(1,n):
        f.write(f"{i} ")