# Descripción
Comienza un nuevo año escolar en la escuela de magia y hechicería de Hogwarts. Tradicionalmente, cada uno de los $N$ alumnos de nuevo ingreso es asignado a uno de $C$ grupos llamados “casas” al que pertenecerán por el resto de sus estudios. Para realizar la asignación, los $N$ alumnos de primer ingreso se forman a la entrada de la escuela y antes de entrar se les asigna mágicamente$^1$ a una de las $C$ casas. Al final de la asignación, la $i$-ésima casa quedará con $n_i$ alumnos asignados, donde $1 \leq i \leq C$. A cada posible resultado $\lbrace n_1, n_2, …, n_C \rbrace$ le llamamos una “configuración” de las $C$ casas. ¿Cuántas posibles configuraciones distintas habrá?

# Entrada
En la primera línea los números $N$ y $C$, separados por un espacio.

# Salida
Como el número de posibles configuraciones puede ser muy grande, imprime en la primera línea el número posibles configuraciones de las $C$ casas, módulo $1,000,000,007$.

# Ejemplos
||input
3 2
||output
4
||description
Hay 3 alumnos y 2 casas. Las posibles configuraciones de las 2 casas son:

1. **{3, 0}**: todos los alumnos se asignan a la primera casa
2. **{2, 1}**: dos alumnos a la primera casa y un alumno a la segunda casa
3. **{1, 2}**: un alumno a la primera casa y dos alumnos a la segunda casa
4. **{0, 3}**: todos los alumnos se asignan a la segunda casa
||input
3 3
||output
10
||description
Hay 3 alumnos y 3 casas.
Las posibles configuraciones son:

1. {3, 0, 0}
2. {2, 1, 0}
3. {2, 0, 1}
4. {1, 2, 0}
5. {1, 1, 1}
6. {1, 0, 2}
7. {0, 3, 0}
8. {0, 2, 1}
9. {0, 1, 2}
10. {0, 0, 3}
||input
2 3
||output
6
||description
Hay 2 alumnos y 3 casas. Las posibles configuraciones son:

1. {2, 0, 0}
2. {1, 1, 0}
3. {1, 0, 1}
4. {0, 2, 0}
5. {0, 1, 1}
6. {0, 0, 2}
||end

# Límites
* $1 \leq N, C \leq 1,000,000$.

$^1$ <i><b>Existe un “sombrero mágico seleccionador” que considera las aptitudes, vocación y preferencias de cada alumno, y luego de una larga meditación y deliberación con el alumno de nuevo ingreso, selecciona una casa al azar.</b></i>
