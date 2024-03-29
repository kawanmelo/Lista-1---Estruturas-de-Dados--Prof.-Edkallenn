#include <stdio.h>
int Fatorial(int n);
double FatorialInverso(int n);
double soma_fatoriais_inversos(int n);
/*
  Função : Somar fatoriais inversos 
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 28.03.2023
  Observações: Null
*/

int main(void) {
  printf("Soma de fatoriais inversos:\n %f", soma_fatoriais_inversos(3));
  return 0;
}

// Função : Calcular fatorial simples.
int Fatorial(int n){
  if(n<0){
    printf("Não existe fatorial de número negativo");
    exit(1);
  }
  for(int i = n-1; i > 0; i--){
    n = n * i;
  }
  return n;
}

// Função : Calcular fatorial inverso.
double FatorialInverso(int n){
  double result;
  if(n<0){
    printf("Não existe fatorial de número negativo");
    exit(1);
  }
  result = 1.0 / (Fatorial(n));
  return result;
}

// Função : Somar fatoriais inversos.
double soma_fatoriais_inversos(int n){
  double soma = 0.0;
  while(n>0){
    soma = soma + FatorialInverso(n);
    n--;
  }
  return soma;
}