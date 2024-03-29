#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool eh_numero_feliz(int num);
/*
  Função : Verificar números felizes
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 28.03.2023
  Observações: Null
*/

int main(void) {
  if(eh_numero_feliz(7)){
    printf("É um número feliz\n");
  }else{
    printf("Não é um número feliz\n");
  }
  if(eh_numero_feliz(4)){
    printf("É um número feliz\n");
  }else{
    printf("Não é um número feliz\n");
  }
  return 0;  
}


//Função : verificar se o número é feliz
bool eh_numero_feliz(int num) {
    int visitados[1000];
    int somaQuadrados;

    while (true) {
        somaQuadrados = 0;
        while (num) {
            somaQuadrados += (num % 10) * (num % 10);
            num /= 10;
        }
        if (somaQuadrados == 1) {
            return true;
        }
        if (visitados[somaQuadrados] == 1) {
            return false;
        }
        visitados[somaQuadrados] = 1;
        num = somaQuadrados;
    }
}