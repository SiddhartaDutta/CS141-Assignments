#include <iostream>
#include <algorithm>

using namespace std;
int candies = 0;

void merge(int array[], int const left, int const mid, int const right){
	auto const size1 = mid - left + 1;
	auto const size2 = right - mid;

	auto *arrayL = new int[size1], *arrayR = new int[size2];

	// Copy to left and right
	for (auto i = 0; i < size1; i++)
		arrayL[i] = array[left + i];
	for (auto j = 0; j < size2; j++)
		arrayR[j] = array[mid + 1 + j];

	auto initIndexSub1 = 0, initIndexSub2 = 0;
	int indexMerge = left;

	while (initIndexSub1 < size1 && initIndexSub2 < size2) {
		if (arrayL[initIndexSub1] <= arrayR[initIndexSub2]) {
			array[indexMerge] = arrayL[initIndexSub1];
			initIndexSub1++;
		} else {
			array[indexMerge] = arrayR[initIndexSub2];
			initIndexSub2++;
		}
		indexMerge++;
	}

	while (initIndexSub1 < size1) {
		array[indexMerge] = arrayL[initIndexSub1];
		initIndexSub1++;
		indexMerge++;
	}
	
	while (initIndexSub2 < size2) {
		array[indexMerge] = arrayR[initIndexSub2];
		initIndexSub2++;
		indexMerge++;
	}
	delete[] arrayL;
	delete[] arrayR;

    candies += array[right] - array[left];

}

void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end){
		return;
    }

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);

	merge(array, begin, mid, end);

}

int main()
{
    int size;//, candies = 0;
    cin >> size;

	int *arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

	mergeSort(arr, 0, size - 1);
    // cout << "Candies: " << candies << endl;

	cout << candies;
	return 0;
	// hi bryce
}