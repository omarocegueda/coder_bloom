# Descripción
[Nancy Pacheco](https://www.linkedin.com/in/nancy-pacheco-2b443461/), directora ejecutiva de Coder Bloom, acaba de entrar en pánico: el siguiente concurso de programación se acerca y ¡aún no hay problemas para el concurso! Ahora debe apresurarse a coordinar a los creadores de problemas antes de que se vayan de vacaciones.

Hay $N$ creadores de problemas, y cada uno de ellos se especializa en escribir problemas de un tipo distinto (hay exactamente $N$ tipos distintos de problemas). A cada creador le toma una hora escribir un problema de su especialidad, pero le toma $K$ horas escribir un problema que no es de su especialidad.

Dada la cantidad de problemas de cada tipo que se necesitan para el siguiente concurso de programación, ¿cuál será el mínimo tiempo necesario para que los creadores de problemas, trabajando simultaneamente, puedan terminar todos los problemas del concurso?



# Entrada
En la primera línea, dos enteros $N, K$ separados por espacio que indican el número de creadores de problemas y la cantidad de horas que tarda cada creador en escribir un problema que no es de su especialidad. En la segunda línea, $N$ enteros $\lbrace p_i \rbrace$ separados por espacio que indican la cantidad de problemas de cada especialidad que se requieren para el concurso.

# Salida
En la primera línea el mínimo número de horas que se requieren para que los creadores de problemas terminen todos los problemas del concurso.

# Ejemplo

||input
3 2
2 9 4
||output
6
||description
Una manera de dividirse los problemas es la siguiente:

* El creador 1 escribe los dos problemas de su especialidad y le ayuda al creador 2 con 2 problemas. Tiempo total: 2*1+2*2=6
* El creador 2 escribe 6 problemas de su especialidad. Tiempo total: 6*1=6
* El creador 3 escribe los 4 problemas de su especialidad y le ayuda al creador 2 con un problema. Tiempo total: 4*1+1*2=6

No hay manera de lograr terminar todos los problemas en menos de 6 horas.
||end

# Límites
* $1 \le N \le 20,000$
* $1 \le K \le 100$
* $0 \le p_i \le 1,000,000,000$
