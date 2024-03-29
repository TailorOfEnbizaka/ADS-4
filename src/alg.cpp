// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int size, int value) {
    int k = 0;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if ((arr[i] + arr[j]) == value) {
          k++;
        }
      }
    }
    return k;
  }
int countPairs2(int* arr, int len, int value) {
      int k = 0, b = len - 1;
      while (arr[b] > value) {
        b -= 1;
      }
      for (int i = 0; i < b; i++) {
        for (int j = b; j > i; j--) {
          int val = arr[i] + arr[j];
          if (val == value) {
            k++;
          }
        }
      }
      return k;
    }
  int binpoisk(int* arr, int size, int value) {
        int b = size - 1;
        int k = 0;
        int a = 0;
        while (a <= b) {
          int sr = a + (b - a) / 2;
          if (arr[sr] == value) {
            k++;
            a = sr - 1;
            b = sr + 1;
            while (a >= 0 && arr[a] == value) {
              k++;
              a--;
            }
            while (b < size && arr[b] == value) {
              k++;
              b++;
            }
            return k;
          }
          if (arr[sr] < value) {
            a = sr + 1;
          } else {
            b = sr - 1;
          }
        }
        return k;
      }
      int countPairs3(int* arr, int len, int value) {
        int k = 0;
        for (int i = 0; i < len; i++) {
          int dodatok = value - arr[i];
          k += binpoisk(&arr[i + 1], len - i - 1, dodatok);
        }
        return k;
      }
