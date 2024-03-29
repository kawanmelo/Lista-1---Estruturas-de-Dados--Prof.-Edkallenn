#include <stdio.h>
int VerificaCongruencia(int a, int b, int c);
int VerificaCoPrimos(int a, int b);
int verificar_numero_charmichael(int n);

/*
  Função : Verificar se um número é de Carmichael
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 29.03.2023
  Observações: Null
*/

int main(void) {
  int result = verificar_numero_charmichael(572);
  if (result == 1) {
    printf("O número é de Carmichael\n");
  } else {
    printf("O número não é de Carmichael\n");
  }
  return 0;
}

// Função : Verificar congruência entre a, b e c. ( a ≡ b (mod c) )
int VerificaCongruencia(int a, int b, int c) { return (a % c == b % c); }

// Função : Verificar se a e b são CoPrimos entre si.
int VerificaCoPrimos(int a, int b) {
  if (a <= 1 || b <= 1) {
    return 0;
  }
  for (int i = 2; i <= (a < b ? a : b); i++) {
    if (a % i == 0 && b % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Função : Verificar se o número é de Carmichael.
int verificar_numero_carmichael(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int a = 2; a < n; a++) {
    if (VerificaCoPrimos(a, n)) {
      if (VerificaCongruencia(a, 1, n) != 1) {
        return 0;
      }
    }
  }

  return 1;
}
