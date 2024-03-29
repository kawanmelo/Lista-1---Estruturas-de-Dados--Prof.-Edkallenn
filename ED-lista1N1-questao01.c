#include <stdio.h>
long int potencia_fatorial_crescente(int x, int n);
long int potencia_fatorial_decrescente(int x, int n);

/*
  Função : Calcular potência fatorial crescente e decrescente
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 26.03.2023
  Observações: Null
*/

int main(void) {
  long int resultado_crescente[12];
  long int resultado_crescente_variandoX[12];
  long int resultado_decrescente[12];
  long int resultado_decrescente_variandoX[12];
  int j=0;
  int k=0;
  int m = 7;
  for(int i=2; i<=10; i++){
    resultado_crescente[k] = potencia_fatorial_crescente(7, i);
    k++;
    resultado_decrescente[j] = potencia_fatorial_decrescente(7, i);
    j++;
  }
  j=0;
  k=0;
  for(int i=2; i<=10; i++){
    resultado_crescente_variandoX[k] = potencia_fatorial_crescente(i, 7);
    k++;
    resultado_decrescente_variandoX[j] = potencia_fatorial_decrescente(i, 2);
    j++;
  }
  printf("Fatorial Crescente:\n");
  printf("\nVariando o valor de n de 2 a 10, (x = 7) temos:\nn=2: %ld\nn=3: %ld\nn=4: %ld\nn=5: %ld\nn=6: %ld\nn=7: %ld\nn=8: %ld\nn=9: %ld\nn=10: %ld\n\n", resultado_crescente[0], resultado_crescente[1],resultado_crescente[2], resultado_crescente[3], resultado_crescente[4],resultado_crescente[5], resultado_crescente[6], resultado_crescente[7], resultado_crescente[8]);
  
  printf("\nVariando o valor de i de 2 a 10, (i = 7) temos:\nx=2: %ld\nx=3: %ld\nx=4: %ld\nx=5: %ld\nx=6: %ld\nx=7: %ld\nx=8: %ld\nx=9: %ld\nx=10: %ld\n\n", resultado_crescente_variandoX[0], resultado_crescente_variandoX[1],resultado_crescente_variandoX[2], resultado_crescente_variandoX[3], resultado_crescente_variandoX[4],resultado_crescente_variandoX[5], resultado_crescente_variandoX[6], resultado_crescente_variandoX[7], resultado_crescente_variandoX[8]);

  printf( "\n\nFatorial Decrescente:\n");
  
  printf("\nVariando o valor de n de 2 a 10, (x = 7) temos:\nn=2: %ld\nn=3: %ld\nn=4: %ld\nn=5: %ld\nn=6: %ld\nn=7: %ld\nn=8: %ld\nn=9: %ld\nn=10: %ld\n\n", resultado_decrescente[0], resultado_decrescente[1],resultado_decrescente[2], resultado_decrescente[3], resultado_decrescente[4],resultado_decrescente[5], resultado_decrescente[6], resultado_decrescente[7], resultado_decrescente[8]);

  printf("\nVariando o valor de i de 2 a 10, (i = 2) temos:\nx=2: %ld\nx=3: %ld\nx=4: %ld\nx=5: %ld\nx=6: %ld\nx=7: %ld\nx=8: %ld\nx=9: %ld\nx=10: %ld\n\n", resultado_decrescente_variandoX[0], resultado_decrescente_variandoX[1],resultado_decrescente_variandoX[2], resultado_decrescente_variandoX[3], resultado_decrescente_variandoX[4],resultado_decrescente_variandoX[5], resultado_decrescente_variandoX[6], resultado_decrescente_variandoX[7], resultado_decrescente_variandoX[8]);
  
  return 0;
}


// Função : calcular potência fatorial crescente
long int potencia_fatorial_crescente(int x, int n){
  long int acumulador = x * (x+1);
  for(int i = 2; i < n; i++){
    acumulador = acumulador * (x + i);
  }
  return acumulador;
}

// Função : calcular potência fatorial decrescente
long int potencia_fatorial_decrescente(int x, int n){
  long int acumulador = x * (x-1);
  for(int i = 2; i < n; i++){
    acumulador = acumulador * (x - i);
  }
  return acumulador;
}