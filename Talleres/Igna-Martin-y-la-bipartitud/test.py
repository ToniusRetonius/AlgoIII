# Generar un árbol lineal de 100000 nodos
n = 100000

# Abrir un archivo para escribir
with open('test_gigante.txt', 'w') as f:
    # Escribir el número de nodos
    f.write(f"{n}\n")
    
    # Escribir las aristas del árbol
    for i in range(1, n):
        f.write(f"{i} {i + 1}\n")