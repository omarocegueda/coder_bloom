# Descripción
<i>Doña Blanca<a id="footnote1ref" href="#footnote1">[1]</a> está cubierta<br>
con pilares de oro y plata<br>
romperemos un pilar<br>
para ver a doña Blanca<br>
¿Quien es ese Jicotillo<br>
que anda en pos de Doña blanca?<br>
¡yo soy ese Jicotillo<br>
que anda en pos de doña blanca!<br>
</i>
<br>
<center>![](img1.png)</center>
<br>
Los $N$ pilares están colocados en círculo y numerados del $1$ al $N$ en el sentido de las manecillas del reloj. El Jicotillo comienza intentando romper el pilar $P$, luego el pilar que se encuentra avanzando $K$ pilares en el sentido de las manecillas del reloj y así sucesivamente, avanzando $K$ pilares hasta que logra romper un pilar, logrando así alcanzar a Doña Blanca. Cada pilar $i$ resiste $R_i$ unidades de fuerza, donde $1 \le i \le N$. El Jicotillo podrá romper un pilar si y sólo si la fuerza con la que intenta romperlo es estrictamente mayor que la resistencia del pilar. ¿Cuál es la mínima fuerza que requiere el Jicotillo para romper al menos uno de los pilares que intentará romper?

# Entrada
En la primera línea, los enteros $N$, $K$ separados por espacio. En la segunda línea, $N$ enteros $R_i$, $1 \le i \le N$ separados por espacio que representan las resistencias de los pilares. En la tercera línea un entero $M$ que indica el número de veces que se jugará el juego. En la siguiente línea, $M$ enteros $P_j$, $1 \le j \le M$ que indican las posiciones en las que comenzará el Jicotillo en cada instancia del juego. 

# Salida
En la primera línea, $M$ enteros $F_j$, $1 \le j \le M$ separados por espacio que indican la mínima fuerza que requiere el Jicotillo para romper al menos uno de los pilares que intentará romper en esa instancia del juego. 

# Ejemplo

||input
8 2
7 3 7 1 7 3 5 3
2
1 2

||output
6 2
||description
Hay 8 pilares, como se muestra en la figura y en todas las instancias del juego, el Jicotillo avanza $K=2$ pilares en cada intento. Habrá dos instancias del juego:

* **Juego 1**: El Jicotillo comienza intentando romper el pilar número 1 (ver figura), por lo tanto, intentará romper los pilares {1, 3, 5, 7} con resistencias respectivas {7, 7, 7, 5}. La mínima fuerza que requiere el Jicotillo es 6.
* **Juego 2**: El Jicotillo comienza intentando romper el pilar número 2, por lo tanto intentará romper los pilares {2, 4, 6, 8} con resistencias respectivas {3, 1, 3, 3}. La mínima fuerza que requiere el Jicotillo es 2.
||end

# Límites
* $1 \le N, K, M \le 100,000$
* $1 \le R_i \le 1,000,000,000$, para $1 \le i \le N$
* $1 \le P_j \le N$, para $1 \le j \le M$


<p id="footnote1">
   1. “Doña Blanca” es un juego popular en el que un grupo de $N$ niños se colocan en círculo, tomados de las manos alrededor de otro niño que juega el papel de “Doña Blanca”. Un niño adicional, quien juega el papel del “Jicotillo” (un abejorro pequeño), camina alrededor del círculo intentando “romper” al menos un “pilar” para entrar en el círculo y así alcanzar a “Doña Blanca”. Cada “pilar” está representado por las manos unidas de dos niños consecutivos, quienes se sujetan fuertemente para evitar que el Jicotillo separe sus manos, representando la ruptura del pilar. <a href="#footnote1ref">&#8617;</a>  