# Descripción
Definimos la “alfombra de Sierpinski” de tamaño $1$ como un cuadrado de $1\times 1$ ($1$ fila por $1$ columna) de color blanco. La alfombra de Sierpinski de tamaño $N=3$ se construye comenzando con un cuadrado de $3\times 3$, pintamos el cuadrado del centro de negro y los 8 cuadrados de alrededor los pintamos como alfombras de Sierpinski de tamaño $\frac{N}{3}$ (que en este caso son simplemente cuadrados blancos de $1 \times 1$). Podemos repetir este proceso para todas las potencias de $3$: $1, 3, 9, 27, 81, …$ Simplemente comenzamos con un cuadrado de tamaño $N=3\times k$, lo dividimos en $9$ cuadrados de $k \times k$, es decir, en $9$ cuadrados con $N’=k$, pintamos el cuadrado del centro de negro, y luego pintamos los $8$ cuadrados de alrededor como alfombras de Sierpinski de tamaño $k\times k$. En la figura se muestran las alfombras de Sierpinski para las 3 primeras potencias de $3$: $1, 3, 9$.

![](fig.jpg)

Escribe un programa que dado el valor de $N$ (donde $N$ es una potencia de $3$), construya la alfombra de Sierpinski de tamaño $N$.

# Entrada
En la primera línea, un entero positivo $N$ indicando el tamaño de la alfombra de Sierpinski.
# Salida
$N$ líneas con $N$ caracteres cada una, representando la alfombra de Sierpinski de tamaño $N$, donde los cuadrados blancos están representados por puntos (‘.’) y los cuadrados negros están representados por la letra X (‘X’).
# Ejemplo

||input
9
||output
.........
.X..X..X.
.........
...XXX...
.X.XXX.X.
...XXX...
.........
.X..X..X.
.........

||description
El ejemplo en la descripción del problema.
||end

# Límites
* $1 &le; N &le; 729$ (se garantiza que $N$ es una potencia de 3)

