# Descripción
Inspirado en “Las mil y una noches”.

El terrible sultán Shahriar, del antiguo Imperio Persa, desposaba una hermosa doncella cada día y la condenaba a muerte al día siguiente. Al enterarse de ésto, la brillante Sherezade ideó un plan para aplacar la ira del Sultán.

Sherezade conoce $A+B$ cuentos. Según el Sultán, $A$ son interesantes y $B$ son no-interesantes. Cada que Sherezade le cuenta un cuento interesante al Sultán, su interés se incrementa en una unidad, mientras que al contarle un cuento no-ainteresante, su interés se reduce en una unidad. El interés del Sultán nunca puede ser mayor que $I_{max}$, así que si Sherezade le cuenta un cuento interesante al Sultán cuando su interés ya ha alcanzado el valor $I_{max}$, el interés del Sultán permanecerá en $I_{max}$. Si el interés del sultán se reduce hasta alcanza un valor $I_{min}$ o menor, el Sultán condenará a muerte a Sherezade, continuando así con su reinado de terror. 

El sultán comienza con un interés $I_0$. Si Sherezade debe contar un cuento cada noche hasta terminarlos todos ¿Podrá Sherezade idear una estrategia para que el interés del Sultán siempre sea estrictamente mayor que $I_{min}$?



# Entrada
En la primera línea, los cinco enteros no-negativos $A$, $B$, $I_0$, $I_{min}$, $I_{max}$ descritos anteriormente, separados por espacio.

# Salida
En la primera línea, la palabra “SI” si existe una estrategia contar los $A+B$ cuentos manteniendo el interés del Sultán estrictamente mayor que $I_{min}$. "NO" si no existe dicha estrategia.

# Ejemplo

||input
2 2 1 0 2
||output
SI
||description
Sherezade conoce 2 cuentos interesantes y 2 cuentos no-interesantes. El sultán comienza con un interés $I_0=1$. Sherezade puede alternar los cuentos de la siguiente manera:

1. Interesante → Interés=2
2. No-Interesante → Interés=1
3. Interesante → Interés=2
4. No-interesante → Interés=1

||input
3 4 1 0 10
||output
NO
||description
Sherezade conoce 3 cuentos interesantes y 4 cuentos no interesantes. Como el Sultán inicia con un interés $I_0=1$, no existe ninguna estrategia para evitar que el interés del Sultán llegue a $I_{min}=0$ :'( 

||input
50 0 90 90 100
||output
NO
||description
Sherezade conoce 50 cuentos, todos ellos interesantes. Desafortunadamente, el Sultán comienza con un interés igual a $I_{min}$, no hay nada que Sherezade pueda hacer para que su interés siempre sea estrictamente mayor que $I_{min}$  :’(
||end

# Límites
* $0 \le A, B \le A+B \le 1,000,000,000,000$
* $0 \le I_{min} \le I_0 \le I_{max} \le 1,000,000,000,000$


