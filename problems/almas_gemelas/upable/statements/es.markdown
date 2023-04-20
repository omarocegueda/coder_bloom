# Descripción
Los Dioses del Olimpo están celosos y preocupados por lo felices y poderosos que son los humanos. Para debilitarlos, Zeus decidió partir el alma de los humanos en dos mitades (que se conocen como almas gemelas), y enviar cada par de mitades a lados opuestos de una línea divisoria. Dada la ubicación $(x_1, y_1)$, $(x_2, y_2)$ de dos personas, sabemos que sus almas son gemelas si la línea que las une es perpendicular a la línea divisoria de Zeus y ambos puntos se encuentran a la misma distancia de dicha línea.

Por ejemplo, en la siguiente figura hay $N=7$ personas y la línea divisoria de Zeus está dada por la línea que une los puntos $(5, 5)$ y $(15, 15)$. En este caso hay 2 pares de almas gemelas.

<center>![](img1.jpg)</center>

Dada la ubicación de $N$ personas y la descripción de la línea divisoria de Zeus, encuentra el número de pares de personas cuyas almas son gemelas.
# Entrada
En la primera línea, el número $N$ de personas. En cada una de las siguientes $N$ líneas, dos enteros separados por espacio que representan ubicación $(x_i, y_i)$ de la $i$-ésima persona. <b>Se garantiza que las posiciones de las $N$ personas son distintas.</b> 
En la última línea, 4 enteros $a_0, b_0, a_1, b_1$ separados por espacios que definen la línea divisoria de Zeus: la línea que une los puntos $(a_0, b_0)$ y $(a_1, b_1)$.


# Salida
El número de pares de personas cuyas almas son gemelas.

# Ejemplo

||input
7
5 10
10 20
15 10
10 5
10 30
30 10
30 25
5 5 15 15
||output
2
||description
Éste es el ejemplo en la descripción del problema. Hay $N=7$ personas y la línea divisoria de Zeus está dada por la línea que une los puntos $(5, 5)$ y $(15, 15)$. En este caso hay 2 pares de almas gemelas.
||end

# Límites
* $2 \le N \le 30,000$
* $-1,000,000 \le x_i, y_i \le 1,000,000$
* $-1,000,000 \le a_0, b_0, a_1, b_1 \le 1,000,000$



