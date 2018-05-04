# Proyecto Final: Online Shopping

## Contexto
El objetivo del problema es obtener la mayor cantidad de descuentos posibles. 
Existen M tiendas en línea, los precios de los items varían en cada tienda. Cada tienda cuenta con los N elementos. Todas las tiendas ofrecen algún descuento. Si compra el elemento *ith* en una tienda, obtiene un cupón de descuento para el elemento *i+1th* de la misma tienda. Pero si compra el elemento *i+1th* de una tienda distinta, no puede obtener el descuento.

Nota: Si el descuento es mayor que el precio del item, es decir, Y-X < 0, el elemento es gratuito y no se regresa dinero.

## Breakdown
Es necesario analizar cada caso consistente en analizar dos rows continuas y obtener el valor mínimo. Conforme se recorren los N elementos, se va sumando el nuevo acumulado.

### Input
La primera línea contiene un entero T, el número de test cases.

Cada test case comienza con una línea que consiste en dos enteros, N y M.

Las siguientes N líneas consisten en M enteros separados por espacio. El número *jth* en la línea *ith* denota el precio del elemento *ith* en la tienda *jth*.

Las siguientes N líneas consisten en M enteros separados por espacio. El número *jth* en la línea *ith* denota el valor del cupón de descuento después de comprar el elemento *ith* en la tienda *jth*.

### Output
Para cada caso de prueba, en una línea se implime la cantidad mínima a gastarse para obtener los N elementos.

### Limitantes
1 ≤ T ≤ 10
2 ≤ N, M ≤ 100000
0 ≤ Prices, Discounts ≤ 1000000
1 ≤ T * N * M ≤ 1000000

## Solución
Se leen las entradas y se guardan en dos arreglos: precios y cupones.

Primero se obtiene el valor mínimo del primer row y se van almacenando los precios en un arrego auxiliar *dp*.

Después se recorre el arreglo de precios a partir de la segunda línea.
Para cada elemento, se calcula el precio del elemento *i, j* restándole el cupón en *i-1,j*. Posteriormente, se hace la comparación de qué valor es menor:
* El precio *i,j* menos el descuento o
* El precio del valor mínimo de la fila *i-1* de *dp*, donde se almacenan los acumulados de precios, más el precio actual, sin descuento.

El valor menor de ambos se almacena en el arreglo *dp* para cada tienda de se item.
Luego se vuelve a calcular del valor mínimo de la siguiente fila y se realiza el mismo procedimiento con las demás filas.

Cuando sea la última fila, se obtendrá del valor mínimo de todo el acumulado de precios para cada caso.


