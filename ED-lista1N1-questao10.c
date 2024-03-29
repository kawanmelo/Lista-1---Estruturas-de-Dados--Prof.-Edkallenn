#include <stdio.h>
int* fibonacci_max(int max);

/*
  Função : Calcular série de Fibonacci com restrição máxima.
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 29.03.2023
  Observações: Null
*/

int main(void) {
  int *array = NULL;
  int n;
  printf("Digite um número inteiro: ");
  scanf("%d", &n);
  array = (int*) malloc(sizeof(int) * n);
  if(array == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  array = fibonacci_max(n);
  int count = 0;
  printf("\nSequência de Fibonacci com restrição máxima %d:\n ", n);
  do{
    printf("%d ", array[count]);
    count++;
  }while(array[count] != -1);
  return 0;
}

// Função : calcular sequencia de Fibonacci com restrição máxima.
int* fibonacci_max(int max){
  int* fibonacci = (int*) malloc(sizeof(int) * max);
  if(fibonacci == NULL){
    printf("Erro ao alocar memória");
    exit(1);
  }
  fibonacci[0] = 0;
  fibonacci[1] = 1;
  for(int i = 2; i < max; i++){
    fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
    if(fibonacci[i] > max){
      fibonacci[i] = - 1;
      return fibonacci;
    }else if(fibonacci[i] == max){
      fibonacci[i+1] = - 1;
      return fibonacci;
    }
  }
  return fibonacci;
}