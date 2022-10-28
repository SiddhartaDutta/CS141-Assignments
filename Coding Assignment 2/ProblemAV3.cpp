#include <iostream>

using namespace std;

int candies = 0;

void merge(int arr[], int left[], int right[], int n){

    int i = 0, p1 = 0, p2 = 0;

    while((p1 < n/2) && (p2 < n/2)){
        if(left[p1] < right[p2]){
            arr[i] = left[p1];
            p1++;
        } else {
            arr[i] = right[p2];
            p2++;
        }
        i++;
    }

    while(p1 < n/2){
        arr[i] = left[p1];
        i++;
        p1++;
    }

    while(p2 < n/2){
        arr[i] = right[p2];
        i++;
        p2++;
    }

    candies += arr[n-1] - arr[0];

}

void mergeSort(int array[], int n,int left, int right ){

	if(n <= 1){
        return;
    }

    int *left = new int[n/2];
    int *right = new int[n/2];
    int mid = left + (right - left)/2;

    
    for(int i = 0; i <= n/2; i++){
        left[i] = array[i];
    }
    //for ( i = n/2+1 ;i<array.length();)
    for(int i = 0; i < n/2; i++){
        right[i] = array[n/2 + i + 1];
    }
    cout << endl << "Right Array: ";
    for(int i = 0; i < n/2; i++){
        cout << right[i] << " ";
    }
    exit(0);

	mergeSort(left, n/2);
	mergeSort(right, n/2);

	merge(array, left, right, n);
}

int main(){
    int size;
    cin >> size;

	int *arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

	mergeSort(arr, size);

    cout << candies << endl;

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
	return 0;
}