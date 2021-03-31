# Descripcion
El rey se queda solo en un tablero de ajedrez. A pesar de esta soledad, no se desanima, porque tiene negocios de importancia nacional. Por ejemplo, tiene que hacer una visita oficial a la casilla $t$. Como el rey no tiene la costumbre de perder el tiempo, quiere pasar de su posición actual $s$ al cuadrado t en el menor número de movimientos. Ayúdalo a llegar rapidamente.

![El tablero de ajedrez](tablero.png)

En un movimiento, el rey puede llegar a la casilla que tiene un lado común o un vértice común con la casilla en la que se encuentra actualmente el rey (es decir se puede mover a las 8 casillas diferentes que lo rodean ).

# Entrada
La primera línea contiene las coordenadas $s$ del rey en el tablero de ajedrez  , en la segunda línea, las coordenadas  $t$ de la casilla a la que quiere llegar. Las coordenadas del tablero de ajedrez constan de dos caracteres, el primero es una letra latina minúscula (de la $a$ la $h$), el segundo es un dígito del $1$ al $8$.

# Salida
En la primera linea imprime un numero  $n$ - el número mínimo de movimientos del rey. Luego, en $n$ líneas, imprime los movimientos en sí. Cada movimiento se describe con uno de los 8: $L$, $R$, $U$, $D$, $LU$, $LD$, $RU$ o $RD$. _L_, _R_, _U_, _D_ representan respectivamente movimientos hacia la izquierda, derecha, arriba y abajo (según la imagen), y las combinaciones de 2 letras representan movimientos diagonales. Si hay más de una respuesta imprime cualquiera de ellas.

|| input
a8
h1
|| output
7
RD
RD
RD
RD
RD
RD
RD
|| end
