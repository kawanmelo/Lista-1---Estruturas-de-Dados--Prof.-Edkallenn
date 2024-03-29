#include <stdio.h>
int verificaDivisorAmigavel(int a, int b);
void verificaDivisorAmigavelAteN(int n, int z[], int w[]);
/*
  Função : Calcular divisores amigaveis
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 27.03.2023
  Observações: Null
*/

int main(void) {
  int n=0;
  int arr1[20];
  int arr2[20];
  printf("Digite um valor para n: ");
  scanf( "%d", &n);
  verificaDivisorAmigavelAteN(n, arr1, arr2);
  return 0;
}

int verificaDivisorAmigavel(int a, int b){
  int divisoresA[100];
  int divisoresB[100];
  int somaDivisoresA = 0;
  int somaDivisoresB = 0;
  int k=0;
  int l=0;
  if(a == b){
    return 0;
  }
  for(int i = a-1; i>=1; i--){
    if(a%i==0){
      divisoresA[k] = i;
      k++;
    }
  }
  
  for(int i = b-1; i>=1; i--){
    if(b%i==0){
      divisoresB[l] = i;
      l++;
    }
  }

  for(int i = 0; i<k; i++){
    somaDivisoresA += divisoresA[i];
  }
  for(int i = 0; i<l; i++){
    somaDivisoresB += divisoresB[i];
  }
  if(somaDivisoresA == b && somaDivisoresB == a){
    printf("\n%d e %d são divisores amigáveis\n", a, b);
    printf("\nDivisores de %d: ", a);
    for(int i=0; i<k; i++){
      printf("%d ",divisoresA[i]);
    }
    printf("\nDivisores de %d: ", b);
    for(int i=0; i<l; i++){
      printf("%d ", divisoresB[i]);
    }
    printf("\nSoma dos divisores de %d:  %d\n", a, somaDivisoresA);
    printf("\nSoma dos divisores de %d:  %d\n", b, somaDivisoresA);
    return 1;
  }else{
    
  return 0;
  }
}

void verificaDivisorAmigavelAteN(int n, int z[], int w[]){
  int o=0;
  for(int i = 1; i<=n; i++){
    for(int j = i; j<=n; j++){
    int result =  verificaDivisorAmigavel(i, j);
      if(result == 1){
        z[o] = i;
        w[o] = j;
        o++;
      }
    }
  }
  for(int i=0; i<o; i++){
    printf("\n%d e %d são divisores amigavéis\n", z[i], w[i]);
  }
}