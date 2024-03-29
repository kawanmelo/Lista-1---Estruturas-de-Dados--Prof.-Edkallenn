#include <stdio.h>
#include <stdbool.h>
bool eh_numero_armstrong(int n);

/*
  Função : Verificar números ade Armstrong
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 28.03.2023
  Observações: Null
*/

int main(void) {
  printf("Números de Armstrong entre 1 e 100:\n");
  for(int i = 1; i < 100; i++){
    if(eh_numero_armstrong(i)){
      printf("%d\n", i);
    }
  }
  return 0;
}


// Função : verifica se um número é um número de Armstrong
bool eh_numero_armstrong(int n) {
    int original = n;
    int somaDosCubos = 0;
    int digitos = 0;
    int number = n;
    while (number != 0) {
        number /= 10;
        digitos++;
    }
    number = original;
    while (number != 0) {
        int digito = number % 10;
        int cubo = 1;
        for (int i = 0; i < digitos; i++) {
            cubo *= digito;
        }
        somaDosCubos += cubo;
        number /= 10;
    }
    return somaDosCubos == original;
}