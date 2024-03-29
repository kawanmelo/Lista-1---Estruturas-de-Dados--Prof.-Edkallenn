#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool permutacao_circular(int *originalArray, int arrayLenght, int *comparisonArray);
void rotate(int array[], int lenght);

/*
  Função : Verificar permutação circular entre dois arrays de inteiros
  Autor : Kawan Melo - 3º período turma F 2024.1
  Data : 29.03.2023
  Observações: Null
*/

int main() {
  int *originArray = NULL;
  int *comparisonArray = NULL;
  int arrayLenght = 0;
  printf("Digite o tamanho dos array: ");
  scanf("%d", &arrayLenght);
  originArray = (int *)malloc(arrayLenght * sizeof(int));
  comparisonArray = (int *)malloc(arrayLenght * sizeof(int));
  if (originArray == NULL) {
    printf("Erro ao alocar memoria");
  }
  for (int i = 0; i < arrayLenght; i++) {
    printf("Digite o valor do array 1 na posição %d: ", i);
    scanf("%d", &originArray[i]);
  }
  for (int i = 0; i < arrayLenght; i++) {
    printf("Digite o valor do array 2 na posição %d: ", i);
    scanf("%d", &comparisonArray[i]);
  }
  bool result = permutacao_circular(originArray, arrayLenght, comparisonArray);
  if (result) {
    printf("É permutação circular");
  } else {
    printf("Não é permutação circular");
  }
  return 0;
}


// Função : Verificar permutação circular entre dois arrays de inteiros de mesmo tamanho através de ciclos de rotações e comparações entre os arrays.
bool permutacao_circular(int *originalArray, int arrayLenght, int *comparisonArray){
  // inicializa array "copiedArray" e copia o conteúdo do array "originalArray" para ele.
  int *copiedArray = malloc(arrayLenght * sizeof(int));
  for (int i = 0; i < arrayLenght; i++) {
    copiedArray[i] = originalArray[i];
  }
  while (true) {
    int count;
    int count2;
    // rotaciona o array "originalArray e verifica se todos os valores são iguais aos valores do array "comparisonArray", retorna true em caso positivo(confirma que os arrays são uma permutação circular).
    rotate(originalArray, arrayLenght);
    for (int i = 0; i < arrayLenght; i++) {
      if (originalArray[i] == comparisonArray[i]) {
        count++;
      }
      if (count == arrayLenght) {
        return true;
      }
    }
    // verifica se o array "copiedArray" é igual ao array "originalArray" e retorna false caso positivo(confirma que os arrays não são uma permutação circular).
    for (int i = 0; i < arrayLenght; i++) {
      if (originalArray[i] == copiedArray[i]) {
        count2++;
      }
      if (count2 == arrayLenght) {
        printf("");
        return false;
      }
    }
  }
  printf("");
  return false;
}

// Função : Rotaciona array em um ciclo para a direita.
void rotate(int array[], int lenght) {

  int lastElement = array[lenght - 1];
  int i = 0;
  for (i = lenght - 1; i > 0; i--) {
    array[i] = array[i - 1];
  }
  array[0] = lastElement;
}
