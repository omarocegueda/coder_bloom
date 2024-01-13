# Descripción
Una noche, el Conde Drácula observaba una enorme cortina cuadriculada de muchos colores en su castillo y se le ocurrió que podría utilizar parte de la cortina para confeccionar una nueva capa. La cortina está definida por una retícula rectangular de $N$ filas por $M$ columnas, donde cada celda está pintada de algún color. Para elaborar su capa, el Conde necesita recortar un trozo cuadrado lo más grande posible. Al Conde no le interesan los colores de su capa, pero definitivamente quiere que formen el patrón de un tablero de ajedrez . Dada la descripción de la cortina, ayuda al Conde Drácula a encontrar el trozo cuadrado más grande que puede recortar cuyos colores formen el patrón de un tablero de ajedrez (con exactamente 2 colores alternados horizontal y verticalmente).

# Entrada
En la primera línea, dos enteros $N$, $M$ separados por un espacio que indican las dimensiones de la cortina. En cada una de las siguientes $N$ líneas, una cadena de texto de longitud $M$ donde cada elemento de la cadena es una letra minúscula del alfabeto inglés (entre ‘a’ y ‘z’) que representa el color de la celda correspondiente en la cortina cuadriculada.

# Salida
En la primera línea, un entero $L$ que representa el tamaño del trozo cuadrado de $L \times L$ más grande que el Conde puede recortar de la cortina cuyos colores formen el patrón de un tablero de ajedrez. Se garantiza que en todos los casos de prueba, la solución es mayor o igual que 2.

# Ejemplo

||input
5 7
cccccc
cabacc
cbabcc
cabacc
cccccc

||output
3
||description
El trozo cuadrado unicolor más grande es de tamaño $3 \times 3$ y tiene el patrón de un tablet de ajedrez de colores correspondientes a las letras a, b:
aba
bab
aba

||end

# Límites
* $1 \le N, M \le 1,000$
