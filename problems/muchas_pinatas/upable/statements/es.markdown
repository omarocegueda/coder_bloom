# Descripción
La mamá de Federico (“Kiko”, para sus amigos) le organizó una fiesta de cumpleaños con muchas piñatas (¡el número de piñatas es igual al número de niños en la fiesta!), cada una de las cuales se rompe al darle exactamente $G$ golpes. Durante la fiesta, a Federico se le ocurrió formar una fila para turnarse a pegarle a las piñatas (el primer niño de la fila ocupa la posición 1, el segundo la posición 2, y así sucesivamente). En cada turno, cada niño le puede pegar a la piñata una sola vez y luego se vuelve a formar al final de la fila. Todos los $N$ niños quieren ser quien rompa la piñata porque entonces estarán ubicados en la mejor posición para recoger los dulces.
Al ver la posición $K$ de Kiko en la fila, su mamá se preocupó: ¿habrá suficientes piñatas para que "su Tesoro" rompa al menos una?


# Entrada
En la primera línea, tres enteros separados por espacio: el número  $N$ de niños en la fiesta (igual al número de piñatas), la cantidad $G$ de golpes que requiere cada piñata para romperse y la posición $K$ de Kiko en la fila. 

# Salida
En la primera línea, la palabra “SI” si Kiko romperá al menos una piñata y la palabra “NO” si Kiko no romperá ninguna piñata.

# Ejemplo

||input
10 5 1
||output
NO
||description
Tramposamente, Kiko ocupó la primera posición en la fila de 10 niños. Cada piñata resiste 5 golpes, por lo que los niños en las posiciones 5 y 10 de la fila romperán 5 piñatas cada uno. El resto de los niños no romperá ninguna ='(.
||input
10 5 10
||output
SI
||description
Esta vez, Kiko ocupó la última posición de la fila, así que romperá la segunda piñata, luego la cuarta piñata, luego la sexta piñata, y así sucesivamente hasta haber roto las 10 piñatas.
||input
8 3 4
||output
SI
||description
¡Cada niño romperá una piñata!
||input
50 2 1
||output
NO
||description
Kiko no romperá ninguna de las 50 piñatas.
||end

# Límites
* $1 \leq N, G \leq 1,000,000,000,000$
* $1 \leq K \leq N$

