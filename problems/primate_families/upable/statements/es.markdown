# Descripción
La famosa primatóloga y antropóloga <a href="https://en.wikipedia.org/wiki/Jane_Goodall">Jane Goodall </a>se dirige a Tanzania para investigar el comportamiento de múltiples familias de chimpancés salvajes. En preparación para su llegada, sus colaboradores elaboraron un mapa que indica los lugares en los que se han observado chimpancés y la familia a la que pertenece cada uno de ellos.

El mapa consiste en una retícula cuadrada de $N$ filas por $N$ columnas donde cada celda está marcada con un punto ('.') si en ese lugar no se ha observado ningún chimpancé y con una letra del alfabeto inglés (entre 'A' y 'Z', inclusive) que indica que en ese lugar se ha observado exactamente un chimpancé y la letra indica la familia a la que pertenece dicho chimpancé. Por ejemplo, el siguiente mapa de 5 filas por 5 columnas indica la ubicación de 8 chimpancés, cada uno de los cuales pertenecen a una de las 3 familias asociadas a las letras 'B', 'C' y 'D':
<pre>
DB...
..C..
.DD..
..D..
B...C
</pre>
La Dra. Goodall necesita estudiar todas las familias de chimpancés reportadas en el mapa (al menos un chimpancé de cada familia).

Ayuda a la Dra. Goodall a encontrar una región cuadrada lo más pequeña posible dentro de la cual se haya observado al menos un chimpancé de cada familia reportada en el mapa para que pueda enfocar su expedición en dicha región.

# Entrada
En la primera línea el número $N$ de filas y columnas del mapa cuadrado. En cada una de las siguientes $N$ líneas, $N$ caracteres, donde un punto ('.') indica que en ese lugar no se ha observado ningùn chimpancé y una letra del alfabeto inglés (entre 'A' y 'Z', inclusive) que indica que en ese lugar se ha observado exactamente un chimpancé y la letra indica la familia a la que pertenece dicho chimpancé (nota que existen a lo mas 26 familias de chimpancés, cada una asociada a una letra del alfabeto inglés). 

# Salida
Un entero $S$ que indica que la región cuadrada más pequeña en la que se ha observado al menos un chimpancé de cada familia es de $S \times S$.

# Ejemplo

||input
5
DB...
..C..
.DD..
..D..
B...C

||output
3
||description
El ejemplo presentado en la descripción del problema. La región cuadrada más pequeña en la que se ha observado al menos un chimpancé de cada familia es de $3 \times 3$.
||end

# Límites

* $1 &leq; N &leq; 500$


