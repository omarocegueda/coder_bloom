# Descripción
Uno de los pasatiempos favoritos de Cupido es andar por ahí disparando flechas doradas para hacer que las personas se enamoren de la primera persona que ven luego de ser flechadas. Cupido quiere disparar una última flecha antes de ir a descansar. Para tratar de minimizar el tiempo que tardará su víctima en enamorarse a primera vista, la estrategia de Cupido consiste  en buscar al par de personas más cercanas y flechar a una de ellas.

Dados dos puntos $A=(x_1, y_1)$, $B=(x_2, y_2)$, su distancia está dada por:

$D(A, B)=|x_2-x_1|+|y_2-y_1|$

Dado la ubicación de $N$ personas, ayuda a Cupido a encontrar al par de personas más cercanas. 


# Entrada
En la primera línea, el número $N$ de personas. En cada una de las siguientes $N$ líneas, dos enteros separados por espacio que representan ubicación $(x_i, y_i)$ de la $i$-ésima persona.

# Salida
La distancia entre las dos personas más cercanas. 

# Ejemplo

||input
5
-5 -4
5 -1
-7 -5
7 6
4 4
||output
3
||description
Los puntos mas cercanos son:

* $(-5, -4)$ 
* $(-7 -5)$

La distancia entre ellos es:

$|-7 - (-5)| + |-5 - (-4)| = 2 + 1 = 3$
||end

# Límites
* $2 \le N \le 30,000$
* $-1,000,000,000,000 \le x_i, y_i \le 1,000,000,000,000$

