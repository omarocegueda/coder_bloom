# Descripción
El equipo nacional de nado sincronizado está realizando audiciones para seleccionar a las atletas que participarán en el Campeonato Acuático Mundial de Fukuoka, 2023. Para evaluar el desempeño de las candidatas, cuentan con un sistema automatizado que registra la secuencia de movimientos realizados por cada una de las candidatas durante la rutina. Cada una de las candidatas sabe ejecutar 26 movimientos distintos identificados por las letras mayúsculas del alfabeto inglés ‘A’, ‘B’, …, ‘Z’. Una rutina está compuesta de $T$ movimientos. Esto significa que la secuencia de movimientos que cada candidata ejecutó durante la rutina se puede describir usando una cadena de texto de $T$ letras de longitud.

Hay $N$ candidatas luchando por un puesto en el equipo nacional. Dada la secuencia de movimientos de un subconjunto de $k$ candidatas, definimos su “sincronía” como $k \times L$ donde L es el máximo número de movimientos consecutivos en que todas las $k$ candidatas realizaron el mismo tipo de movimiento. Escribe un programa que dada la secuencia de movimientos de todas las $N$ candidatas, encuentre el subconjunto más grande de candidatas con máxima sincronía.


# Entrada
En la primera línea, dos enteros $N$ y $T$ que indica el número total de candidatas luchando por un puesto en el equipo nacional y el número de movimientos en la rutina de nado sincronizado. En cada una de las siguientes $N$ líneas, una cadena de texto de $T$ letras del alfabeto inglés describiendo los movimientos que realizó la candidata correspondiente. 

# Salida
En la primera línea dos enteros $S$, $M$ que indican la máxima sincronía y el máximo número de atletas que maximizan dicha sincronía, respectivamente.

# Ejemplo

||input
5 7
ABCYABX
BCABCDF
ABCYABW
XYABCDE
IJABCDG

||output
12 3
||description
Hay 5 candidatas a formar parte del equipo nacional de nado sincronizado. La rutina está compuesta de 7 movimientos.
La máxima sincronía la alcanzaron dos subconjuntos de candidatas:
Las candidatas 1 y 3 realizaron los mismos movimientos en los primeros 6 movimientos de la rutina: [ABCYAB] para una sincronía de $2 \times 6 = 12$
Las candidatas 2, 4, y 5 realizaron los mismos movimientos durante los movimientos 3 al 6 de la rutina: [ABCD] para una sincronía de $3 \times 4 = 12$
Nos interesa encontrar el subconjunto más grande de candidatas que alcanza la máxima sincronía, por lo que la solución se obtiene al seleccionar a las candidatas 2, 4, y 5.
||end

# Límites
*  $1 \le N \le 15$
*  $1 \le T \le 100$


