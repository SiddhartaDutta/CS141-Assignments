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
        //cout << "read: " << i << endl;
    }

    while(a.size() > 1){
        // sort
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size(); i++){
            cout << " " << a.at(i);
        }
        cout << endl;

        // increment count
        temp = a.at(0) + a.at(1);
        count += temp * 2;
        cout << "addition: " << temp*2 << endl;

        // erase used elements
        a.erase(a.begin());
        a.erase(a.begin());

        // push new element
        a.push_back(temp);

        cout << "size: " << a.size() << endl;
    }
    
    cout << count;

}