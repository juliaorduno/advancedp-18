# Kata9: UTF-8 Validation

## Contexto
La codificación de UTF-8 sucede de la siguiente manera:
`Char. number range  |        UTF-8 octet sequence        (hexadecimal)    |              (binary)     --------------------+---------------------------------------------     0000 0000-0000 007F | 0xxxxxxx     0000 0080-0000 07FF | 110xxxxx 10xxxxxx     0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx     0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  `

## Input
- data, array of integers

## Output
- Regresa un booleano indicando si el código es válido o no.

## Constraints

Un caracter en UTF-8 puede ser de 1 a 4 bytes de largo, sujeto a las siguientes reglas:
- 1-byte: El primer bit es cero, seguido por su unicode.
- n-bytes: Los primeros n-bits son 1's, seguido por un 0, seguido por n-1 bytes con sus 2 bits más significativos iguales a 10.

## Breakdown
- Sólo es necesario analizar los n-bytes y sus bytes consiguientes.
- Los que sean sólo un byte, pueden pasar desapercibidos.
- Del primer byte en caso de n > 1: analizar los primeros 1's para conocer el número de bytes.
- De los bytes consiguientes al primer byte de n > 1: analizar sólo que los primeros 2 bits sean 10.

## Solution
- Recibo de input el tamaño del arreglo y su contenido.
- Inicializo dos booleanos (int) *nth_byte* y *is_valid* igual a falso (o sea, 0) y *is_valid* igual a 1.
- Recorro el arreglo, por cada entero obtengo su arreglo de *bits*.
- En caso de que *nth_byte* sea 0 y el primer bit es igual a 1, es decir, se inicia un n-byte, recorro dicho byte para obtener la cantidad de bytes y voy aumentando *nth_byte* como contador. Además, seteo *is_valid* igual a 0.
- En caso de que *nth_byte* > 0, le resto 1 y mientras *nth_byte* siga así, verifico que los siguientes bytes inicien con 10, en caso de que cumpla con las restricciones, seteo *is_valid* igual a 1 (verdadero).
- De lo contrario rompo el ciclo.

