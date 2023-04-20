# Descripción
Inspirado en <i>“Las mil y una noches”</i>.

El terrible sultán Shahriar, del antiguo Imperio Persa, desposaba una hermosa doncella cada día y la condenaba a muerte al día siguiente. Al enterarse de ésto, la brillante Sherezade ideó un plan para aplacar la ira del Sultán.

Sherezade conoce $N$ cuentos. Según el Sultán, $A$ son interesantes y $N-A$ son no-interesantes. Cada que Sherezade le cuenta un cuento interesante al Sultán, su interés se incrementa en una unidad, mientras que al contarle un cuento no-interesante, su interés se reduce en una unidad. El interés del Sultán nunca puede ser mayor que $I_{max}$, así que si Sherezade le cuenta un cuento interesante al Sultán cuando su interés ya ha alcanzado el valor $I_{max}$, el interés del Sultán permanecerá en $I_{max}$. Si en cualquier momento el interés del sultán se termina (es decir, su interés tiene un valor de cero) el Sultán condenará a muerte a Sherezade, continuando así con su reinado de terror. 

El sultán comienza con un interés $I_0$. Ahora Sherezade se pregunta de cuántas maneras distintas puede contar los $N$ cuentos de tal manera que el interés del Sultán siempre sea estrictamente mayor que cero. Dos secuencias de cuentos $X=\lbrace x_1, x_2, …, x_N\rbrace$, $Y=\lbrace y_1, y_2, … y_N \rbrace$ se consideran iguales si y sólo si para todos los índices $1 \le i \le N$, $x_i$ y $y_i$ ambos son interesantes o ambos son no-interesantes (ver ejemplos).   


# Entrada
En la primera línea, los cuatro enteros no-negativos $N$, $A$, $I_0$, $I_{max}$ descritos anteriormente, separados por espacio.

# Salida
El número de secuencias distintas en que Sherezade puede contar los $N$ cuentos de forma que el interés del Sultán siempre sea positivo. Como el número de secuencias distintas puede ser muy grande, imprime la solución <b>módulo 1000000007</b>.


# Ejemplo

||input
7 3 2 2
||output
1
||description
<b>Si denotamos cada cuento interesante por una flecha hacia arriba ‘^’ y cada cuento no-interesante por una flecha hacia abajo ‘v’</b>, la única manera en que Sherezada puede contar los $N=7$ cuentos es:

1. v^v^v^v

||input
4 2 2 2
||output
3
||description
Sherezade puede contar los $N=4$ cuentos (donde $A=2$ de ellos son interesantes) de la siguiente manera:

1. ^v^v
2. v^^v
3. v^v^
||input
7 3 2 3
||output
8
||description
Sherezade puede contar los $N=7$ cuentos (donde $A=3$ de ellos son interesantes) de la siguiente manera:

1. ^v^v^vv
2. v^^v^vv
3. ^vv^^vv
4. v^v^^vv
5. ^v^vv^v
6. v^^vv^v
7. ^vv^v^v
8. v^v^v^v
||input
7 3 1 2
||output
0
||description
No existe ninguna estrategia para evitar que el interés del Sultán llegue a cero :’( 
||input
10 10 0 100
||output
0
||description
Sherezade conoce 10 cuentos, todo ellos interesantes. Desafortunadamente, el interés del Sultán comienza en cero. No hay nada que Sherezade pueda hacer :’(
||end

# Límites
* $0 \le N, I_{max} \le 100$
* $0 \le A   \le N$
* $0 \le I_0 \le I_{max}$


