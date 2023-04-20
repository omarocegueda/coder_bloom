# Descripción
Inspirado en “¡Cómo el Grinch robó la navidad!”

“<i>¡Otra rasuradora!</i>” – Refunfuñó el Grinch al ver su regalo de intercambio – “<i>Con esta ya van siete. ¿Qué parte de no-quiero-rasurarme no han entendido?</i>”. El año siguiente, El Grinch propuso modificar la dinámica del intercambio. En lugar de decidir primero quién le daría regalo a cada Quién, los $N$ participantes, numerados del 1 al $N$ formarían un círculo alrededor de los $N$ regalos en el sentido de las manecillas del reloj. Luego, en el orden de su numeración, cada participante elegiría el regalo que quisiera. Todos los participantes tienen las mismas preferencias, es decir, de acuerdo a los participantes, el regalo 1 es el mejor de todos, seguido del 2 y así sucesivamente, siendo el regalo $N$ el menos deseado. “<i>¡Pero eso no es justo!</i>” - Exclamó uno de ellos - “<i>¡El primero en elegir se quedará con el mejor regalo!</i>”. Así que, sin pensarlo mucho, el Grinch propuso que se valga robar: cada participante puede elegir el regalo que quiera sin importar si alguien ya lo eligió antes. El participante al que le fue robado su regalo, tendrá que elegir de nuevo cuando llegue su turno. <b>Si el participante en turno ya tiene un regalo, no puede elegir otro, y el turno pasa al siguiente participante</b>. Ese intercambio duró toda la noche y pudo continuar infinitamente, por lo que decidieron cancelarlo.

Para evitar que el intercambio se prolongue infinitamente, este año todos decidieron poner un límite de $R$ “robos” en total durante el intercambio. Nota que es posible que un participante termine con el mismo regalo sin importar cuál sea su elección inicial, en ese caso siempre elegirá primero el regalo más deseado. Por ejemplo, si hay 2 participantes y se vale hacer $R=1$ robo, entonces el primer participante puede iniciar eligiendo el regalo 1 o el regalo 2:

* <b>Opción 1</b>:
El participante 1 elige el regalo 1
El participante 2 le roba el regalo 1 (el participante 1 se queda sin regalo momentáneamente)
El participante 1 elige el regalo 2 porque ya no hay robos disponibles

* <b>Opción 2</b> :
El participante 1 elige el regalo 2
El participante 2 elige el regalo 1 (no es necesario robar para obtener el mejor regalo)
Como el resultado final es el mismo para el primer participante (siempre terminará con el regalo 2) el primer participante decidirá elegir primero el regalo más valioso (es decir, ocurrirá la opción 1).

Ahora el Grinch se pregunta, suponiendo que cada participante hace la elección óptima, ¿Cuál será la asignación final? 

# Entrada
En la primera línea, dos enteros $N$ y $R$ separados por un espacio indicando el número de participantes y el número total de robos permitidos.

# Salida
En la primera línea, $N$ enteros $a_i$ indicando el regalo que obtendrá cada participante.

# Ejemplo

||input
3 0
||output
1 2 3
||description
Hay $N=3$ participantes y no se vale robar. Entonces el primer participante elegirá el regalo 1, el segundo participante el 2, y el tercer participante el 3, es decir, la asignación final será {1, 2, 3}

||input
3 1
||output
3 1 2
||description
Hay $N=3$ participantes y se vale hacer a lo más un robo en total. La dinámica es la siguiente:

1. El participante 1 elige el regalo 1
2. El participante 2 le roba el regalo 1 al participante 1
3. El participante 3 elige el regalo 2 (ya no hay robos disponibles)
4. El participante 1 elige el regalo 3 (el único disponible) 

Nota que sin importar la elección inicial del participante 1, siempre terminará con el regalo menos deseado (el 3), así que su elección inicial será el regalo más deseado (el 1).

||input
3 2
||output
1 3 2
||description
Hay $N=3$ participantes y se vale hacer, a lo más, dos robos en total.
En este caso, la elección óptima para el primer participante es el regalo 2:

1. El participante 1 elige el regalo 2
2. El participante 2 elige el regalo 1
3. El participante 3 le roba el regalo 2 al participante 1
4. El participante 1 le roba el el regalo 1 al participante 2
5. El participante 2 elige el regalo 3 (el único disponible)

Nota que sin importar la elección inicial del participante 2, siempre terminará con el regalo menos deseado (el 3), así que su elección inicial será el regalo más deseado (el 1).

||end

# Límites

* $1 \le  N, R \le 6$
* $1 \le N + R \le 10$


