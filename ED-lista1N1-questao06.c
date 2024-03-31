#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool VerificaCongruencia(int a, int b, int c);
bool VerificaCoPrimos(int a, int b);
bool verificar_numero_carmichael(int n);

/*
  Função : Verificar se um número é de Carmichael
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 29.03.2023
  Observações: Null
*/

int main() {
  int num = 0;
  printf("Digite um número: ");
  scanf("%d", num);
  printf("Exibindo números de carmichael de 2 até %d: ", num);
  for (int i = 2; i <= num; i++) {
    if(verificar_numero_carmichael(num)){
      printf("O número %d é de Carmichael", num);
    }
  }
}

// Função : Verificar se a e b são CoPrimos entre si.
bool VerificaCoPrimos(int a, int b) {
  if (a == b) {
    return false;
  }
  int *divisoresA = NULL;
  divisoresA = (int *)malloc(sizeof(int) * a);
  int *divisoresB = NULL;
  divisoresB = (int *)malloc(sizeof(int) * b);
  if (divisoresA == NULL || divisoresB == NULL) {
    printf("Erro ao alocar memória!");
    exit(1);
  }
  // Calculando os divisores de a, exceto o número 1;
  int countA = 0;
  for (int i = 2; i <= a; i++) {
    if (a % i == 0) {
      divisoresA[countA] = i;
      countA++;
    }
  }
  // Calculando os divisores de b, exceto o número 1;
  int countB = 0;
  for (int i = 2; i <= b; i++) {
    if (b % i == 0) {
      divisoresB[countB] = i;
      countB++;
    }
  }
  // Verificando se há divisores em comum entre os dois números;
  int i = 0, j = 0;
  while (i < countA && j < countB) {
    if (divisoresA[i] == divisoresB[j]) {
      return false;
    } else if (divisoresA[i] < divisoresB[j]) {
      i++;
    } else {
      j++;
    }
  }

  return true;
}

// Função : Verificar congruência entre a, b e c. ( a ≡ b (mod c) )
bool VerificaCongruencia(int a, int b, int c){
  return (a % c == b % c);
}

// Função : Verificar se o número é de Carmichael.
bool verificar_numero_carmichael(int n) {
  // Verifica se o número não é primo
  for (int i = 2; i < n; ++i) {
    if (n % i == 0) {
      // Se encontrar um divisor, não é um número de Carmichael
      return false;
    }
  }

  // Verifica para todos os a entre 1 e n-1 se a e n são coprimos e a^(n-1) ≡ 1
  // (mod n)
  for (int a = 2; a < n; ++a) {
    if (VerificaCoPrimos(a, n)) {
      if (!VerificaCongruencia(pow(a, n - 1), 1, n)) {
        // Se uma das condições falhar, não é um número de Carmichael
        return false;
      }
    }
  }

  // Se passar por todas as condições, é um número de Carmichael
  return true;
}
