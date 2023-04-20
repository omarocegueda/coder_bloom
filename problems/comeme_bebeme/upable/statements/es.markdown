# Descripción
Inspirado en <i>“Alicia en el País de las Maravillas”</i>.
 
<i>“Desde que llegué aquí por perseguir al conejo blanco, se me ha dicho que debo hacer y quién debo ser, me han encogido, estirado, rasguñado, y atrapado en una tetera también…”</i> – Renegó Alicia decidida a hacerse cargo de su propio destino – <i>“Desde ahora voy a decidir lo que pasa”</i>.

Luego de reflexionar por un momento, Alicia está angustiada, ¿será posible regresar a su tamaño normal? El tamaño normal de Alicia es $N$ centímetros, pero después de haber sido encogida y estirada en múltiples ocasiones, Alicia mide ahora $A$ centímetros. Cada que Alicia bebe un sorbo de su poción “Bébeme”, se encoge $B$ centímetros y cada que come un bocado de su pastel “Cómeme”, crece $C$ centímetros (Alicia debe tener cuidado ya que beber la poción mientras mide $B$ centímetros o menos, ¡la mataría!). Alicia puede beber tantos sorbos de su poción y comer tantos bocados de su pastel como ella deseé. 

# Entrada
En la primera línea, los cuatro enteros positivos $A$, $B$, $C$, $N$ descritos anteriormente, separados por un espacio.

# Salida
En la primera línea, la palabra “SI” si Alicia puede regresar a su tamaño normal o la palabra “NO” si Alicia no puede regresar a su tamaño normal.

# Ejemplo

||input
20 7 15 127

||output
SI
||description
Actualmente, Alicia mide 20 centímetros y su altura normal es 127 centímetros. Cada sorbo de la poción la hace encoger 7 centímetros y cada bocado de su pastel la hace crecer 15 centímetros.

Una manera de volver a su tamaño normal sería comiendo 9 bocados de su pastel y tomando 4 sorbos de su poción.
||input
126 2 2 127
||output
NO
||description
Para volver a su tamaño normal, Alicia necesita crecer 1 centímetro, lo cual es imposible de lograr con una poción y un pastel que sólo le permiten a Alicia encogerse y crecer 2 centímetros a la vez, respectivamente. 
||end

# Límites
* $1<=A, B, C, N<=1,000,000,000$

