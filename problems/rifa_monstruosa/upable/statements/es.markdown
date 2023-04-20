# Descripción
Como parte de las actividades de Halloween del año pasado, la escuela de Lucy organizó una serie de rifas que consisten en lo siguiente. Cada niño recibió un boleto dependiendo de su disfraz: los niños que fueron disfrazados de vampiros entraron en la rifa de los vampiros, los que fueron disfrazados de monstruos de Frankenstein entraron en la rifa de los monstruos de Frankenstein y  los que fueron disfrazados de momias entraron en la rifa de las momias. El día de Halloween, se seleccionó un boleto al azar de cada categoría monstruosa y el boleto seleccionado fue el ganador de esa categoría. A Lucy se le ocurrió ir disfrazada de ¡Dracu-Franken-Momia!

Luego de una exhaustiva revisión de la convocatoria y varias horas de deliberación, los organizadores de las rifas accedieron a darle tres boletos a Lucy: uno para la rifa de vampiros, uno para la rifa de monstruos de Frankenstein y uno para la rifa de momias. A pesar de eso, Lucy no obtuvo ningún premio. “¿Pero cómo puede ser posible?” - Pensó Lucy - “¡Esos tramposos!, ¡Seguro que las rifas estuvieron arregladas!”

Este año, la escuela volvió a organizar las rifas, esta vez con $N$ categorías monstruosas. Lucy planea repetir su estrategia, pero solamente puede combinar $K$ tipos de monstruos, así que debe elegir cuidadosamente cuál subconjunto de monstruos combinar para maximizar la probabilidad de ganar en al menos una rifa.

Escribe un programa que, dados $N$, $K$ y el número de niños que ya decidieron disfrazarse de cada tipo de monstruo, seleccione los $K$ tipos de monstruo que debe elegir Lucy para maximizar la probabilidad de ganar.


# Entrada
En la primera línea, dos enteros positivos $N$, $K$ separados por un espacio que indican el número de categorías monstruosas y el número de tipos de monstruos que puede combinar Lucy. En la segunda línea, $N$ enteros $A_i$ que indican el número de niños que decidieron ir disfrazados de cada tipo de monstruo.

# Salida
En la primera línea, dos números $X$, $Y$ separados por un espacio, donde, suponiendo que Lucy participa en las $K$ categorías monstruosas que maximizan su probabilidad de ganar:

* $X$ es el número de posibles resultados de las $N$ rifas en los que Lucy gana al menos una de ellas.
* $Y$ es el número de posibles resultados de las $N$ rifas en total.


# Ejemplo

||input
3 2
1 1 2
||output
6 8
||description
Hay 3 categorías monstruosas y Lucy sólo puede combinar 2 de ellas. Lucy tiene 3 opciones:

1. Combinar {1, 2}: habrá 8 posibles resultados de las 3 rifas. Hay 6 posibles resultados en los que Lucy gana al menos una de las rifas. <b>Probabilidad de ganar al menos una rifa: 3/4</b>.
2. Combinar {1, 3}: habrá 6 posibles resultados de las 3 rifas (la segunda rifa la ganará el único niño inscrito!). Hay 4 posibles resultados en los que Lucy gana al menos una de las rifas. <b>Probabilidad de ganar al menos una rifa: 2/3</b>
3. Combinar {2, 3}: habrá 6 posibles resultados de las 3 rifas. Hay 4 posibles resultados en los que Lucy gana al menos una de las rifas. <b>Probabilidad de ganar al menos una rifa: 2/3</b>.

La mejor opción de Lucy es participar en las dos primeras rifas.
||end

# Límites

* $1 \le  K \le N \le 15$
* $1 \le A_i \le 10$,  $1 \le i \le N$


