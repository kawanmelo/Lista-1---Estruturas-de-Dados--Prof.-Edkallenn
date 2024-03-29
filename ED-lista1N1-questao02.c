#include <stdio.h>
double fatorial_duplo(int n);
double fatorial(int n);

/*
  Função : Calcular fatorial dupla
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 26.03.2023
  Observações: Null.
*/

int main(void) {
  double fatorialDuplo[20];
  double fatorialSimples[20];
  double diferenca[20];
  int k=2;
  for(int i=0; i<20; i++){
    fatorialDuplo[i] = fatorial_duplo(k);
    fatorialSimples[i] = fatorial(k);
    diferenca[i] = fatorialSimples[i] - fatorialDuplo[i];
    k++;
  }

  printf("Número\t|\tFatorial Duplo\t\t\t|\tFatorial Simples\t\t\t|Diferença\n");
  printf("--------------------------------------------------------------------------------\n");
  int l =0;
  for (int i = 2; i <= 20; i++) {
      printf("%d\t|\t%.0f\t\t\t|\t%.0f |\t\t\t%.0f\n", i, fatorialDuplo[l], fatorialSimples[l], diferenca[l]);
    l++;
  }
  return 0;
}

// Função : Calcular fatorial duplo
double fatorial_duplo(int n){
  double resultado=1;
  if(n%2==0){
    for(int i = n; i >= 2; i -= 2){
      resultado *= i;
    }
    return resultado;
  }else{
    for(int i = n; i>=1; i-=2){
      resultado *= i;
    }
    return resultado;
  }
}


// Função : Calcular fatorial simples
double fatorial(int n){
  double resultado=1;
  for(int i = n; i >= 1; i--){
    resultado *= i;
  }
  return resultado;
}