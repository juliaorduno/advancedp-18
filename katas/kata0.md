## Kata0: Two Sum

int n = *valor*
int a[] = *valor*
Para encontrar los índices que resultan el número del input:

1. Usar un for loop para recorrer todo el arreglo e ir agregando objetos a una hash table,
    donde el par (key:value) obtendrá los valores (número:índice).

2. Volver a recorrer el arreglo, en esta ocasión se toma el current value y se calcula la diferencia:
        int dif = n - *currentValue*
    Se realiza una búsqueda en la hashTable por valor contenido por la key *dif*. Dónde puede suceder:
    * El par key, value existe. Se termina el ciclo.
    * No existe el par, continúa el ciclo y se realiza la búsqueda por el siguiente valor del arreglo.

3. Una vez terminado el loop, se regresan los índices de *currentValue* y del valor de la key *dif*.