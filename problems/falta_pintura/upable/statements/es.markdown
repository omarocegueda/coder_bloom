# Descripción
WALL-E (el robot) acaba de detectar que las líneas de división de la carretera que recorre todos los días ya están muy desgastadas y casi no se ven, así que se dispone a pintarlas pacientemente. La carretera mide $N$ kilómetros y WALL-E tiene $N$ botes de pintura amontonados al inicio de la carretera, cada bote tiene suficiente pintura para pintar las líneas de un kilómetro de carretera.
WALL-E solo puede cargar un bote de pintura a la vez, así que inicia tomando un bote de pintura, pinta el primer kilómetro y regresa al inicio de la carretera por otro bote de pintura, regresa hasta la posición donde se le terminó la pintura anteriormente y pinta el siguiente kilómetro usando el nuevo bote de pintura. Luego regresa al inicio de la carretera por otro bote de pintura y así sucesivamente hasta terminar de pintar los $N$ kilómetros. 
¿Cuántos kilómetros tuvo que recorrer WALL-E para pintar los $N$ kilómetros de carretera?

# Entrada
En la primera un entero no negativo $N$ indicando el número de kilómetros de la carretera. 

# Salida
En la primera línea un único entero no negativo indicando el número de kilómetros que tuvo que recorrer WALL-E para pintar los $N$ kilómetros de carretera.
# Ejemplo

||input
3
||output
9
||description
El proceso fue el siguiente:

1. Tomar un bote de pintura y pintar el primer kilómetro (total=1km).
2. Regresar al inicio de la carretera (total=2km)
3. Tomar otro bote de pintura y avanzar 1km para llegar hasta donde se había quedado (total=3km).
4. Pintar 1km de carretera usando el nuevo bote de pintura (total=4km)
5. Regresar al inicio de la carretera (total=6km)
6. Tomar otro bote de pintura y avanzar 2km para llegar hasta donde se había quedado (total=8km).
7. Pintar 1km de carretera usando el nuevo bote de pintura (total=9km)
||end

# Límites
* $0 &leq; N &leq; 1,000,000,000$
