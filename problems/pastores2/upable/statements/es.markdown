# Descripción
Cada año, los pastores, a Belén, corren presurosos y llevan, de tanto correr, los zapatos rotos. Este año, los pastores decidieron que no tiene sentido comenzar el viaje a Belén si al final tendrán que abandonar su peregrinación al romperse sus zapatos, así que decidieron organizarse mejor. Cada pastorcillo comenzará su viaje usando sus propios zapatos y llevará en su morral algunos pares de zapatos extras cedidos por los pastorcillos que no viajarán. Durante su caminata, cada pastor puede dejar en el camino cualquier conjunto de pares de zapatos, sin importar el número de kilómetros de vida que les queden. Así, algún otro pastor podrá usarlos mientras duren. Cada par de zapatos resiste $R$ kilómetros de caminata y el camino a Belén mide $B$ kilómetros. ¿Cuál es el máximo número $K$ de pastorcillos que pueden llegar a Belén?


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
4
||description
Hay 10 pastorcillos, cada par de zapatos resiste 49 kilómetros de caminata y el camino a Belén mide 100 kilómetros. Los pastores pueden iniciar con cualquier cantidad de pares de zapatos, pueden cambiarse de zapatos cualquier cantidad de veces y pueden dejar en el camino, cualquier cantidad de pares de zapatos para que los pastores siguientes los utilicen. 
||end

# Límites

* $1 \le  N, R, B \le 1,000,000,000$


