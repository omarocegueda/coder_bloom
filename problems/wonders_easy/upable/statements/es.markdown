# Descripción
Las <A href="https://en.wikipedia.org/wiki/New_7_Wonders_of_the_World">7 nuevas maravillas del mundo</A> fueron elegidas en 2007 luego de una votación en línea en la que participaron millones de personas. Si inicialmente había $N$ monumentos candidatos a formar parte de las nuevas maravillas y al final sólo $M$ de ellos serían elegidos, ¿Cuáles serían todos los posibles resultados?

# Entrada
En la primera línea dos enteros positivos, $N$ y $M$, separados por un espacio.
En las siguientes $N$ líneas, el nombre de cada uno de los monumentos candidatos. 


# Salida
Escribe todos los posibles resultados, cada uno en una linea. Cada resultado es una lista de  $M$candidatos separados por espacio. No importa el orden en el que imprimas los candidatos de cada resultado ni el orden en el que imprimas los posibles resultados. 

# Ejemplo
`Advertencia: es posible que omegaUp reporte como incorrecto el resultado de los siguientes ejemplos sólo porque el orden es diferente, pero para la evaluación final no importará el orden.`
||input
2 1
Coliseo
Petra
||output
Coliseo
Petra
||description
Sólo podemos elegir a un candidato. Hay dos posibilidades.
`Para la evaluación final, no importará el orden en el que imprimas los resultados.`

||input
4 2
ChichenItza
MachuPicchu
MurallaChina
TajMahal
||output
ChichenItza MachuPicchu 
ChichenItza MurallaChina
ChichenItza TajMahal
MachuPicchu MurallaChina
MachuPicchu TajMahal
MurallaChina TajMahal
 

||description
Debemos elegir a dos de los cuatro candidatos. Hay 6 posibles resultados. `Para la evaluación final, no importará el orden en el que imprimas los resultados.`
||end

# Límites
* $1 \leq M \leq N \leq 15$.
* Cada nombre tendrá al menos un caracter y a lo más 20 caracteres
* Los caracteres son los del alfabeto inglés (cada caracter está entre ‘A’ y ‘Z’ o entre ‘a’ y ‘z’)


