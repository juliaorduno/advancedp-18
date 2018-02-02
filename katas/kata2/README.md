## Kata2: Strong Password Checker

Para realizar esta kata, en el método 

* int strongPasswordChecker(char *password)

Primero inicialicé variables para 
1. Contar los cambios mínimos necesarios
2. Contar la cantidad de letras repetidas
3. Booleanos para saber si tiene mayúscula, minúscula y número
4. Asignar el valor ascii de cada caracter

Luego verifico que esté dentro del rango de caracteres necesarios, de no estarlo, cuento como cambio cada caracter de diferencia.

Después, dentro de un for loop, analizo cada caracter, dentro del mismo:
* Verifico si antes del caracter había uno igual, de ser así aumento la variable de repeated. De no ser así, si ya se había repetido algún valor, reasigno a la variable la cantidad caracteres repetidos antes de comenzar con el actual caracter, por ejemplo:
    + Si tenemos aaabbbccd, al llegar a la segunda c, repeated es igual a 5, al leer una d después, repeated regresa al valor de 4.
*  Después checo si el caracter es mayúscula, minúscula o número, en caso de que aún no se haya detectado alguno previamente.
* Finalmente, en caso de que algún booleano siga falso, es decir, el entero es = 0, se suma otro cambio mínimo necesario por cada uno. Posteriormente, se suman el número de grupos de letras repetidas.
* La función regresa minimumChanges

