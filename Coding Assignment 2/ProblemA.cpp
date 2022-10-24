#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
    
using namespace std;

int main(){

    int n, count = 0, temp;
    vector<int> a;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        a.push_back(temp);
        cout << "read: " << i << endl;
    }

    for(auto n : a){
        // sort
        sort(a.begin(), a.end());

        // increment count
        temp = a.at(0) + a.at(1);
        count += temp * 2;

        // erase used elements
        a.erase(a.begin(), a.begin() + 1);

        // push new element
        a.push_back(temp);

        cout << "stuck\n";
    }
    
    cout << count;

}