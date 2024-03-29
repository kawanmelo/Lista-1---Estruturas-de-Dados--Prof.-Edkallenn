#include <stdio.h>
#include <stdlib.h>
int verificar_automorfico(int n);
void verificaAutomorficoAteN(int begin, int end);
/*
  Função : Verificar números automórficos
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 27.03.2023
  Observações: Null
*/

int main() {
  printf("Verificando números automorficos até 1000:\n");
  verificaAutomorficoAteN(2, 1000);

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Verificando números automorficos até n:\n");

  int n;
  printf("Digite um número: ");
  scanf("%d", &n);

  verificaAutomorficoAteN(1, n);

  return 0;
}

// Função : Verifica se um número é automórfico
int verificar_automorfico(int n){
  int quadrado = n*n;
  while(n>0){
    if(n%10 != quadrado%10){
      return 0;
    }
    n /= 10;
    quadrado /= 10;
  }
  return 1;
}

// Função : Verifica todos os números automórficos em um intervalo.
void verificaAutomorficoAteN(int begin, int end) {
  int count = 0;
  int *automorficos = NULL;

  for (int i = begin; i <= end; i++) {
    if (i > 0) {
      if (verificar_automorfico(i)) {
        automorficos = (int *)realloc(automorficos, (count + 1) * sizeof(int));
        if (automorficos == NULL) {
          printf("Erro de alocação de memória.\n");
          exit(1);
        }
        automorficos[count] = i;
        count++;
      }
    }
  }

  printf("Números automorficos entre %d e %d:\n", begin, end);
  for (int i = 0; i < count; i++) {
    printf("%d\n", automorficos[i]);
  }

  free(automorficos);
}
