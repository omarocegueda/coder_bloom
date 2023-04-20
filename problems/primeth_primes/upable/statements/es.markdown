# Descripción
Es bien sabido que los Primatitlenses tienen fama de orgullosos. Su mayor orgullo, que los distingue del resto de los números naturales, es ser números primos, por supuesto. Pero algo que no es tan bien sabido, es que existe un grupo de Primatitlenses aún más orgullosos y son la envidia de todo Primatitlán: los primésimos primos. Decimos que el $k$-ésimo número primo es es un “primésimo primo” si $k$ es primo. Por ejemplo:
El 2 no es un primésimo primo porque 2 es el 1er primo (es decir, el “1-ésimo”) pero 1 no es primo.
El 3 es un primésimo primo porque 3 es el 2do primo (es decir, el “2-ésimo”) y 2 es primo.
El 5 es un primésimo primo porque 5 es el 3er primo (el “3-ésimo”) y 3 es primo. 
¿Qué tan “especiales” serán estos orgullosos primos? O más precisamente, dado un número $N$, ¿Cuántos primésimos primos menores o iguales que $N$ existirán? 


# Entrada
En la primera línea el número $N$.

# Salida
En la primera línea el número de primésimos primos menores que $N$.

# Ejemplo

||input
31
||output
5
||description
Los primésimos primos menores o iguales que 31 son:

* 3: el 2-ésimo primo
* 5: el 3-ésimo primo
* 11: el 5-ésimo primo
* 17: el 7-ésimo primo
* 31: el 11-ésimo primo

||input
15
||output
3
||description
Los primésimos primos menores o iguales que 15 son 3, 5 y 11. El siguiente es 17, pero es mayor que 15.
||end

# Límites
* $N \leq 1,000,000$

