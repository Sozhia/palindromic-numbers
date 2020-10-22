# Productos capicúa

## 0.- Introducción
Un palíndromo es una palabra, número o frase que se lee igual de izquierda a derecha que de derecha a izquierda. Ejemplos de palíndromos son las palabras arenera, Ana, arepera o reconocer. Si se trata de un numeral, usualmente en notación indoarábiga, al palíndromo se le denomina número capicúa.

Teniendo en cuenta esta definición, se puede observar que el mayor número capicúa obtenido como el producto de dos números de dos dígitos, es el 9009:

`9009 = 91 × 99`

Análogamente, 99000099 es el mayor número capicúa obtenido como producto de dos números de cuatro dígitos:

`99000099 = 9999 × 9901`

## 1.- Ejercicio práctico
Diseñar e implementar en C++ un programa `palindrome_prod.cc` que, dado un número entero `n > 0`, encuentre los números capicúas resultantes de multiplicar dos números de n dígitos cada uno. El programa deberá almacenar en un fichero de texto esos números capicúas usando una línea diferente para cada producto, de forma que un ejemplo de línea de ese fichero serían los dos productos anteriores. Como entrada el programa recibirá por línea de comandos el número n y el nombre de un fichero de salida para almacenar los números capicúa, de modo que el programa se ejecutará como:

`$> ./palindrome_prod n output.txt`

siendo `n` el número de dígitos de los factores que producen los números capicúa.

## 2.- Razonamiento

* Al ejecutar el código debemos controlar que sea el formato correcto y el orden correcto. Es decir, un número que representa los digitos máximos ha multiplicar y un fichero externo. De no ser ninguno de los dos casos debemos mostrar un comando por pantalla `./palindrome_prod --help` que muestre al usuario el funcionamiento del programa.

* Controlaremos que si el fichero existe o no. En caso de existir escribiremos en la línea inferior la fecha de la última ejecución y sus pertinentes productos capicúa. En caso contrario, crearemos dicho fichero y procederemos del mismo modo.

* Dados los requisitos de esta actividad, necesitamos una estructura para almacenar los datos con los que voy a trabajar. En mi caso he optado por un `std::vector<number>` de tamaño `n x n` al que llamaré `palindrom_holder`, donde number será:

```c++
struct Number{
  unsigned int multiplicand, multiplier, value;
  bool palindromic;
};
```

* Manejamos el vectir rellenando con la información pertinente, comprobando si es capicúa o no cada producto con `bool IsPalindromic (unsigned int number)`, asignandole el `return` al `palindromic` del `struct`.
* Una vez finalizado el procedimiento anterior, borraremos y redimensionaremos el vector con todos los `palindromic = false;` encontrados. Posteriormente llamaremos a `void WriteFile ()` que escribirá en el fichero con el siguiente formato `product = multiplicand * multiplier`.