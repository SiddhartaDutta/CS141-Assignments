#include <bits/stdc++.h>
    
using namespace std;

// Merge arrays
void merge(int *arr[], int start, int half, int end) {
  
  // Create left and right arrays
  int size1 = half - start + 1;
  int size2 = end - half;

  int *L[size1], *R[size2];

  for (int i = 0; i < size1; i++){
    L[i] = arr[start + i];
  }
  for (int i = 0; i < size2; i++){
    R[i] = arr[half + 1 + i];
  }

  // Record current index of arrays
  int i, j, k;
  i = 0;
  j = 0;
  k = start;

  while (i < size1 && j < size2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < size1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < size2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int *arr[], int l, int r, int& candies) {
  if (l < r) {
    
    // divide array
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, candies);
    mergeSort(arr, m + 1, r, candies);

    // merge
    merge(arr, l, m, r);

    // get candies
    int temp = (sizeof(arr) / sizeof(int)) - 1;
    candies += arr[temp] - arr[0];

  }
}

// Driver program
// int main() {
//   int arr[] = {6, 5, 12, 10, 9, 1};
//   int size = sizeof(arr) / sizeof(arr[0]);

//   mergeSort(arr, 0, size - 1);

//   cout << "Sorted array: \n";
//   printArray(arr, size);
//   return 0;
// }

int main(){
    int scores, temp = 0;

    cin >> scores;

    int *arr[scores];

    for(int i = 0; i < scores; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, scores - 1, temp);

    cout << temp;
}