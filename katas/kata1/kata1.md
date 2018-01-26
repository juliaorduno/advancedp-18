## Kata0: Anagram Mapping

Implementé un pequeño programa en C (de principiante) el cual:

1. Recibe como inputs el tamaño de los arreglos y los valores de cada uno -asumiendo que el usuario no cometerá el error de poner
    valores distintos en ambos arreglos A y B.

2. Usando dos ciclos anidados busca cada valor de A dentro de B hasta encontrar el valor y guarda en índice dentro de P (el arreglo de índices).

La complejidad del programa es O(n^2). Sin embargo, podría mejorarse a un O(n) si se utiliza una Hash Table, recorriendo A y guardando los valores como keys y los índices como los values y, finalmente, recorrer B y buscar los índices en la hash table.