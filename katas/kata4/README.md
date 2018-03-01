##Kata4: Valid Number

###Contexto
Es necesario desarrollar una función que indique si una cadena de caracteres contiene un valor numérico o no. Los casos aceptables son:
* 1
* 0.1, .1
* +1, -1
* 1e2, 1e+2, 1e-1
* 1,000, 1,000.00

Estos fueron algunos ejemplos, derivados de éstos también serán aceptados, es decir, combinación de caracteres como ', . e + -'. Casos que serán rechazados son:
* 1.
* 1,1
* 1e3.4
* 1+1

Entre otros casos evidentes de valores no aceptados en el contexto -letras, otros caracteres especiales, repetición de puntos,...-

###Breakdown
Comencé a partir de los casos más simples a los más complejos. Desde números enteros, decimales, exponenciales, con comas, espacios, signos y combinación de algunos. Utilicé los valores ASCII para establecer rangos de caracteres aceptados. 

###Solución
La función que utilicé consiste en recorrer todo el arreglo de caracteres, utilizando 3 whiles y condicionales:
1. El primer while recorre la cadena en caso de que contenga espacios antes de que comiencen los demás caracteres.
2. Puse una condicional que acepte un caracter '+' o '-' como primer elemento del número.
3. El while principal recorre los caracteres validando si:
    * El caracter es un número.
    * Si contiene decimal
    * Si es exponencial
    * Si tiene comas
    Además contiene restricciones que evite aceptar casos especiales como puntos después del exponente, mal uso de comas, punto como caracter último
4. Finalmente hay un while final, idéntico al inicial, para eliminar espacios al final.
5. La función regresa 1 en caso de que sea válido, si no se cumple con alguna validación, regresa 0.