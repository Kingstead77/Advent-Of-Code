Para este problema tampoco hemos utilizado nada de lo visto en la asignatura pero de igual manera lo hemos hehco.

PARTE 1

En primer lugar, hemos almacenado las reglas en un vector de pares vector<pair<int, int>>. Originalmente tenemos el vector relleno de -1 que indica que está vacío. Leemos la regla, y separamos el primer dígito del segundo y los almacenamos en first y second dentro de la misma posicion del vector.

Una vez ya tenemos almacenadas todas las reglas que lo sabemos porque entre las normas y las series de numeros hay una linea en blanco, por lo que el primer carácter de la lineas es un \n.

Lo siguiente es procesar las series de numeros. Para ello, la condicion de continuar el programa es llegar hasta el final del archivo. Leemos una linea almacenamos en un vector entero los valores separados por ','.

Ahora la lógica que hemos implementado es la siguiente. recorremos el vector y comparamos cada elemento con los numeros de la primera regla. En el momento que se encuentre uno de los dos numeros se guarda la posición en la que está. Por ejemplo si primero se encuentra el 40 en la posición 3 y luego el 70 en la 6 y la norma que estabamos comprobando es 40|70 podemos decir que si que cumple (por ahora) las normas. Este proceso se cumple con todas las normas, si al final so ha habido ninguna regla incumplida retornamos un True, en caso contrario un false.

PARTE 2

Lo que se nos ha ocurrido par ordenar la linea en funcion de las normas es intercambiar las posiciones de los elementos que están mal. Por ejemplo, si 40 está despues de 70, se intercambian y ya cumpliriamos esta norma. No obstante, al hacer este intercambio podemos haber  incumplido una norma que previamente habiamos respetado. Es por esto que estas operaciones las hacemos dentro de un bucle while cuya condicion es que esté la linea desordenada. De tal manera que, eventuelmente, la linea cumplirá todas las reglas (suponemos que hay una combinacion correcta para todos las series) y podrá salir del bucle. No es un enfoque eficiente pero funciona.

Por último, de obtenemos el valor medio de cada linea correcta y lo sumamos.