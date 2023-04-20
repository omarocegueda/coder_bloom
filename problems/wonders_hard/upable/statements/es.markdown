# Descripción
Las <A href="https://en.wikipedia.org/wiki/New_7_Wonders_of_the_World">7 nuevas maravillas del mundo </A>fueron elegidas en 2007 luego de una votación en línea en la que participaron millones de personas. Si a cada uno de los $N$ monumentos iniciales le asignamos un número distinto entre 1 y $N$ y al final sólo $M$ de ellos serían elegidos, podemos enumerar todos los posibles resultados en orden lexicográfico ordenando primero los candidatos de cada resultado de menor a mayor. 

Más precisamente, supongamos que tenemos dos conjuntos distintos de números $A$, $B$ con el mismo número de elementos: $A=\lbrace a_1, a_2, …, a_n\rbrace$, $B=\lbrace b_1, b_2, …, b_n\rbrace$ donde cada conjunto está ordenado. Si el $i$-ésimo elemento es el primero en el que difieren (es decir, $a_i \neq b_i$) entonces decimos que $A \lt B$ si y sólo si $a_i \lt b_i$.

Por ejemplo si inicialmente había 5 candidatos de los cuales 3 serían elegidos, todos los posibles resultados en orden lexicográfico son los siguientes:

1. {1, 2, 3}
2. {1, 2, 4}
3. {1, 2, 5}
4. {1, 3, 4}
5. {1, 3, 5}
6. {1, 4, 5}
7. {2, 3, 4}
8. {2, 3, 5}
9. {2, 4, 5}
10. {3, 4, 5}

Escribe un programa que, dados $N$, $M$ y $k$ imprima el $k$-ésimo posible resultado en orden lexicográfico.

# Entrada
En la primera línea tres enteros positivos: $N$, $M$ y $k$.

# Salida
En la primera línea, los elementos del $k$-ésimo posible resultado, ordenados de menor a mayor, separados por espacio.

# Ejemplo

||input
2 1 2
||output
2
||description
Sólo podemos elegir a un candidato. Hay dos posibles resultados en orden lexicográfico: 

1. {1}
2. {2}

Nos piden imprimir el segundo de ellos.
||input
4 2 4
||output
2 3
||description
Debemos elegir a dos de los cuatro candidatos. Hay 6 posibles resultados en orden lexicográfico:

1. {1, 2}
2. {1, 3}
3. {1, 4}
4. {2, 3}
5. {2, 4}
6. {3, 4}

Nos piden imprimir el cuarto de ellos.
||input
5 3 9
||output
2 4 5
||description
El ejemplo en la descripción del problema. Nos piden imprimir el noveno posible resultado (ver la descripción del problema).
||end

# Límites
* $1 \leq M \leq N \leq 60$.
* $k$ siempre será un índice válido (entre 1 y el número total de posibles resultados, inclusive)


