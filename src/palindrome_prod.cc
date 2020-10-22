/* @autor: Miqueas (Sozhia) García González
** @email: sozhia.business@gmail.com
** @web: https://github.com/Sozhia
** @date: 16/10/2020
** @file_name: palindrome_prod.cc
** @description: Al pasarle dos parámetros por la línea de comandos (n, numero entero
** y nombre de fichero), imprimirá en dicho fichero los palíndromos resultantes de los
** productos desde 1x1 hasta nxn.
*/

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>

// Constants

const std::string instructions1 = "Por favor introduzca un valor 1-9 y un fichero de salida. Ejemplo: ";
const std::string instructions2 = "./palindrome_prod 3 salida.txt";

struct Number{
  unsigned int multiplicand, multiplier, value;
  bool palindromic;
  // Sobrecarga operador < ordenar según value creciente
  bool operator < (const Number &position) const {
    return value < position.value;
  }
};

// Funciones
void PrintHelp();
unsigned int Invert (unsigned int number);
bool IsPalindromic(unsigned int number);
void CreateVector(std::vector<Number>& vector, unsigned int size);
unsigned int Power(unsigned int exp);
unsigned int GetMaxRange(unsigned int digits);
void SortVector( std::vector<Number>& vector);
void TestVector( std::vector<Number>& vector);
void WriteFile(std::vector<Number>& vector);


void PrintHelp() {
  std::cout << instructions1 << std::endl;
  std::cout << instructions2 << std::endl;
}
// Funcion para invertir numero
unsigned int Invert (unsigned int number) {
  unsigned int inverted;
  while (number > 0) {
  inverted = (inverted * 10) + (number % 10);
  number = number / 10;
  }
  return inverted; 
}
// Comprobamos si el número introducido es capicúa invirtiendo y comparando
bool IsPalindromic (unsigned int number) {
  if (number < 10 ) {
  	return true;
  } else if (number == Invert(number)) {
    return true;
  } else {
    return false;
  }
}

// Escribimos en el fichero
void WriteFile(std::vector<Number>& vector) {
  
  std::ofstream file;
  if (file.fail()) {
    std::cout << "Error al crear archivo" << std::endl;
    exit(1);
  }else{
    file.open("capicua.txt", std::ofstream::out);
    for (unsigned int i = 0; i < vector.size(); i++) {
      if (vector[i].palindromic == true){
        file <<vector[i].multiplicand;
        file << " * ";
        file <<vector[i].multiplier;
        file << " = ";
        file <<vector[i].value;
        file << "\n";
      }
    }
    file.close();
  }
}

unsigned int GetMaxRange(unsigned int digits) {
  unsigned int max_range;
  max_range = Power(digits);
  return max_range-1;
}
unsigned int Power(unsigned int exp) {
  unsigned int power = 1;
  for(unsigned int i = 1;i <= exp; i++)
    power=power*10;
  return power;
}


// Creamos el vector y rellenamos con los productos
void CreateVector(std::vector<Number>& vector, unsigned int size) {
  unsigned int contador = 0 ;
  unsigned int dimension = size;
  vector.resize(dimension);
  for (unsigned int control1 = 1; control1 < size; control1 ++) {
    for (unsigned int control2 = 1; control2 < size; control2 ++) {
      vector[contador].multiplier = control1;
      vector[contador].multiplicand = control2;
      vector[contador].value = control1 * control2;
      if (IsPalindromic(vector[contador].value)) {
        vector[contador].palindromic = true;
      }else{
        vector[contador].palindromic = false;
      }
	    contador++;    
    }
  }
}

// Ordena vector según <
void SortVector( std::vector<Number>& vector) {
    std::sort(vector.begin(), vector.end());
}

void TestVector(std::vector<Number>& vector) {
  for (unsigned int i = 0; i < vector.size(); i++) {
    std::cout << "Posicion" << i << " : "<< std::endl;
    std::cout << vector[i].multiplier << " * " << vector[i].multiplicand;
    std::cout << " = " << vector[i].value;
    if (vector[i].palindromic == true){
      std::cout << " Capicua"<<std::endl;
    }else{
      std::cout << " No Capicúa " <<std::endl;
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2){
    std::cout << "Cuantía de argumentos no válida" << std::endl ;
    PrintHelp();
    exit(1);
  }
  if (atoi(argv[1]) < 1 ) {
    PrintHelp();
    exit(1);
  }
  
  std::vector<Number> palindromic_holder;
  unsigned int digits = atoi(argv[1]);
  CreateVector(palindromic_holder,GetMaxRange(digits));
  SortVector(palindromic_holder);
  WriteFile(palindromic_holder);
  
}
