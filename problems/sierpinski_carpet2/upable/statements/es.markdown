# Descripción
Definimos la “alfombra de Sierpinski” de tamaño $1$ como un cuadrado de $1\times 1$ ($1$ fila por $1$ columna) de color blanco. La alfombra de Sierpinski de tamaño $N=3$ se construye comenzando con un cuadrado de $3\times 3$, pintamos el cuadrado del centro de negro y los 8 cuadrados de alrededor los pintamos como alfombras de Sierpinski de tamaño $\frac{N}{3}$ (que en este caso son simplemente cuadrados blancos de $1 \times 1$). Podemos repetir este proceso para todas las potencias de $3$: $1, 3, 9, 27, 81, …$ Simplemente comenzamos con un cuadrado de tamaño $N=3\times k$, lo dividimos en $9$ cuadrados de $k \times k$, es decir, en $9$ cuadrados con $N’=k$, pintamos el cuadrado del centro de negro, y luego pintamos los $8$ cuadrados de alrededor como alfombras de Sierpinski de tamaño $k\times k$. En la figura se muestran las alfombras de Sierpinski para las 3 primeras potencias de $3$: $1, 3, 9$.

![](fig.jpg)

Escribe un programa que dado el valor de $N$ (donde $N$ es una potencia de $3$), y una lista de $L$ coordenadas de cuadrados dentro de la alfombra de $N \times N$, determine el color de cada uno de los $L$ cuadrados correspondientes. 

# Entrada
En la primera línea, dos enteros positivos $N, L$ indicando el tamaño de la alfombra de Sierpinski y el número de cuadrados por consultar, respectivamente. En cada una de las siguientes $L$ líneas, dos enteros positivos $(f_i, c_i)$ indicando la fila y la columna del cuadrado del cual nos interesa conocer su color.

# Salida
Una sola línea con $L$ caracteres indicando el color de cada uno de los $L$ cuadrados solicitados. El $i$-ésimo caracter debe ser un punto (‘.’) si el color del $i$-ésimo cuadrado de la lista es blanco, y debe ser ‘X’ si es negro.

# Ejemplo

||input
9 4
1 1
2 2
3 5
4 4
||output
.X.X
||description
En la alfombra de Sierpinski de tamaño $N=9$ (como la del ejemplo), los siguientes son los colores de las $L=4$ coordenadas solicitadas:

* $(1,1) \rightarrow$ Blanco
* $(2,2) \rightarrow$ Negro
* $(3,5) \rightarrow$ Blanco
* $(4,4) \rightarrow$ Negro

||end

# Límites
* $1 \le N < 2^{62}$ (se garantiza que $N$ es una potencia de $3$)
* $1 \le L \le 1000$
* $1 <=f_i, c_i<=N$

