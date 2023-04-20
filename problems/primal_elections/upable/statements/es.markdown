# Descripción
Las elecciones para gobernador del Estado soberano de Primatitlán se acercan y los habitantes (todos ellos números primos) se preparan para emitir sus votos. Por ley, todos los primos tienen derecho a ser votados, por lo que todos los primos se consideran candidatos. Cada habitante puede votar por cero o más primos candidatos escribiendo en su boleta un número positivo que representa el conjunto de candidatos por los que desea votar. Por ejemplo, si un habitante escribe en su boleta "1", eso significa que desea anular su voto, y ningún primo obtendrá ningún voto de esa boleta. Si un habitante escribe en su boleta "6", eso significa que desea votar por los primos candidatos "2" y "3", ya que 6=2*3. Cada habitante puede votar por tantos primos candidatos como desee pero, para evitar fraudes, cada boleta solamente asignará a lo más un voto a cada candidato. Por ejemplo, si uno de los habitantes escribe "120" en su boleta, entonces los primos candidatos 2, 3 y 5 recibiran cada uno un solo voto a pesar de que 120=2*2*2*3*5 (el candidato 2 solamente recibirá un voto, no tres).

El Instituto Factorizador Electoral (IFE) es el encargado de contabilizar los votos y determinar al candidato primo ganador de las elecciones. Ayuda al IFE a determinar al ganador de la elección.


# Entrada
En la primera línea el número $V$ de votos que fueron emitidos durante la elección. En la segunda línea, $V$ enteros positivos $\lbrace v_i \rbrace$, separados por espacio que representan los $V$ votos emitidos.

# Salida
En la primera línea, el primo ganador de la elección y el número de votos que obtuvo, separados por un espacio (se garantiza que existirá exactamente un primo con la mayor cantidad de votos).

# Ejemplo

||input
3
6 10 14

||output
2 3
||description
Los votos fueron:

* $6 = 2*3$
* $10 = 2*5$
* $14 = 2*7$

El carismático candidato 2 obtuvo 3 votos, venciendo a sus contrincantes 3, 5 y 7.

||input
6
1024 27 6 5 5 5

||output
5 3
||description
Los votos fueron:

* $1024 = 2^{10}$
* $27 = 3^3$
* $6 = 2*3$
* $5$
* $5$
* $5$

Los candidatos 2 y 3 empataron con 2 votos cada uno. El candidato 5 los venció con un total de 3 votos.
||end

# Límites
* $V \leq 1,000$
* $v_{i} \leq 1,000,000,000$
