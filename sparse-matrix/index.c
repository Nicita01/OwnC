# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

int putValue (int x, int y, int value, int strLen, int countStr, int* arr);

int main() {
  int strLen;
  printf("Введите кол-во элементов в строке массива: ");
  scanf("%i", &strLen);
  printf("/put для записи\n/get для чтения\n/exit для выхода\n");
  int* arr = (int *) malloc(strLen * sizeof(int) / 2);
  int countStr = 1;
  char str[40];
  while(true) {
    scanf("%s", str);
    if (strcmp(str, "/exit") == 0) {
      exit(EXIT_SUCCESS);
    }
    if (strcmp(str, "/put") == 0) {
      int x;
      int y;
      int value;
      printf("Номер строки:\n");
      scanf("%i", &x);
      printf("Номер столбца:\n");
      scanf("%i", &y);
      printf("Значение:\n");
      scanf("%i", &value);
      countStr = putValue(x, y, value, strLen, countStr, arr);
    }

    // DEBUG ::
    if (strcmp(str, "/dd") == 0) {
      int t = 0;
      while (t <= strLen * countStr ) {
        printf("%i ", arr[t++]);
      }
    }

  }
  return 0;
  
}

int arrIndex(int x, int y, int strLen) {
  int index = ((x - 1)*strLen + y) / 2;
  return index;
}

int putValue(int x, int y, int value, int strLen, int countStr, int* arr) {
  if ((x % 2 == 1 && y % 2 == 1) ||
  (x % 2 == 0 && y % 2 == 0)) {
    if (y > strLen) {
      printf("В строке может быть не более %i элементов\n", strLen);
      return countStr;
    }
    if (x > countStr) {
      arr = (int*)realloc(arr, 4);//x * strLen * sizeof(int) / 2);
      countStr = x;
    }


    int curArrIndex = arrIndex(x, y, strLen);
    arr[curArrIndex] = value;
    return countStr;
  } else {
    printf("На эту позицию записать элемент невозможно\n");
    return countStr;
  }
}

// int getValue(int x, int y) {
//   if ((x / 2 == 1 || y / 2 == 1) &&
//   (x / 2 == 0 || y / 2 == 0)) {
//     int index = arrIndex(x, y);
//     return arr[index];
//   } else {
//     return 0;
//   }
// }

// bool addEmptyStr() {
//   for (let countEl = 0; countEl < strLen; countEl++) {
//     arr
//   }
// }