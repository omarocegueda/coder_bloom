# Descripción
<i>“Haz tu tarea con ChatGPT”</i> - Decían. <i>“Nadie se dará cuenta”</i> - Decían. Lo que nadie me dijo es que en el examen final no podría usar ChatGPT. Ahora que reprobé mis materias tendré que pasar el verano en cursos de regularización 😢. Me pregunto si con tantos cursos de verano me quedará tiempo para hacer algunas de las actividades divertidas que había planeado dado que los intervalos de tiempo en los que ocurren las actividades seleccionadas no deben superponerse entre sí y tampoco deben superponerse con mis clases.

Afortunadamente, todas las clases fueron bien planeadas por mi escuela, así que no se superponen entre sí. Además las actividades divertidas que tenía planeadas tampoco se superponen entre sí.

# Entrada
En la primera línea el número de clases que debo tomar durante el verano. En cada una de las siguientes $N$ líneas dos enteros $a_i, b_i$ que indican el intervalo de tiempo $[a_i, b_i]$ en el que ocurre la clase (nota que el intervalo de tiempo es cerrado, es decir, incluye los instantes de tiempo $a_i$ y $b_i$). En la siguiente línea el número de actividades divertidas que había planeado. En cada una de las siguientes $M$ líneas tres enteros $d_i, e_i, f_i$ que indican el intervalo de tiempo $[d_i, e_i]$ en el que ocurre la actividad y la cantidad de diversión que obtendría si realizara la actividad.

# Salida
En la primera línea, un entero que indica la máxima diversión total que puedo obtener realizando solamente actividades que no se superponen con mis clases de verano.

# Ejemplo

||input
2
0 10
20 30
4
31 32 3
10 15 3 
27 30 3
16 25 3
||output
3
||description
La única actividad divertida que no se superpone con ninguna clase es la primera de ellas, así que la máxima cantidad de diversión que puedo obtener sin faltar a mis clases es 3.
||input
5
10 11
12 19
50 69
71 79
90 94
6
30 49 2
0 10 2
22 24 2
97 98 2
51 59 2
70 70 2
||output
8
||description
Las actividades que no se superponen con ninguna clase son las correspondientes a los intervalos [22, 24], [30, 49], [70, 70], [97, 98], para un total 8 unidades de diversión.
||input
1
0 15
1
20 25 -1
||output
0
||description
La única actividad "divertida" tiene diversión negativa, así que la máxima diversión que puedo obtener es cero (prefiero no realizar la actividad). 
||end

# Límites
*  $1 \le N, M \le 20,000$
* $-10^{18} \le a_i \le b_i \le 10^{18}$
* $-10^{18} \le d_i \le e_i \le 10^{18}$
* $-10^9 \le f_i \le 10^9$. Además, todas las actividades son igualmente divertidas, es decir, $f_i = f_j$ para todas las actividades $i, j$



