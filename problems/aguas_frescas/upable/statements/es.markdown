# Descripción
A Roberto le encantan las aguas frescas$^{1}$. Una tarde calurosa caminó a la tienda más cercana, donde venden aguas frescas de frutas, y pidió una agua de fresa. ¡Con mucho gusto! - respondió el vendedor muy amablemente - ¿quiere de la que parece de fresa, de la que huele a fresa o de la que sabe a fresa? Desconcertado, Roberto respondió: la que sabe a fresa, por favor. Aún más desconcertado, Roberto vió cómo el vendedor llenaba un vaso con agua de color naranja. Al salir de la tienda, Roberto notó sorprendido que efectivamente sabía a fresa, aunque curiosamente olía como a zarzamoras.

Mientras caminaba de regreso a su casa, Roberto se preguntó cuántas posibles aguas de frutas “engañosas” podría existir, en el sentido de que al menos dos de sus propiedades (apariencia, olor o sabor) corresponden a diferentes frutas. 

Escribe un programa que dado el número de frutas distintas, determine el número de posibles aguas “engañosas” que pueden existir.


# Entrada

En la primera línea el número $N$ de frutas.

# Salida

En la primera línea, el número de posibles aguas frescas “engañosas” que pueden existir, en el sentido de que al menos dos de sus propiedades (apariencia, olor o sabor) corresponden a diferentes frutas.


# Ejemplo

||input
2
||output
6
||description
Hay dos frutas, por ejemplo fresa y sandía. Hay 6 posibles aguas frescas engañosas:

1. {fresa, fresa, sandía} - se ve como fresa, huele a fresa, pero sabe a sandía
2. {fresa, sandía, fresa} - se ve como fresa, huele a sandía pero sabe a fresa
3. {fresa, sandía, sandía}
4. {sandía, sandía, fresa}
5. {sandía, fresa, sandía}
6. {sandía, fresa, fresa}

||end

# Límites

* $1 \le N \le 1000$


$^1$ <i><b>En México y algunos otros países de América Latina, se acostumbra preparar bebidas a base de frutas, cereales o semillas mezcladas con agua y azúcar. A estas bebidas se les llama “aguas frescas”.</b></i>

