# Descripción
Canicas aleatorias es un juego de mesa para dos jugadores que consiste en un tablero circular con $N$ casillas numeradas del $1$ al $N$ y $C$ canicas. Antes de iniciar el juego, los jugadores eligen un número $k$ al azar y colocan las canicas, también al azar, sobre las casillas del tablero (cada casilla puede tener cero o más canicas). Luego el juego comienza: el primer jugador elige una casilla inicial $A$ y recolecta todas las canicas de esa casilla, luego avanza $k$ casillas en el sentido de las manecillas del reloj y recolecta todas las canicas de esa casilla y así sucesivamente hasta que regrese a su casilla original $A$. Luego es el turno del segundo jugador y procede de la misma manera eligiendo una casilla inicial $B$. El juego termina cuando ya no hay más canicas en el tablero. Al final del juego, gana el jugador que tenga la mayor cantidad de canicas.

<center>![](img1.jpg)</center>

En la figura se muestra un ejemplo de un tablero de N=14 casillas y F=19 canicas. Suponiendo que el número elegido fue $k=4$, el primer jugador puede ganar el juego eligiendo, por ejemplo, $A=7$ ya que de esa manera visitará las casillas 7, 11, 1, 5, 9, 13, 3, 7, en ese orden, recolectando 10 canicas. Lo mejor que el segundo jugador puede hacer es recolectar las otras 9 canicas eligiendo por ejemplo $B=14$, de esa manera visitará las casillas 14, 4, 8, 12, 2, 6, 10, 14.
Suponiendo que cada jugador intenta maximizar la cantidad de canicas que puede recolectar ¿cuántas canicas obtendrá cada jugador?


# Entrada
En la primera línea tres enteros positivos $N$, $C$ y $k$ que indican el número de casillas del tablero, el número de canicas y el número casillas que los jugadores avanzan en cada movimiento, respectivamente.
En la segunda línea, $C$ enteros positivos ${c_i}$ que indican el número de casilla en la que se encuentra cada canica.


# Salida
En la primera línea, dos enteros positivos $T_1$, $T_2$ separados por un espacio indicando el total de canicas que obtendrá el primer jugador y el segundo jugador respectivamente, suponiendo que ambos juegan de manera óptima.
# Ejemplo

||input
14 19 4
2 2 3 2 3 3 3 6 7 7 9 9 11 11 14 14 14 14 14
||output
10 9
||description
Este caso corresponde al ejemplo explicado en la descripción del problema.
||input
14 19 1
2 2 3 2 3 3 3 6 7 7 9 9 11 11 14 14 14 14 14
||output
19 0
||description
Haciendo movimientos de una sola casilla ($k$=1), el primer jugador puede recolectar todas las canicas en su primer turno!
||end

# Límites
* $1 &le; N &le; 1,000,000,000$
* $1 &le; k &le; 1,000,000,000$
* $0 &le; C &le; 1,000,000$
* $1 &le; c_i &le; N$

