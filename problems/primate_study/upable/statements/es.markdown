# Descripción
La famosa primatóloga y antropóloga <a href="https://en.wikipedia.org/wiki/Jane_Goodall">Jane Goodall </a>se dirige a Tanzania para investigar el comportamiento de múltiples familias de chimpancés salvajes. En preparación para su llegada, sus colaboradores elaboraron un mapa que indica la ubicación de las familias de chimpancés que la Dra. Goodall necesita investigar durante su expedición.

El mapa consiste en una retícula rectangular de $N$ filas por $M$ columnas donde cada celda está marcada con una letra ‘C’ si en ese lugar habita una familia de chimpancés y con un punto (‘.’) si en ese lugar no habita ninguna familia de chimpancés. Por ejemplo, el siguiente mapa de 5 filas por 10 columnas indica la ubicación de 4 familias de chimpancés:

    .C........
    .......C..
    ...C......
    ..........
    .....C....

Ayuda a la Dra. Goodall a contar el número de familias de chimpancés que estudiará durante su expedición.


# Entrada
En la primera línea el número $N$ de filas y $M$ de columnas del mapa. En cada una de las siguientes $N$ líneas, $M$ caracteres indicando si en esa posición habita una familia de chimpancés o no. 

# Salida
El número de familias de chimpancés que estudiará la Dra. Goodall durante su expedición.

# Ejemplo

||input
5 10
.C........
.......C..
...C......
..........
.....C....

||output
4
||description
Hay 4 familias de chimpancés en el mapa de 5 filas por 10 columnas.
||end

# Límites

* $1 &leq; N &leq; 100$
* $1 &leq; M &leq; 100$

