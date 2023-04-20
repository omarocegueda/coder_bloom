# Descripción
Inspirado en "La Odisea".

Han pasado 20 años desde que el Rey Odiseo dejó la isla de Ítaca para pelear en la guerra de Troya. Al creerlo muerto, muchos traidores amenazan con apoderarse de su reino ya que, según la tradición, la reina Penélope debe elegir al sucesor del rey.

Inspirada por la Diosa Atenea, Penélope decidió poner a prueba a los pretendientes. La prueba consiste en disparar una flecha a través de una serie de aros, algo que sólo Odiseo es capaz de realizar. Quien pase la prueba será el sucesor del rey.

Odiseo, quien acaba de regresar de su largo viaje, envejecido y harapiento, está irreconocible y todos lo toman por un pobre mendigo. Al enterarse del certamen del arco, Odiseo decide participar.

Hay $N$ aros colocados en diferentes posiciones frente a Odiseo. La posición de cada aro está dada por dos números enteros $(x, y)$ (ver figura). Odiseo sostiene su arco de tal forma que la punta de la flecha está en la posición $(0, B)$. Ahora Odiseo debe decidir en qué orientación disparar su flecha de tal manera que atraviese la mayor cantidad de aros$^1$.

Por ejemplo, supongamos que $B=20$ (es decir, Odiseo está colocado de tal forma que la punta de su flecha está en la posición $(0, 20)$). Supongamos que hay $N=12$ aros ubicados como en la siguiente figura:

<center>![](img1.png)</center>

Odiseo tiene infinitas opciones para disparar su flecha pero sólo hay 3 opciones para lograr atravesar un número positivo de aros. Lo mejor que puede hacer Odiseo es atravesar 5 aros.


# Entrada
En la primera línea, dos enteros $B$ y $N$ separados por un espacio que indican la posición de la flecha y el número de aros, respectivamente. En cada una de las siguientes $N$ líneas, dos enteros ${x_i, y_i}$ que indican la posición del i-ésimo aro.

# Salida
En la primera línea, el máximo número de aros que puede atravesar Odiseo.

# Ejemplo

||input
20 12
30 20
15 35
45 5
20 40
55 20
60 0
25 45
5 20
5 25
15 15
10 30
30 10
||output
5
||description
El ejemplo en la descripción del problema. Odiseo sostiene la flecha en la posición $(0, 20)$ y hay 12 aros en las posiciones que muestra la figura. Lo mejor que puede hacer Odiseo es disparar la flecha hacia arriba, atravesando 5 aros.
||end

# Límites
* $1<=B<=100,000,000$
* $1<=N<=100,000$
* $1<=x_i<=100,000,000$
* $0<=y_i<=100,000,000$

$^1$ Para este problema, supondremos que el movimiento de la flecha será en línea recta (es decir, ignoraremos la fuerza de gravedad) y que para atravesar un aro en la posición $(x_i, y_i)$, la flecha debe pasar exactamente por ese punto (es decir, ignoraremos el diámetro de los aros y dimensiones de la flecha).
