# Descripción
Inspirado en: Age of Empires II

Un ataque sorpresa de soldados Mongoles causó pánico en la ciudad principal de la civilización China. Al no contar con ejército para defenderse, un grupo de aldeanos Chinos construyeron una muralla formando un triángulo a su alrededor. Al notar su propia superioridad, los Mongoles se retiraron, dejando solamente un paladín (soldado a caballo) para hacerse cargo del resto de los aldeanos Chinos. Tristemente, la ejecución en la construcción de la muralla de los Chinos fue un desastre, algunos aldeanos quedaron dentro y algunos quedaron fuera de la región amurallada.

Dada la descripción de la muralla y la ubicación de los aldeanos Chinos y la del paladín Mongol, ¿Cuántos aldeanos Chinos están protegidos por la muralla contra el paladín?



# Entrada
En las primeras tres líneas, tres pares de enteros que indican las coordenadas $(P_x, P_y), (Q_x, Q_y), (R_x, R_y)$ de los tres vértices, no colineales, $P, Q, R$ de la muralla, respectivamente. En la siguiente línea, dos enteros $S_x, S_y$ que indican la ubicación $S$ del soldado Mongol. En la siguiente línea, el número $N$ de aldeanos Chinos. En cada una de las siguientes $N$ líneas, dos enteros enteros que indican la ubicación $(x_i, y_i)$ del $i$-ésimo aldeano Chino.

Se garantiza que cada aldeano Chino estará ya sea estrictamente dentro o estrictamente fuera de la región amurallada (es decir, ninguno de ellos estará sobre la muralla). De igual forma, se garantiza que el soldado Mongol estará estrictamente dentro o estrictamente fuera de región amurallada.

Se garantiza que todos los puntos $P, Q, R, S$ y $(x_i, y_i)$ son distintos entre sí.


# Salida
En la primera línea, el número de aldeanos Chinos protegidos por la muralla en contra del paladín Mongol.

# Ejemplo

||input
0 0
0 10
10 0
10 10
2
1 1
2 2
||output
2
||description
Hay solamente dos aldeanos. Afortunadamente, la muralla protege a ambos del soldado Mongól.

||input
0 0
0 10
10 0
10 10
2
1 1
-1 -1
||output
1
||description
Hay solamente dos aldeanos. Desafortunadamente, uno de los aldeanos está fuera de la región amurallada. Es solo cuestión de tiempo para que el paladín alcance al desafortunado aldeano que quedó desprotegido.
||end

# Límites
* $1 \le N \le 100$
* $-1000 \le P_x, P_y, Q_x, Q_y, R_x, R_y, S_x, S_y, x_i, y_i \le 1000$


