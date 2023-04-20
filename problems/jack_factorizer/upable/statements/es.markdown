# Descripción
Jack el Factorizador es un criminal en serie que ataca a números compuestos (los números “compuestos” son los números <b>mayores que 1</b>, que no son primos). Cuando Jack el Factorizador ataca a un número compuesto, lo factoriza y deja en su lugar a sus factores primos. La pobre víctima queda irreconocible, pero al menos todos sus factores primos permanecen juntos.

Jack el Factorizador acaba de atacar a algunos elementos de una lista de $C$ números compuestos. El resultado fue una lista de $N$ enteros positivos que podría contener números primos. Las autoridades locales necesitan determinar la identidad de todos los elementos de la lista original. Afortunadamente, Jack nunca ataca a dos números compuestos consecutivos en ninguna lista. Es decir, si Jack ataca a un número compuesto, nunca atacará a sus números compuestos adyacentes.

Ayuda a las autoridades locales en su investigación de estos terribles crímenes determinando el número de elementos de la lista original.

# Entrada
En la primera línea, el número $N$ de elementos en la lista final (luego de los ataques de Jack el Factorizador). En la segunda línea, los $N$ enteros positivos $\lbrace a_i \rbrace$ separados por espacio.

# Salida
En la primera línea, el número $C$ de elementos en la lista original de números compuestos (antes de los ataques de Jack el Factorizador).

# Ejemplo

||input
7
2 3 9 3 5 3 2

||output
3
||description
Los primeros 2 elementos de la lista son números primos seguidos de un afortunado número compuesto, 9, que no fue atacado. Por lo tanto el número compuesto original debe haber sido 6. Los último cuatro números son primos, todos ellos deben ser los restos del número compuesto 3*5*3*2=90, ya que Jack nunca ataca a dos números compuestos consecutivos. 
La lista original era: [6, 9, 90], de longitud 3.

||input
10
2 3 8 5 7 10 15 30 2 2
||output
7
||description
La lista original era: [6, 8, 35, 10, 15, 30, 4], de longitud 7.
||end

# Límites
* $N \leq 10,000$
* $a_i \leq 1,000,000$

