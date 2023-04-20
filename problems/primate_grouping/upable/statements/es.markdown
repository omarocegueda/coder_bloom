# Descripción
La famosa primatóloga y antropóloga Jane Goodall se dirige a Tanzania para observar el comportamiento de chimpancés salvajes. En preparación para su llegada, sus colaboradores elaboraron un mapa que indica los lugares donde habitan los chimpancés que la Dra. Goodall puede observar durante su expedición. 
El mapa consiste en una retícula rectangular de $N$ filas por $M$  columnas donde cada celda está marcada con una letra ‘C’ si en ese lugar habita un chimpancé y con un punto (‘.’) si en ese lugar no habita ningún chimpancé. 
Al analizar el mapa, la Dra. Goodall notó que algunos chimpancés parecen formar grupos a los que llamó "familias de chimpancés". Dos chimpancés pertenecen a la misma familia si su ubicación aparece en celdas adyacentes en el mapa (es decir, una de ellas está inmediatamente a la izquierda, derecha, arriba o abajo de la otra). Por ejemplo, el siguiente mapa de 8 filas por 10 columnas indica la ubicación de 21 chimpancés formando 6 grupos de tamaño 1, 1, 1, 1, 5 y 12, respectivamente:
<pre>
.....C....
....CCC...
.....C....
..C....C..
...CCCC...
...CCCC...
...CCCC...
..C....C..
</pre>
Ayuda a la Dra. Goodall a encontrar el tamaño de la familia más numerosa de chimpancés.


# Entrada
En la primera línea el número $N$ de filas y $M$ de columnas del mapa. En cada una de las siguientes  líneas,  $M$ caracteres indicando si en esa posición habita un chimpancé o no.

# Salida

El tamaño de la familia más numerosa de chimpancés.

# Ejemplo

||input
8 10
.....C....
....CCC...
.....C....
..C....C..
...CCCC...
...CCCC...
...CCCC...
..C....C..
||output
12
||description
En este ejemplo, existen 6 familias de tamaño 1, 1, 1, 1, 5 y 12, respectivamente.
||end

# Límites

* $1 \leq N \leq 100$
* $1 \leq M \leq 100$
