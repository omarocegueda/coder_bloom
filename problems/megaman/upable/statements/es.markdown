# Descripción
Mega Man es un robot, originalmente creado por el Dr. Light y su colega, el Dr. Wily, como un pacífico asistente robótico de laboratorio. El Dr. Wily tenía tiempo elaborando un macabro plan que consistía en robar y reprogramar los robots del Dr. Light y utilizarlos para conquistar el mundo. Para combatir al ejército robótico del Dr. Wily, el Dr. Light reprogramó a Mega Man como un poderoso robot de batalla.

Mega Man inicia con una arma llamada “Mega Buster”, pero una de sus habilidades más impresionantes es la capacidad de adquirir las armas de los robots que derrota y así utilizar dichas armas en contra del resto de los robots. Es decir, Mega Man puede elegir entre atacar a cada robot usando su Mega Buster o cualquiera de las armas de los robots que ha derrotado previamente. Cada robot $i$, $0 \le i \lt N$ está descrito por dos números enteros:
$R_i$ representa la resistencia del $i$-ésimo robot al ser atacado con el Mega Buster
$D_i$ indica la debilidad del $i$-ésimo robot. La resistencia del $i$-ésimo robot al ser atacado con el arma del robot $D_i$ es 1 (una unidad)

Ayuda a Mega Man a elegir el orden en el que debe enfrentar a los robots del Dr. Wily para minimizar la resistencia total (la suma de las resistencias de los robots al ser atacados con el arma óptima al momento de enfrentarlos).


# Entrada
En la primera línea el número $N$ de robots del Dr. Wily. En cada una de las siguientes $N$ líneas, los enteros $R_i$, $D_i$ que describen al $i-$-ésimo robot.

# Salida
En la primera línea, la mínima resistencia total (la suma de las resistencias de los robots al ser atacados con el arma óptima al momento de enfrentarlos).

# Ejemplo

||input
4
10 0
20 1
30 2
40 2
||output
61
||description
La debilidad de los robots 0, 1 y 2 es su propia arma, por lo que es necesario enfrentarlos usando el Mega Buster. La debilidad del robot 3 es el arma del robot 2. 

Una posible estrategia es enfrentar a los robots en el siguiente orden:

* Enfrentar al robot 0 usando el Mega Buster (Resistencia 10)
* Enfrentar al robot 1 usando el Mega Buster (Resistencia 20)
* Enfrentar al robot 2 usando el Mega Buster (Resistencia 30)
* Enfrentar al robot 3 usando el arma del robot 2 (Resistencia 1)

Total = 10+20+30+1=61
||input
5
10 1
20 2
30 0
40 4
50 3

||output
53
||description
Una posible estrategia es enfrentar a los robots en el siguiente orden:

* Enfrentar al robot 0 usando el Mega Buster (Resistencia 10)
* Enfrentar al robot 2 usando el arma del robot 0 (Resistencia 1)
* Enfrentar al robot 1 usando el arma del robot 2 (Resistencia 1)
* Enfrentar al robot 3 usando el Mega Buster (Resistencia 40)
* Enfrentar al robot 4 usando el arma del robot 3 (Resistencia 1)

Total = 10+1+1+40+1=53
||input
10
10 1
20 2
30 3
40 4
50 2
60 6
70 3
80 8
90 4
100 2
||output
39
||description
Una posible estrategia es enfrentar a los robots en el siguiente orden:

* Enfrentar al robot 2 usando el Mega Buster (Resistencia 30)
* Enfrentar al robot 1 usando el arma del robot 2 (Resistencia 1)
* Enfrentar al robot 0 usando el arma del robot 1 (Resistencia 1)
* Enfrentar al robot 4 usando el arma del robot 2 (Resistencia 1)
* Enfrentar al robot 3 usando el arma del robot 4 (Resistencia 1)
* Enfrentar al robot 6 usando el arma del robot 3 (Resistencia 1)
* Enfrentar al robot 5 usando el arma del robot 6 (Resistencia 1)
* Enfrentar al robot 8 usando el arma del robot 4 (Resistencia 1)
* Enfrentar al robot 7 usando el arma del robot 8 (Resistencia 1)
* Enfrentar al robot 9 usando el arma del robot 2 (Resistencia 1)

Total = 30 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 39

||end

# Límites
* $1 \le N \le 1,000,000$
* $0 \le D_i \lt N$
* $2 \le R_i \le 1,000,000$


