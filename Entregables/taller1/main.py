""" pasa perfecto el VJudge """
class Jugador:
    def __init__(self, nombre, ataque, defensa):
        self.nombre = nombre
        self.ataque = ataque
        self.defensa = defensa

class Equipo:
    def __init__(self, numero):
        self.jugadores = [None] * 10
        self.numero = numero

    def agregar_jugador(self, jugador):
        for i in range(len(self.jugadores)):
            if self.jugadores[i] is None:
                self.jugadores[i] = jugador
                return

    def swap(self, i, j):
        self.jugadores[i], self.jugadores[j] = self.jugadores[j], self.jugadores[i]

    def formacion(self):
        for i in range(9):
            for j in range(i + 1, 10):
                if self.jugadores[i].ataque < self.jugadores[j].ataque:
                    self.swap(i, j)
                elif self.jugadores[i].ataque == self.jugadores[j].ataque:
                    if self.jugadores[i].defensa > self.jugadores[j].defensa:
                        self.swap(i, j)
                    elif self.jugadores[i].defensa == self.jugadores[j].defensa:
                        if self.jugadores[i].nombre > self.jugadores[j].nombre:
                            self.swap(i, j)
        for i in range(4):
            for j in range(i + 1, 5):
                if self.jugadores[i].nombre > self.jugadores[j].nombre:
                    self.swap(i, j)
        for i in range(5, 9):
            for j in range(i + 1, 10):
                if self.jugadores[i].nombre > self.jugadores[j].nombre:
                    self.swap(i, j)

    def ataque(self):
        return [jugador.nombre for jugador in self.jugadores[:5]]

    def defensa(self):
        return [jugador.nombre for jugador in self.jugadores[5:]]

def alfabeticamente(lista):
    return sorted(lista)

def main():
    primera_linea = input()
    cant_equipos = int(primera_linea)
    caso = 1
    equipos = []

    for i in range(cant_equipos):
        equipos.append(Equipo(caso))
        for _ in range(10):
            datos_jugador = input().split()
            nombre = datos_jugador[0]
            ataque = int(datos_jugador[1])
            defensa = int(datos_jugador[2])
            jugador = Jugador(nombre, ataque, defensa)
            equipos[i].agregar_jugador(jugador)
            if _ == 9:
                caso += 1

    for equipo in equipos:
        equipo.formacion()
        ataque = alfabeticamente(equipo.ataque())
        defensa = alfabeticamente(equipo.defensa())
        print(f"Case {equipo.numero}:")
        print(f"({', '.join(ataque)})")
        print(f"({', '.join(defensa)})")

if __name__ == "__main__":
    main()
