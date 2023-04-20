# Descripción
Definimos el “triángulo de Sierpinski” de tamaño $3$ como un triángulo formado por 3 bloques negros en la base y un bloque negro centrado sobre los tres bloques que forman la base. El triángulo de Sierpinski de base $N=7$ se construye comenzando con un triángulo de base $7$, lo dividimos en 4 sub-triángulos de base $3$, pintamos el triángulo (invertido) del centro de blanco y los 3 triángulos de alrededor los pintamos como triángulos de Sierpinski de tamaño $\frac{N-1}{2}$ (que en este caso son simplemente triángulos negros de base $3$). Podemos repetir este proceso para todas las bases de la forma $2^k - 1$, donde $k>1$ : $3, 7, 15, 31, 63, …$ Simplemente comenzamos con un triángulo de base $N=2^k - 1$, lo dividimos en $4$ triángulos de base $2^{k-1} -1$, es decir, en $4$ triángulos con $N’=\frac{N-1}{2}$, pintamos el triángulo del centro de blanco, y luego pintamos los $3$ triángulos de alrededor como triángulos de Sierpinski de base $N’$. En la figura se muestran los primeros 3 triángulos de Sierpinski: de base $3, 7$ y $15$:

![](fig.jpg)

Escribe un programa que dado el valor de $N$, construya el triángulo de Sierpinski de base $N$.

# Entrada
En la primera línea un entero positivo $N$ que indica el tamaño de la base del triángulo de Sierpinski.
# Salida
Imprime el triángulo de Sierpinski de base $N$ donde los bloques blancos están representados por puntos (‘.’) y los bloques negros están representados por la letra X (‘X’). Se garantiza que $N$ es de la forma $2^k - 1$, donde $k>1$

# Ejemplo

||input
15
||output
       X
      XXX
     X...X
    XXX.XXX
   X.......X
  XXX.....XXX
 X...X...X...X
XXX.XXX.XXX.XXX
||description
El ejemplo en la descripción del problema.
||end

# Límites
* $3 \leq N \leq 511$ (se garantiza que $N$ es de la forma $2^k - 1$, donde $k>1$.)


