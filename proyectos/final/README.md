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
Después de leer las entradas, se recorre el arreglo de precios de cada test case.
Para cada elemento, se calcula el precio del elemento *i+1, j* restándole el cupón. Posteriormente, se recorre cada elemento de la fila *i+1* manteniendo una referencia al valor mínimo encontrado y actualizandola en caso de ser necesario.

Se realiza el procedimiento de cada elemento de la fila *i* y se saca el valor mínimo encontrado para dicha fila.
Posteriormente, se realiza el mismo procedimiento con las demás filas.
Se cuenta con un acumulador para ir sumando los valores de cada row.

