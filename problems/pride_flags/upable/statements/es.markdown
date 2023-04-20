# Descripción
<center>![](fig.jpg)</center>

Los organizadores del desfile del orgullo LGBTQ+ necesitan imprimir banderas para distribuirlas entre los asistentes al desfile. Para esto, cuentan con una máquina con dos componentes configurables: (1) Un rodillo giratorio con los $C$ colores de la bandera y (2) una banda circular que se puede configurar para colocar $M$ mantas. Al activar la máquina, ésta imprime una franja del color 1 sobre la manta número 1 y luego tanto el rodillo como la banda avanzan imprimiendo una franja del siguiente color sobre la siguiente manta. Tanto el rodillo como la banda avanzan simultáneamente. Cuando el rodillo alcanza el color $C$, regresa al color $1$ y cuando la banda alcanza la manta número $M$, regresa a la manta número $1$. Este proceso se repite exactamente $C \times M$ veces.

Por ejemplo, supongamos que el número de colores es $C=2$ y configuramos la banda para $M=3$ mantas. En cada movimiento, el rodillo alternará los dos colores. En el primer ciclo de la banda, las mantas tendrán los colores {{1}, {2}, {1}}. Luego, el rodillo comenzará con el color 2 sobre la banda 1, así que al final del siguiente ciclo, cada manta tendrá una franja de cada uno de los dos colores.

Si la máquina no se configura correctamente, es posible que las mantas no contengan todos los colores. Por ejemplo, en el caso anterior, si en lugar de configurar la banda para 3 mantas la configuramos para 4 mantas, entonces, al final del primer ciclo las mantas tendrán los colores {{1}, {2}, {1}, {2}}, y luego el rodillo regresará al color 1 sobre la manta 1, volviendo a imprimir el mismo color en cada manta.

Los organizadores del desfile necesitan imprimir al menos $N$ banderas, cada una con todos los $C$ colores. Ayuda a los organizadores a encontrar el mínimo número de mantas $M$ con las que deben configurar la máquina para asegurar que cada manta tendrá todos los $C$ colores de la bandera del orgullo LGBTQ+.

# Entrada
En la primera línea, dos enteros $C$, $N$ separados por un espacio, indicando el número de colores de la bandera y el mínimo número de banderas que necesitamos imprimir. 

# Salida
En la primera línea, el mínimo número $M$, donde $M >= N$ de mantas con las que debemos configurar la máquina para obtener al menos $N$ banderas todas con los $C$ colores.

# Ejemplo

||input
2 3
||output
3
||description
El ejemplo en la descripción del problema
||input
2 4
||output
5
||description
Si usamos 4 mantas, dos de ellas tendrán solo el color 1 y dos de ellas tendrán solo el color 2. Usando 5 mantas todas ellas tendrán los 2 colores.
||input
15 20
||output
22
||description
Necesitamos usar al menos 22 mantas para que todas ellas tengan los 15 colores.
||end

# Límites
* $1 \leq C, N \leq 10,000,000$.

