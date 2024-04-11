""" entregable 4 """
def rEq(a, b):
    """ si las cadenas son iguales ::  """
    if a == b:
        return True

    """ caso base : comparo letra vs letra """
    if len(a) == 1 and len(b) == 1:
        if a == b:
            return True
        else:
            return False
    
    else:
        if len(a) % 2 == 0:  
            """ caso recursivo : si las mitades tienen la misma len, las parto a la mitad y entro en la recursión """
            m = len(a) // 2
            a1, a2 = a[:m], a[m:]
            b1, b2 = b[:m], b[m:]
            return ((rEq(a1, b2) and rEq(a2, b1)) or (rEq(a1, b1) and rEq(a2, b2)))

def main():
    a = input()
    b = input()
    
    r = rEq(a,b)
    if r == True:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
