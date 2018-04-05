# Proyecto Parcial 2: Pegman

## Contexto
Al usar Google Street View, un usuario va a posicionar a Pegman en una celda de un una cuadríacula rectangular con R filas y C columnas. Cada célular puede estar en blanco o puede estar etiquetada con una flecha apuntando a una de las cuatro posibles direcciones: arriba, abajo, a la derecha o a la izquierda.

Cuando se posiciona a Pegman en una celda, si la celda está en blanco, Pegman se mantiene quieto para siempre. Sin embargo, si la celda tienen una flecha, Pegman comienza a caminar en esa dirección. Mientras cmaina, Cuando encuentra una celda en blanco, sigue caminando en la misma dirección; pero si encuentra una celda con una flecha distinta, cambia de dirección y sigue caminando.

Es posible que Pegman pueda seguir caminando por la cuadrícula para siempre, pero también es posible que llegue al límite de la misma. Se puede prevenir este evento cambiando la dirección de una o más flechas. (Cada flecha puede cmaibarse a una de las otras tres direcciones, sólo pueden cambiarse, no pueden añadirse o eliminarse).

¿Cuál es la mínima cantidad de flechas que tienes que cambiar para asegurar que Pegman no se pasará de los límites de la cuadrícula, sin importar en donde se posiciona inicialmente?

## Breakdown

### Input
La primera línea de input da el número de test cases T. Prosiguen T test cases. Cada test comienza con una línea con dos enteros separados por un espacio: R y C. De esta línea siguen R líneas, cada una con C caracteres, cada uno describe una celda y puede contener una de las siguientes opciones:

. period = no arrow
^ caret = up arrow
> greater than = right arrow
v lowercase v = down arrow
< less than = left arrow

### Output
Para cada test case, se imprime una línea conteniendo "Case #x: y", donde x es el número de test case (empezando por 1) y y es el mínimo número de flechas que deben ser cambiadas para asegurar que Pegman no dejará la cuadrícual sin importar donde es su posición inicial, o el texto "IMPOSSIBLE" si no es posible asegurar eso, sin importar cuantas flechas cambies.

Límites
1 ≤ T ≤ 100.
Small dataset
1 ≤ R, C ≤ 4.
Large dataset
1 ≤ R, C ≤ 100.

## Solución
Se recorre toda la matriz para verificar el path de cada caracter. Si aparece un '.' se ignora. En caso de que sea una flecha, se hace un recorrido de acuerdo a la dirección de la misma, si los caracteres siguientes son puntos y sale de los límites, se realiza cambio de dirección a la flecha. 

Para cada cada cambio de flecha, se realiza un recorrido donde se verifica que no salga de los límites, con las mismas validaciones del recorrido general. Si ninguna dirección evita que salga de la matriz, se arroja un "IMPOSSIBLE". De lo contrario, se aumenta el contador de minChanges y continúa en el recorrido principal.

Este procedimiento se realiza para cada test case.

