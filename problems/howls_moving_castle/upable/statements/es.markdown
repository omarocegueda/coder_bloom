# Descripción
Inspirado en: El Castillo Vagabundo (“Howl’s Moving Castle”)

Howl es un hechicero que habita en el Castillo Vagabundo, y tiene un aprendiz llamado Markl. Después de mucho tiempo de ayudar a Howl, Markl está listo para tener sus propios clientes. Howl, le propuso a Markl que elija dónde colocar $P$ puertas mágicas que le ayuden a comunicar el Castillo Vagabundo con $N$ pueblos ubicados a lo largo de una carretera. La posición del i-ésimo pueblo está dada por un entero no negativo $K_i$ que identifica el número de kilómetro a lo largo de la carretera donde se encuentra el centro del pueblo. Los habitantes del i-ésimo pueblo estarán dispuestos a visitar el Castillo Vagabundo (y por lo tanto contratar los servicios de Markl) si existe una puerta cuya distancia al centro del pueblo sea a lo más $D$ kilómetros, es decir $|X - K_i| \le D$, donde $X$ es la posición de la puerta. 

Ahora Markl se pregunta cuál será el mínimo número de puertas mágicas que requiere para que los habitantes de todos los pueblos estén dispuestos a visitar el Castillo Vagabundo.


# Entrada
En la primera línea los dos enteros $N$ y $D$ separados por un espacio.
En la segunda línea, los $N$ enteros $\lbrace K_i | 1 \le i \le N\rbrace$ separados por espacio que indican las posiciones de los $N$ pueblos a lo largo de la carretera. 



# Salida
En la primera línea el mínimo número de puertas mágicas que Markl requiere para que los habitantes de todos los pueblos estén dispuestos a visitar el Castillo Vagabundo.

# Ejemplo

||input
5 6
25 10 15 20 5
||output
2
||description
Hay 5 pueblos en las posiciones $5, 10, 15, 20, 25$, respectivamente. Los habitantes están dispuestos a visitar el Castillo Vagabundo si existe una puerta mágica a una distancia no mayor que 6 kilómetros. Existen varias soluciones óptimas pero si Markl coloca 2 puertas mágicas en las posiciones $9, 22$, respectivamente,  entonces los habitantes de todos los pueblos tendrán una puerta mágica a distancia menor que 6:

* Los habitantes de los pueblos en las posiciones $5, 10, 15$ pueden usar la puerta en la posición $9$
* Los habitantes de los pueblos en las posiciones $20, 25$ pueden usar la puerta en la posición 22

||end

# Límites
* $1 \le N \le 1,000,000$
* $0 \le D \le 1,000,000$
* $0 \le K_i \le 1,000,000,000$, para $1 \le i \le N$
