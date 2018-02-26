#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* interpret(char* string) {
//printf("On start:\n");
for (int counter = 0; counter < 55; counter++) {
    printf("%c", string[counter]);
  }
// printf("\n");

  // 1) Delete left symbols
  int length = 0;
  int shift = 1;
  while (string[length]){
    switch (string[length]) {
      case '>':
      case '<':
      case '+':
      case '-':
      case '.':
      case ',':
      case '[':
      case ']':
        break;
      default:
        printf("");
        int rewriter = length;
        while(string[rewriter + 1]) {
          string[rewriter] = string[rewriter + 1];
          rewriter++;
        }
        string[strlen(string) - 1] = 0;
        length--;
        break;
    }
    length++;

  }
  printf("After left symbols deleting:\n");
  printf("%s\n", string);
  printf("len %i\n", length);


  // On this step we have string with good symbols only

  // 2) Error, if count("[") != count("]"):
  int left = 0;
  int right = 0;
  int cur = 0;
  while (string[cur]){
    switch (string[cur]) {
      case '[':
        ++left;
        break;
      case ']':
        ++right;
        break;
    }
    cur++;
  }  
  if (left == right) {
  } else {
    static char err[] = "Error!";
    return err;
  }

  // 3) Delete []; +- etc
   for (int counter = 1; counter < length; counter++) {
    if(string[counter - 1] == '[' && string[counter] == ']' ||
    string[counter - 1] == '-' && string[counter] == '+' ||
    string[counter - 1] == '+' && string[counter] == '-' ||
    string[counter - 1] == '>' && string[counter] == '<' ||
    string[counter - 1] == '<' && string[counter] == '>' ) {
      int rewriter = counter;
      while(string[rewriter + 1]) {
        string[rewriter - 1] = string[rewriter + 1];
        rewriter++;
      }
      string[strlen(string) - 1] = 0;
      string[strlen(string) - 1] = 0;
      length -= 2;
      counter -= 2;
    }
  }

  printf("Before lincing:\n%s\n", string);

  char* res = (char*) malloc(10000);
  char nextCommand[] = ";\n";

  int shifter = 0;
  for (int cur = 0; cur < length; cur++) {
   
    switch (string[cur]) {
      case '+':
        res[strlen(res)] = '*';
        res[strlen(res)] = 'p';
        res[strlen(res)] = ' ';
        res[strlen(res)] = '+';
        res[strlen(res)] = '=';
        res[strlen(res)] = ' ';
        res[strlen(res)] = 0;
        break;
      case '-':
        printf("");
        res[strlen(res)] = '*';
        res[strlen(res)] = 'p';
        res[strlen(res)] = ' ';
        res[strlen(res)] = '-';
        res[strlen(res)] = '=';
        res[strlen(res)] = ' ';
        res[strlen(res)] = 0;
        break;
      case '>':
        printf("");
        res[strlen(res)] = 'p';
        res[strlen(res)] = ' ';
        res[strlen(res)] = '+';
        res[strlen(res)] = '=';
        res[strlen(res)] = ' ';
         res[strlen(res)] = 0;
         break;
      case '<':
        printf("");
        res[strlen(res)] = 'p';
        res[strlen(res)] = ' ';
        res[strlen(res)] = '-';
        res[strlen(res)] = '=';
        res[strlen(res)] = ' ';
        res[strlen(res)] = 0;
        break;   
    }


    switch(string[cur]) {
      case '+':
      case '-':
      case '<':
      case '>':
        printf("");
        int counterSameSymbols = 1;
        int curGlob = cur;
        char elementInk = string[cur + 1];
        while (elementInk == string[curGlob]) {
          counterSameSymbols++;
          elementInk = string[curGlob + counterSameSymbols];
          cur++;
        }
        char* stringCur = (char*)malloc(20);
        sprintf(stringCur, "%i", counterSameSymbols);
        int curSymb = 0;
        while(stringCur[curSymb]){
        res[strlen(res)] = stringCur[curSymb];
          curSymb++;
      }
    }
    switch(string[cur]) {
      case ',':
        printf("");
        char forZ[] = "*p = getchar()";
        int flagTemp3 = 0;
        while (flagTemp3 < 14) {
          res[strlen(res)] = forZ[flagTemp3++];
          
        }
        // cur++;
        break;
      case '.':
        printf("");
        char forT[] = "putchar(*p)";
        int flagTemp2 = 0;
        while (flagTemp2 < 11) {
          res[strlen(res)] = forT[flagTemp2++];
        }
          // cur++;
       
        break;
      case '[':
        printf("");
        char forL[] = "if (*p) do {";
        int flagTemp4 = 0;
        while (flagTemp4 < 12) {
          res[strlen(res)] = forL[flagTemp4++];
        }
        // cur++;
        break;
        /////////
      case ']':
        printf("");
        char forR[] = "} while (*p)";
        int flagTemp5 = 0;
        while (flagTemp5 < 12) {
          res[strlen(res)] = forR[flagTemp5++];
        }

          // cur++;
        break;
    }
    
      int flagTemp = 0;
      switch(string[cur]){
        case '[':
          res[strlen(res)] = '\n';
          break;
        default:
          while (flagTemp < 3) {
            res[strlen(res)] = nextCommand[flagTemp++];
          }
      }

  }
//   printf("%s\n", res);
//   int lastCounter = 0;
//   static char ress[10000];
// while(lastCounter < strlen(string)){
//   ress[lastCounter] = res[lastCounter];
//   lastCounter++;
// }
//     return ress;
return res;
}


int main() {
  char str[50] = "<>><++...++---]-[----asdf3[]][[[]]>>>>>";
  char* st = interpret(str);
  //printf("%s", st);
  return 0;
}