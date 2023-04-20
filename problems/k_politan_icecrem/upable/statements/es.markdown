# Descripción
Comienza un nuevo año escolar en la escuela de magia y hechicería de Hogwarts. Tradicionalmente, los elfos domésticos preparan un postre especial para los alumnos el primer día de clases. Este año decidieron que a cada uno de los $N$ alumnos de la escuela le darán un tazón de helado de $K$ sabores, pero para hacer este postre aún más especial, decidieron que los tazones de helado de los $N$ alumnos deben ser distintos entre sí. Es decir, ningún par de alumnos recibirán helados K-politanos con la misma combinación de $K$ sabores.

Ahora los elfos domésticos se preguntan cuál es el mínimo número de sabores distintos de helado que necesitan para poder servir los $N$ helados $K-$politanos distintos.

# Entrada
En la primera línea los números $N$ y $K$ separados por un espacio.

# Salida
En la primera línea, el mínimo número de sabores distintos de helado necesarios para servir $N$ helados $K$-politanos distintos.

# Ejemplos
||input
5 2
||output
4
||description
Hay 5 alumnos y cada tazón debe tener 2 sabores. 

Con 3 sabores distintos, solo podríamos servir 3 combinaciones distintas de 2 sabores:

1. {1, 2}
2. {1, 3}
3. {2, 3}

Así que 3 sabores distintos no son suficientes para darle una combinación distinta a cada uno de los 5 alumnos.

Con 4 sabores distintos, podemos servir 6 combinaciones distintas:

1. {1, 2}
2. {1, 3}
3. {1, 4}
4. {2, 3}
5. {2, 4}
6. {3, 4}

Por lo tanto, 4 sabores distintos son suficientes.

||input
10 3
||output
5
||description
Hay 10 alumnos y cada tazón debe tener 3 sabores. Con 5 sabores distintos podemos formar exactamente 10 combinaciones de 3 sabores:

1. {1, 2, 3}
2. {1, 2, 4}
3. {1, 2, 5}
4. {1, 3, 4}
5. {1, 3, 5}
6. {1, 4, 5}
7. {2, 3, 4}
8. {2, 3, 5}
9. {2, 4, 5}
10. {3, 4, 5}

¡Justo las que necesitamos!
||end

# Límites
* $1 \leq N \leq 1,000,000,000$.
* $1 \leq K \leq 1,000$.

$^1$ <i><b>A un helado con $K$ sabores distintos, los elfos le llaman ”helado $K$-politano”.</b></i>
