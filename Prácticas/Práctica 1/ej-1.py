## ejercicio 1

# tenemos que a partir de un conjunto, devolver un valor de verdad sobre si existe un subconjunto de este
# tal que sume el valor j

def suma_subconjuntos(C, i, j):
    if j == 0:
        return True
    elif j < 0 or i < 0:
        return False
    else:
        return suma_subconjuntos(C, i - 1, j) or suma_subconjuntos(C, i - 1, j - C[i])


def main():
    conjunto = [2, 4, 6, 8, 10]
    suma_objetivo = 10
    resultado = suma_subconjuntos(conjunto, len(conjunto) - 1, suma_objetivo)
    
    if resultado:
        print(f"Es posible obtener la suma {suma_objetivo} con los elementos del conjunto.")
    else:
        print(f"No es posible obtener la suma {suma_objetivo} con los elementos del conjunto.")


if __name__ == '__main__':
    main()



    
    