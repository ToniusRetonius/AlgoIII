def main():
    ## inicio 
    cantidadDataset = int(input())
    for i in range(0, cantidadDataset):
        cantidadArboles, alturaArboles, costoSaltar =  input().split()
        ## i = alturas
        matrizArbol = [[0 for _ in range(int(cantidadArboles))] for _ in range(int(alturaArboles))]
        for j in range(0, int(cantidadArboles)):            
            ## j = cantidad arboles
            bellotasEnArbol = list(map(int, input().split()))

            for i in range(1, bellotasEnArbol[0] + 1):
                matrizArbol[bellotasEnArbol[i] - 1][j] += 1
    ## siempre que pensemos en la n-esima altura, tenemos que hacer (i-1)nivel. => matriz[0][0] es arbol 1 altura 1
    ## respecto a la imagen de ejemplo, esto siempre va a estar espejado.

        ## resuelvo la máxima cantidad de acorns para el i-ésimo dataset.
        print(matrizArbol)
        res = solveAcorn(int(cantidadArboles), int(alturaArboles), int(costoSaltar), matrizArbol, 0, int(alturaArboles) - 1)
        print(res)


def solveAcorn(cantidadArboles : int, alturaArboles : int, costoSaltar : int, acornsArbol, arbolActual : int, alturaActual : int):
    # quiero calcular la siguiente operación: comerActual + max{seguir por el actual, saltar a algún arbol que no sea el que estoy parado} donde comerActual es la cantidad de bellotas que hay en mi posición actual. 
    comerActual = int(acornsArbol[alturaActual][arbolActual])
    maxAcorns = 0

    # caso base: cuando llego a la base del arbol (no tengo más altura para subir).
    if alturaActual == 0:
        return comerActual

    for i in range(alturaActual - 1, 0):
        if(costoSaltar > i):
            """ if (costo de salto > altura actual (= i )): entra a la guarda de seguir por el mismo árbol """
            solveAcorn(cantidadArboles, alturaArboles, costoSaltar, acornsArbol, arbolActual, i - 1)

        else:
            for j in range(cantidadArboles):
                if arbolActual == j:
                    j += 1
                else:
                    maxAcorns += max(maxAcorns, 
                                ## recursión recorriendo los arboles que me quedan
                                solveAcorn(cantidadArboles, alturaArboles, costoSaltar, acornsArbol, j, alturaActual - costoSaltar), 
                                ## recursión bajando sobre mi arbol actual
                                solveAcorn(cantidadArboles, alturaArboles, costoSaltar, acornsArbol, j, alturaActual  - 1)
                                )
                    print(maxAcorns)
                    print(comerActual)

    
    return comerActual + maxAcorns

if __name__ == "__main__":
    main()
