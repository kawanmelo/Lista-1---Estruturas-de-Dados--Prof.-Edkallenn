#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool eh_numero_perfeito(int n);

/*
  Função : Verificar números perfeitos
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 29.03.2023
  Observações: Null
*/

int main(void) {
  printf("Números perfeitos de 1 a 100000:\n");
  for(int i = 1; i <= 100000; i++){
    if(eh_numero_perfeito(i)){
      printf("%d\n", i);
    }
  }
  return 0;
}

// Função : verificar se um número é um número perfeito.
bool eh_numero_perfeito(int n){
  int numeroOriginal = n;
  int soma = 0;
  for(int i = 1; i < n; i++){
    if(n % i == 0){
      soma += i;
    }
  }
  if(soma == numeroOriginal){
    return true;
  }
  return false;
}