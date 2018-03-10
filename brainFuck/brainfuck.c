#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* interpret(char* source) {

  char string[strlen(source) + 2];
  for(int count = 0; count < strlen(source); count++) {
    string[count] = source[count];
  }

  printf("start\n%sEND\n\n", string);
  int length = 0; 
  while (string[length]){
    switch (string[length]) {
      case '>':
      case '<':
      case '+':
      case '-':
      case '.':
      case ',':
      case '[':
      case ']': {
        break;
      }
      default: {
        int rewriteCounter = length;
        while(string[rewriteCounter + 1]) {
          string[rewriteCounter] = string[rewriteCounter + 1];
          rewriteCounter++;
        }
        string[strlen(string) - 1] = 0;
        length--;
        break;
      }
    }
    length++;
  }

 printf("leftDelete\n%sEND\n\n", string);
 printf("LENGTH %i\n", length);

  int bracketCount = 0;
  int curSymbolIndex = 0;
  while (string[curSymbolIndex]){
    switch (string[curSymbolIndex]) {
      case '[': {
        bracketCount++;
        break;
      }
      case ']': {
        if (bracketCount-- == 0) {
          static char err[] = "Error!";
          return err;
        }
        break;
      }
    }
    curSymbolIndex++;
  }
  if (bracketCount != 0) {
    static char err[] = "Error!";
    return err;
  }
  
  curSymbolIndex = 1;
  while (string[curSymbolIndex]){
    if (
      string[curSymbolIndex - 1] == '[' && string[curSymbolIndex] == ']' ||
      string[curSymbolIndex - 1] == '-' && string[curSymbolIndex] == '+' ||
      string[curSymbolIndex - 1] == '+' && string[curSymbolIndex] == '-' ||
      string[curSymbolIndex - 1] == '>' && string[curSymbolIndex] == '<' ||
      string[curSymbolIndex - 1] == '<' && string[curSymbolIndex] == '>' 
    ) {
      int rewriteCounter = curSymbolIndex - 1;
      while(string[rewriteCounter + 2]) {
        string[rewriteCounter] = string[rewriteCounter + 2];
        rewriteCounter++;
      }
      string[strlen(string) - 2] = 0;
      length -= 2;
      curSymbolIndex -= 2;
    }
    curSymbolIndex += 1;
  }


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ GOOD ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 


   
  printf("optimize\n%sEND\n\n\n\n", string); 
  int count_of_symbols_conv = 120;
  int sizeRes = count_of_symbols_conv*length;
  char res[sizeRes];

  for (int clearingCounter = sizeRes; clearingCounter> 0; clearingCounter--) {
    res[clearingCounter - 1] = 0;
  }
 
  curSymbolIndex = 0;
  int shiftByBracket = 0;
  printf("%c", sizeRes);
  while (string[curSymbolIndex]){
  
    if (string[curSymbolIndex] == ']') {
      shiftByBracket--;
    }
    for (int shiftCounter = 0; shiftCounter <= shiftByBracket * 2; shiftCounter++ ) {
      res[strlen(res)] = ' ';
    }
    char sumStr[] = "*p += ";
    char derStr[] = "*p -= ";
    char pointRightStr[] = "p += ";
    char pointLeftStr[] = "p -= ";
    char putStr[] = "putchar(*p);";
    char getStr[] = "*p = getchar(*p);";
    char brackeLeftStr[] = "if (*p) do {";
    char brakeRightStr[] = "} while (*p);";
    int countWriteSymbol = 0;
    switch (string[curSymbolIndex]) {
      case '+': {
        for (; countWriteSymbol < 6; countWriteSymbol++) {
          res[strlen(res)] = sumStr[countWriteSymbol];
        }
        break;
      }
      case '-': {
        for (;countWriteSymbol < 6; countWriteSymbol++) {
          res[strlen(res)] = derStr[countWriteSymbol];
        }
        break;
      }
      case '>': {
        for (;countWriteSymbol < 5; countWriteSymbol++) {
          res[strlen(res)] = pointRightStr[countWriteSymbol];
        }
        break;
      }
      case '<': {
        for (;countWriteSymbol < 5; countWriteSymbol++) {
          res[strlen(res)] = pointLeftStr[countWriteSymbol];
        }
        break;
      }
      case '.': {
        for (;countWriteSymbol < 12; countWriteSymbol++) {
          res[strlen(res)] = putStr[countWriteSymbol];
        }
        break;
      }
      case ',': {
        for (;countWriteSymbol < 17; countWriteSymbol++) {
          res[strlen(res)] = getStr[countWriteSymbol];
        }
        break;
      }
      case ']': {
        for (;countWriteSymbol < 13; countWriteSymbol++) {
          res[strlen(res)] = brakeRightStr[countWriteSymbol];
        }
        break;
      }
      case '[': {
        for (;countWriteSymbol < 12; countWriteSymbol++) {
          res[strlen(res)] = brackeLeftStr[countWriteSymbol];
        }
        shiftByBracket++;
        break;
      }
    }

    switch (string[curSymbolIndex]) {
      case '+':
      case '-':
      case '>':
      case '<': {
        char curSymbol = string[curSymbolIndex];
        int symbolSameIndex = 1;
        while (string[curSymbolIndex + symbolSameIndex] == curSymbol) {
          symbolSameIndex++;
        }
        curSymbolIndex += symbolSameIndex - 1;
        char* stringOfCountSameSymbols = (char*) malloc(10);
        sprintf(stringOfCountSameSymbols, "%d", symbolSameIndex);
        int countSymbol = 0;
        while(stringOfCountSameSymbols[countSymbol]){
          res[strlen(res)] = stringOfCountSameSymbols[countSymbol];
          countSymbol++;
        }
        free(stringOfCountSameSymbols);
      }
    }
        res[strlen(res)] = '\n';
    

  curSymbolIndex++;
  }
printf("%i\n", strlen(res));
  printf("RES_START\n%sRES_END", res);
  
  static char str[10000];
  for ( int i = 0; i < 1000; i++) {
    str[i] = res[i];
  }
return str;


}


int main() {
  char str[50] = "[[[[+]-]--]][-]";
  char* st = interpret(str);
  printf("%s", st);
  return 0;
}