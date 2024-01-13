# Descripción
[Aída Román](https://es.wikipedia.org/wiki/A%C3%ADda_Rom%C3%A1n), medallista olímpica Mexicana en tiro con arco, está entrenando para el próximo campeonato mundial de tiro con arco. Una sesión de entrenamiento consiste en disparar $M$ flechas hacia un diana marcada con $N$ anillos de radios $R_1, R_2, …, R_N$, que tienen asignadas puntuaciones de $P_1, P_2, …, P_N$ puntos respectivamente. Cada flecha disparada recibe el número de puntos correspondiente al anillo más pequeño que la contiene estrictamente (si la flecha cae exactamente sobre un anillo, ese anillo no la contiene estrictamente). Si ningún anillo contiene estrictamente a la flecha, entonces esa flecha recibe cero puntos.

Escribe un programa que dada la descripción de la diana y la posición en la que cayó cada flecha, calcule el total de puntos obtenidos por las $M$ flechas.



# Entrada
En la primera línea el número $N$ de anillos que tiene la diana. En cada una de las siguientes $N$ líneas, dos enteros $R_i, P_i$ que indican el radio y el número de puntos correspondientes al i-ésimo anillo. En la siguiente línea el número $M$ de flechas disparadas. En cada una de las siguientes $M$ líneas dos enteros $X_i, Y_i$ que indican la posición en la que cayó la i-ésima flecha. El centro de la diana es $(0, 0)$.

# Salida
En la primera línea el total de puntos obtenidos.

# Ejemplo

||input
6
10 10
20 9
30 8
40 7
50 6
60 5
3
60 0
0 -9
14 14
||output
19
||description
La diana tiene $N=6$ anillos. Aída disparó $M=3$ flechas, cuyos puntajes fueron 0, 10, 9, respectivamente, para un total de 19 puntos.
||input
3
30 10
10 2
20 5
3
15 12
1 2
25 30
||output
7
||description
Esta diana es muy peculiar: los anillos más pequeños no necesariamente dan más puntos. La primera flecha cayó dentro del anillo de radio 20 obteniendo 5 puntos. La segunda flecha cayó dentro del anillo de radio 10 obteniendo 2 puntos.
La tercera flecha no cayó dentro de ningún anillo. El puntaje total fue 5+2=7. 
||end

# Límites
*  $1 \le N, M \le 100,000$
*  $1 \le R_i, P_i \le 10^6$ y se garantiza que $R_i \neq R_j$ para todo $i\neq j$ (es decir, no habrá radios repetidos)
*  $-10^6 \le X_i, Y_i \le 10^6$


