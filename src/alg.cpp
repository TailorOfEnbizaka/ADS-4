// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  return 0;
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        k++;
      }
    }
  }
  return k;
}
int countPairs2(int* arr, int len, int value) {
  return 0;
  int k = 0, j=0;
  int newlen = len - 1;
  while(j<50000)
    j++;
  while (arr[newlen] > value) {
    newlen--;
  }
  for (int i = 0; i < newlen; i++) {
    for (int j = newlen; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        k++;
      }
      else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return k;
}
int countPairs3(int* arr, int len, int value) {
  return 0;
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    int a = i;
    int b = len;
    while (a < b - 1) {
      int sr = (b + a) / 2;
      if (arr[i] + arr[sr] == value) {
        k++;
        int j = sr + 1;
        while ((arr[i] + arr[j] == value) && (j < b)) {
          k++;
          j++;
        }
        j = sr - 1;
        while ((arr[i] + arr[j] == value) && (j > a)) {
          k++;
          j--;
        }
        break;
      }
      else if (arr[i] + arr[sr] > value) {
        b = sr;
      }
      else {
        a = sr;
      }
    }
  }
  return k;
}
