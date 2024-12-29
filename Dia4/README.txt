Hemos elegido este problema por que nos gustaba y nos parecía interesante, pero no se nos ha ocurrido ninguna forma de implementar nada visto en la asignatura de PRA. No obstante, nos ha recordado mucho a la roomba del año pasado :v

PARTE 1

Este problema lo hemos planteado como una matriz, en la que en cada letra es una celda de la misma. La idea es tratar el problema como una sopa de letras y por ello, la manera en que hemos pensado resolverlo es la siguiente:

Como la palabra que queremos encontrar es XMAS, necesariamente debemos encontrar una X. Una vez encontremos una X realizaremos una busqueda en cada una de las 8 direcciones posibles, es decir, en sus celdas contiguas en caso de tenerlas (dentro de límites). En estas casillas buscaremos la siguiente letra, la M. Si no la encontramos, retornamos un 0 pero si la hemos encontrado retornamos un 1 que incrementa la varieble "n". Como sin contar la X nos quedan por encontrar tres letras, quiere decir que cuando n = 3, se habría encontrado la palabra XMAS en cuelquiera de las direcciones. Es entonces cuando se incrementa el contador y se pasa a la siugiente celda.

Se recorre la matriz en un bucle anidado celda por celda.

PARTE 2

De la manera que hemos planteado la parte 1, nos resulta bastante sencillo modificar el código para buscar X-MAS en forma de X ya que simplemente tenemos que encontrar una A y analizar las 4 posibilidades de sus diagonales. En caso de encontrar una M y una S en las opuestas pues ya lo tendrías. para ello hemos creado una funcion llamada "verificar_diagonal" que se encarga precisamente de esto. Devuelve True si la hemos encontrado y False si no y en funcion de esto incrementamos el contador o no.