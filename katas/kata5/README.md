## Kata5: Infograph

### Contexto
Se requiere crear un programa que lea de entrada una cadena de caracteres y utiliza un word cloud donde el tamaño de cada palabra depende del número de veces que aparece dentro del string.

Se debe utilizar una hash table para almacenar las palabras como llaves y el número de veces como los valores:
 * key: word (string)
 * value: times (int)

Si una palabra contiene mayúsculas, debe normalizarse con puras minúsculas.

### Breakdown
* Utilizar hash table word/times
* Input: string
* Output: cada palabra con el número de veces que aparece
* No diferenciar mayúsculas y minúsculas

### Solución
* Se guarda el string dentro de un arreglo de caracteres.
* Iterar el arreglo, guardar cada palabra dentro de la hash table utilizando espacios como separadores y signos de puntuación como separadores.
* Si el par key/value de la palabra no existe en la tabla, agregarlo con valor igual a 1.
* Si el par key/value de la palabra ya existe en la hash table, aumentar el valor en 1.
* Iterar en la hash table e imprimir los resultados.

