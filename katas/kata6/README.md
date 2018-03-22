# Kata6: Shadows of the Knight - Episode 1

## Contexto
Batman debe buscar rehenes en un edificio, brincando de una ventana a otra. El objetivo es brincar hacia la ventana correcta dentro del límite de saltos disponibles antes de que explote una bomba.

## Reglas
Se dan las direcciones de la bomba de acuerdo a la posición actual de Batman
- U (UP)
- UR (Up-Right)
- R (Right)
- DR (Down-Right)
- D (Down)
- DL (Down-Left)
- L (Left)
- UL (Up-Left)

El programa debe indicar a Batman las coordenadas de la ventana a la cual debe realizar su siguiente salto.
Las ventanas están representadas en un arreglo de dos dimensiones, donde la ventana superior izquierda tiene los índices (0,0).

## Input
Se provee una entrada estándar, conforme los loops del programa, cada salida representa la entrada de la siguiente iteración.

### Inputs iniciales
*Integers W H. Ancho y Alto del edificio
*Integer N, máximo número de saltos.
*2 integers X0 Y0, posición inicial de Batman.

### Input de cada iteración
Dirección de la bomba

### Output de cada iteración
2 integers, (X, Y) que representa la ubicación de la siguiente ventana a la cual debe brincar.

### Constraints
1 ≤ W ≤ 10000
1 ≤ H ≤ 10000
2 ≤ N ≤ 100
0 ≤ X, X0 < W
0 ≤ Y, Y0 < H

## Solution

Dependiendo de cada entrada del jugador, se modificará la posición de Batman:

"R": x1 = X0 + 1 
"L": x2 = X0 - 1 
"D": y1 = Y0 + 1 
"U": y2 = Y0 - 1 

A partir de ello, buscamos el punto medio, que es a donde se debe dirigir en la siguiende iteración.

(X0, Y0)=((x1 + x2) / 2, ((y1+y2)/))
