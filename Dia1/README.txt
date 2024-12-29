Hemos elegido este problema ya que hemos visto que podemos emplear algoritmos de ordenación y busqueda vistos en clase, además que es bastante sencillo de realizar.

PARTE 1

Para la resolución de este problema, hemos creado dos vectores donde almacenamos los valores de cada columna. Para realizar las comprobaciones de las diferencias entre los numeros menores de cada vector, hemo pensado que será mucho más fácil si los dos vectores ya están ordenados. Para ello, hemos empleado uno de los algoritmos de ordenación vistos en la asignatura Quick Sort. Una vez ambos vectores ya estan ordenados, las comparaciones son mucho más sencillas.

La función addDiff se encarga de ello. Simplemente lleva un conteo de las diferencias entre los menores elementos de cada vector y cuando ha acabado devuelve la suma.

PARTE 2

Para la segunda parte se han añadido un par de funciones más, pero en esencia el planteamiento es bastante similar. COn los dos vectores ordenados, llamamos a la funcion "buscaRepeticiones" que hace uso de dos funciones más una llamada "counter" que lleva la cuenta de cuantas veces se repite el valor N en el vector y por otro lado un algotritmo de busqueda Binaria como hemos visto en clase. Con él, encontramos la primera posición del valor N en el vector.
Por otro lado, como el vector está ordenado, si hay varios valores iguales, se ha plantedo de manera que no se repita la busqueda si ya se ha buscado previamente el mismo valor usando "last" y "last_value". No llega a ser programación dinámica pero se le acerca un poco :).