# Descripción
A Ramón le encantan los tacos. Para celebrar su cumpleaños, se le ocurrió organizar una comida con todos sus amigos en alguna de las taquerías de la ciudad. Todas las taquerías son excelentes, así que Ramón pensó elegir la taquería más cercana a los asistentes, en el sentido de que la suma de las distancias de cada asistente a la taquería elegida sea mínima. Ramón cuenta con dos mapas. Cada mapa consiste en una retícula rectangular de $N$ filas por $M$ columnas. En el primer mapa, la ubicación de cada asistente está indicada con una letra ‘A’, y el resto de las celdas están marcadas con un punto (‘.’). En el segundo mapa, la ubicación de cada taquería está marcada con una letra ‘T’, y el resto de las celdas están marcadas con un punto (‘.’). Nota que es posible que existan taquerías con la misma ubicación de los asistentes. Por ejemplo, los siguientes mapas de 5 filas por 10 columnas indica la ubicación de 4 asistentes y tres taquerías:

<center>![](img1.png)</center>

La distancia entre dos puntos, digamos $A=(a, b)$ y $B=(c, d)$, es la suma de las distancias vertical y horizontal, es decir:

$Distancia(A, B) = |a-c| + |b-d|$

Ayuda a Ramón a seleccionar la taquería que minimiza la suma de las distancias a los asistentes.

# Entrada
En la primera línea el número $N$ de filas y $M$ de columnas de los mapas. En cada una de las siguientes $N$ líneas, $M$ caracteres indicando si en esa posición se ubica un asistente o no. En cada una de las siguientes $N$ líneas, $M$ caracteres indicando si en esa posición está ubicada una taquería o no.


En la primera línea el número $N$ de frutas.

# Salida
La suma de las distancias de los asistentes a la taquería seleccionada.

# Ejemplo

||input
5 10
.A........
......A...
...A..A...
..........
..........
.T........
....T.....
..........
..........
........T.
||output
11
||description
Hay 4 asistentes, ubicados en
(1, 2), (2, 7), (3,4), (3, 7). Podemos elegir entre tres posibles taquerías ubicadas en 
(1, 2), (2, 5), (5,9), respectivamente. 
Las distancias de cada taquería a cada uno de los 4 asistentes son:

* Taquería en (1, 2): [0, 6, 4, 7]. Total: 17.
* Taquería en (2, 5): [4, 2, 2, 3]. Total: 11.
* Taquería en (5, 9): [11, 5, 7, 4]. Total: 27.

La mejor opción es la taquería en (2, 5), para la que la suma de las distancias a los 4 asistentes es 11.


La mejor opción es la taquería en $(5, 4)$, para la que la suma de las distancias a los 4 asistentes es 11.
||end

# Límites

* $1 \le N \le 1000$
* $1 \le M \le 1000$
* En 10% de los casos habrá a lo más 10 taquerías
* En 10% de los casos habrá a lo más 10 asistentes
* En 10% de los casos habrá exactamente N*M taquerías


