Hemos decidido hacer este problema ya que es sencillo a pesar de que no hemos utilizado nada de lo nuevo visto este curso.

PARTE 1

Para este problema, obtenemos de 1 en uno las lineas del txt, las convertimos en un vector, hacemos las comprobaciones necesarias y pasamos a la siguiente linea.

Utilizamos getline para leer una linea y pushback para ir almacenando los valores. Para hacer las comprobaciones simplemente llamamos a la funcion de "is_safe" que devuelve True si la serie es segura y False si no lo es. En caso de que si lo sea, incrememtamos el contador.

PARTE 2

Como ahora podemos tolerar un error, lo que hemos pensado es llamar a la función eliminando un elemento del vector en cada llamada. De manera que la primera vez se elimina el primer elemento, luego el segundo, pero el primero vuelve a estar operativo y así sucesivamente. De esta manera, si al eliminar un elemento de una serie defectuosa obtenemos que puede ser segura, devuelve un True, en caso contrario, despues de haber probado todas las combinaciones sigue siendo mala, devolvemos False. 

Ahora tenemos que comprobar las dos funciones "is_safe" y "is_safe_with_dampener", si cualquiera de las dos devuelve un valor positivo, inrementamos el corntador.

