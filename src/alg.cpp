// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int  k = 0;
for (int i = 0; i < len-1; i++) 
  for (int j = i+1; j < len; j++) 
    if (arr[i] + arr[j] == value) 
        k++;
return k;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
  int newlen = len - 1, k=0;
for (int i = 0; arr[i]<value; i++)
{
  for (int j = len - 1; i < j; j--)
    if (arr[i] + arr[j] == value)
      k++;
}
return k;
}
int poisk(int* arr, int s, int dodatok2) {
  int a = 0, b = s - 1, sr, k = 0;
  while (a <= b) {
    sr = (a + b) / 2;
    if (arr[sr] == dodatok2) {
      k++;
      int i = sr;
      while (arr[i] == dodatok2) {
        i--;
        k++;
      }
      i = sr;
      while (arr[i] == dodatok2) {
        i++;
        k++;
      }
      k -= 2;
      return k;
    }
    else if (arr[sr] > dodatok2)
      b = sr - 1;
    else
      a = sr + 1;
  }
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
  int dodatok2, k=0;
for (int i = 0; i < len; i++) {
  dodatok2 = value - arr[i];
  k += poisk(&arr[i + 1], len - 1, dodatok2);
}
return k;
}
