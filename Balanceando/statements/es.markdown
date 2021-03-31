# Descipcion
dado un arreglo  que consta de $n$ números enteros $a_1$, $a_2$,…, $a_n$ y un entero positivo $m$. Se garantiza que $m$ es un divisor de $n$.

En un solo movimiento, se puede elegir cualquier posición $i$ entre $1$ y $n$ y aumentar $a_i$ en $1$.

Calculemos $c_r$ ($0$ $≤$ $r$ $≤$ $m − 1$) que son el número de elementos que tienen un residuo $r$ cuando se divide por $m$. En otras palabras, para cada residuo, debemos encontrar el número de elementos correspondientes en $a$ con ese residuo.

Tu tarea es cambiar el arreglo  de tal forma  que $c_0$ = $c_1$ = ⋯ = $c_m − 1$ = $\frac{n}{m}$. 
Encuentra el número mínimo de movimientos para satisfacer el requisito anterior.

# Entrada 
La primera línea de entrada recibes dos números enteros $n$ y $m$ ($1$ $≤$ $n$ $≤$ $2⋅10^5$, $1$ $≤$ $m$ $≤$ $n_1$ $≤$ $n$ $≤$ $2⋅10^5$, $1$ $≤$ $m$ $≤$ $n$). Se garantiza que $m$ es un divisor de $n$. La segunda línea de entrada contiene $n$ números enteros $a_1$, $a_2$,…, $a_n$ ($0$ $≤$ $a_i$ $≤$ $10^9$), los elementos del arreglo.

# Salida
En la primera línea, imprime un único entero: el número mínimo de movimientos necesarios para satisfacer la siguiente condición: para cada residuo de $0$ a $m − 1$, el número de elementos del arreglo que tienen este residuo es igual a $\frac{n}/{m}$.

En la segunda línea, imprima cualquier arreglo que satisfaga la condición y pueda obtenerse del arreglo original con el número mínimo de movimientos. Los valores de los elementos del arreglo resultante no deben exceder $10^{18}$.

|| input
6 3
3 2 0 6 10 12
||output
3
3 2 0 7 10 14
||input
4 2
0 1 2 3
||output
0
0 1 2 3 
|| end