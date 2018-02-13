##Kata3: Judge Route Circle

Asumiendo que el usuario ingresa un input válido con los caracteres U, D, L o R, se llama a una función makeCircle,
la cual hace lo siguiente:

1. Inicializa dos contadores en cero, uno para el eje x y otro para el eje y.
2. Recorre el string caracter por caracter y evalúa los caracteres, aumentando y disminuyendo cada contador dependiendo si va hacia arriba o abajo, o hacia la derecha o la izquierda.
3. Si ambos contadores terminan igual a cero, regresa verdadero, de lo contrario regresa falso.