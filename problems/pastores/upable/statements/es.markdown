# Descripción
Cada año, los pastores, a Belén, corren presurosos y llevan, de tanto correr, los zapatos rotos. Este año, los pastores decidieron que no tiene sentido comenzar el viaje a Belén si al final tendrán que abandonar su peregrinación al romperse sus zapatos, así que decidieron organizarse mejor: solamente $K$ de los $N$ pastorcillos emprenderá el viaje equipados con sus propios zapatos y algunos pares extra en su morral, cedidos por algunos de los otros $N-K$ pastorcillos que no realizarán la peregrinación. Al romperse sus zapatos durante el viaje, cada pastorcillo reemplazará sus zapatos con algunos de los zapatos de su morral y desechará los rotos.

Cada par de zapatos resiste $R$ kilómetros de caminata y el camino a Belén mide $B$ kilómetros. ¿Cuál es el máximo número $K$ de pastorcillos que pueden llegar a Belén?


# Entrada
En la primera línea, tres números $N$, $R$ y $B$, separados por espacio, indicando el número de pastorcillos, el número de kilómetros que resiste cada par de zapatos y la distancia a Belén, respectivamente.

# Salida
En la primera línea, el máximo número $K$ de pastorcillos que pueden llegar a Belén.

# Ejemplo

||input
20 5 10
||output
10
||description
Hay 20 pastores, cada par de zapatos resiste 5 kilómetros de caminata y el camino a Belén mide 10 kilómetros. Cada pastor requiere al menos dos pares de zapatos para llegar a Belén, por lo que, a lo más, 10 de los 20 pastorcillos llegarán a Belén. Los otros 10 cederán sus zapatos para que los demás puedan llegar.

||input
10 49 100
||output
3
||description
Hay 10 pastorcillos, cada par de zapatos resiste 49 kilómetros de caminata y el camino a Belén mide 100 kilómetros. Cada pastor requiere 3 pares de zapatos para llegar a Belén, por lo que, a lo más, 3 de los 10 pastorcillos llegarán a Belén. 
||end

# Límites

* $1 \le  N, R, B \le 1,000,000,000$


