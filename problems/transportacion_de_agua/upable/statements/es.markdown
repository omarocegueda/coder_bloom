# Descripción
Tenemos una fila de $N$ contenedores numerados del $1$ al $N$ de izquierda a derecha. El $i$-ésimo contenedor tiene una capacidad de $C_i$ litros e inicialmente contiene $A_i$ litros de agua, $0 \leq A_i \leq C_i$. En cada movimiento puedes elegir un contenedor $k$ y vaciar todo su contenido en sólo uno de sus contenedores adyacentes, ya sea $k-1$ ó $k+1$. El agua excedente después de llenar el contenedor se derramará, así que no podrá utilizarse después para llenar otros contenedores. Nos interesa concentrar la máxima cantidad de agua en uno solo de los contenedores.

# Entrada
En la primera línea el número $N$ de contenedores. En la segunda línea, $N$ enteros $\lbrace C_i\rbrace$ separados por espacio indicando la capacidad de cada contenedor. En la tercera línea, $N$ enteros $\lbrace A_i \rbrace$ separados por espacio indicando la cantidad de agua que tiene cada contenedor inicialmente. 
# Salida

Un único entero indicando la máxima cantidad de agua que podemos concentrar en uno solo de los $N$ contenedores.

# Ejemplo

||input
5
9 1 1 1 8
3 1 0 1 4

||output
7
||description
Podemos concentrar 7 litros de agua en el último contenedor (el cual tiene capacidad para 8 litros). El primer contenedor tiene 3 litros, pero solo un litro de ellos llegará al último contenedor debido a que los contenedores intermedios sólo tienen capacidad para un litro, por lo que 2 litros se derramarán en el proceso :'(
||input
7
8 1 1 9 2 2 7
4 0 0 5 0 0 6

||output
8
||description
Podemos concentrar 8 litros de agua en el contenedor central (el cual tiene capacidad para 9 litros). De los 4 litros del primer contenedor, solamente 1 llegará al contenedor central debido a que los contenedores 2 y 3 sólo tienen capacidad para 1 litro. De los 6  litros del último contenedor, solamente 2 llegarán al contenedor central debido a que los contenedores 5 y 6 sólo tienen capacidad para 2 litros.
||end

# Límites
* $1 \leq N \leq 10,000$
* $0 \leq C_i \leq 1,000,000$
* $0\leq A_i \leq C_i$
