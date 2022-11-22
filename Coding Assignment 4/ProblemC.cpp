#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, temp;

    vector<int> a, LIS, LDS;

    cin >> n;

    // Fill input vector, LIS, and LDS to 1
    for(int i = 0; i < n; i++){
        cin >> temp;
        a.push_back(temp);
        LIS.push_back(1);
        LDS.push_back(1);
    }

    // Calculate LIS
    for(int pos = 0; pos < n; pos++){
        for(int jumper = 0; jumper < pos; jumper++){
            if(a[pos] > a[jumper] && LIS[pos] < LIS[jumper] + 1){
                LIS[pos] = LIS[jumper] + 1;
            }
        }
    }

    // Calculate LDS
    for(int pos = n - 2; pos >= 0; pos--){
        for(int jumper = n - 1; jumper > pos; jumper--){
            if(a[pos] > a[jumper] && LDS[pos] < LDS[jumper] + 1){
                LDS[pos] = LDS[jumper] + 1;
            }
        }
    }

    temp = LIS[0] + LDS[0] - 1;
    for(int i = 1; i < n; i++){
        if(LIS[i] + LDS[i] - 1 > temp){
            temp = LIS[i] + LDS[i] - 1;
        }
    }
    cout << temp;

}