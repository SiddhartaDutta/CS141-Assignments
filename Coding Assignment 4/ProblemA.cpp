#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, temp;

    vector<int> nums;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        nums.push_back(temp);
    }

    int lds_arr[n], max_length = 0;

    for(int i = 0; i < n; i++){
        lds_arr[i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] < nums[j] && lds_arr[i] < lds_arr[j] + 1){
                lds_arr[i] = lds_arr[j] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(max_length < lds_arr[i]){
            max_length = lds_arr[i];
        }
    }

    cout << max_length;
}