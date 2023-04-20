# Descripción
A Maria Antonieta le encantan los helados. Este domingo, su papá le dió un billete de $N$ pesos para gastar y le dijo: “Chilindrinita, ” -así le dice de cariño su papá - “ cómprate lo que quieras y me traes el cambio.” Ella salió corriendo a la heladería más cercana, donde venden dos tipos de helados: de agua y de leche. Los de agua cuestan $A$ pesos y los de leche cuestan $B$ pesos. Ahora, la ingeniosa María Antonieta se pregunta si existirá alguna manera de gastarse absolutamente todo su dinero en helados. 
# Entrada
En la primera línea, tres números $N$, $A$ y $B$ separados por espacio que indican el valor del billete de María Antonieta y el precio de los helados de agua y de leche, respectivamente.

# Salida
En la primera línea, la palabra “SI” si es posible gastar todos los $N$ pesos en helados, y la palabra “NO” si no es posible.
# Ejemplo

||input
13 4 5
||output
SI
||description
Es posible comprar 2 helados de agua y uno de leche para un total de: 
2*4+1*5=13 pesos.
||input
20 3 6
||output
NO
||description
No importa lo que compre, María Antonieta siempre recibirá cambio.
||input
15 4 5
||output
SI
||description
María Antonieta puede comprar 3 helados de leche y así se gastará todos sus 15 pesos.
||end

# Límites
* $1 &leq; A, B &leq; N &leq; 10,000,000$
