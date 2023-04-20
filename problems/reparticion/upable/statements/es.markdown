# Descripción
Es navidad y todos aún duermen en casa, excepto el pequeño Grinch, quien sigilosamente se levantó muy temprano a ver los regalos. La mente del pequeño trabaja rápido y al ver los regalos de sus mamás, se le ocurrió intercambiarlos de tal forma que cada una reciba los regalos que <b>menos</b> le gusten. Las mamás del Grinch recibieron $N$ regalos cada una, y el Grinch asignó un par de puntajes $(a_i, b_i)$ a cada regalo indicando cuánto le gustaría a cada mamá recibir ese regalo. Ayuda al pequeño Grinch a ejecutar su travesura asignando $N$ regalos a cada mamá de tal forma que la suma de los respectivos puntajes sea <b>mínima</b>.

# Entrada
En la primera línea un número $N$ indicando el número de regalos que recibió cada mamá.
En cada una de las siguientes $2 N$ líneas, dos enteros positivos $(a_i, b_i)$ indicando cuánto le gustaría a cada mamá recibir ese regalo.

# Salida
En la primera línea, la mínima suma de puntajes que el pequeño Grinch puede lograr asignando $N$ regalos a cada mamá.

# Ejemplo

||input
1
1 2
2 1
||output
2
||description
Hay solamente 2 regalos, la primera mamá prefiere el regalo 2 y la segunda mamá prefiere el regalo 1, así que el pequeño Grinch asignará el primer regalo a la primera mamá, y el segundo regalo a la segunda mamá, para un total de 1+1=2.
||input
3
1 10
2 8
3 7
7 4
8 5
10 2

||output
17
||description
Cada mamá recibió 3 regalos. El pequeño Grinch puede asignar los primeros 3 regalos a la primera mamá obteniendo los puntajes {1,2,3} y los siguientes 3 regalos a la segunda mamá, obteniendo los puntajes {4,5,2}, para un total de 6+11=17.

||input
3
1 10
2 8
3 2
7 7
8 3
10 1

||output
16
||description 
El pequeño grinch puede asignar los regalos 1, 2 y 4 a la primera mamá obteniendo los puntajes {1, 2, 7} y los regalos 3, 5 y 6 a la segunda mamá, obteniendo los puntajes {2, 3, 1}, para un total de 10+6=16.
||end

# Límites

* $1 \le N \le 1000$
* $1 \le a_i, b_i \le 10,000$



