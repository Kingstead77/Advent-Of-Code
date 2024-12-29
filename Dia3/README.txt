Hemos elegido este problema por que nos parecía interesante la busqueda de elementos concretos dentro de un texto. No hemos usado nada visto en la asignatura 

PARTE 1

Para este problema, igual que el anterior, procesamos una linea y luego pasamos a la de después. Obtenemos la linea con getline y la pasamos a la función "searchAndAdd". En esta funcion lo que hemos hecho es definir con "regex" un patron de texto que empiece por 'mul(' que contenga dos numeros de entre 1 y 3 dígitos separados por comas y que termine con ')'. Luego usamos coincidencias que es de tipo "smath" y es donde se almacenarán las coincidencias en caso de haberlas. 

Una vez hecho esto, se llama a la funcion "regex_search" pasandole el patrón anterior, coincidencias y la línea. En este punto del código, si ha habido coincindecias, se llama a la funcion "addMul" pasando como parámetro coincidencias. Esta funcion convierte a numeros el patron y hace los calculos que necesitamos.

Como puede que en una linea hayan más de un patrón, seguimos analizando la misma línea hasta que se termine y repetimos el proceso una y otra vez. Finalmente sacamos por pantalla la suma total.

PARTE 2

Para esta parte tenemos que tener dos consideraciones más: do() y don't(). Por ello creamos dos patrones más para poder identificarlos en las lineas. Luego nos dimos cuenta de que era más eficiente crear un patron que incluyera los tres para no tener que analizar las lineas varias veces. Entonces, se llama a la funcion "regex_search" con patronAll, si detecta un patrón, tenemos que averiguar cual de los tres es.
En caso de que sea el mul y no haya habido un don't antes, llamamos a la funcion que realizaba los cálculos. Si es un do() ponemos la variable "enableMul" a True, indicando que podemos hacer la mul en caso de encontar una. Si encontramos un don't() la pondremos a False hasta que apareca un do(). 