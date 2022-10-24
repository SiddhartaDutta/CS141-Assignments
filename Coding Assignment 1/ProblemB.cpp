#include <bits/stdc++.h>

using namespace std;

int main(){
    int depts = 0, temp;
    vector<int> deptMembers;

    // Get dept count
    cin >> depts;

    // Get faculty count per dept
    for(int i = 0; i < depts; i++){
        cin >> temp;
        deptMembers.push_back(temp);
    }

    // Order depts by lowest->greatest
    sort(begin(deptMembers), end(deptMembers));

    // Ceiling half only the first ceiling half of depts
    depts = int(depts/2) + 1;
    temp = 0;
    for(int i = 0; i < depts; i++){
        temp += int(deptMembers[i]/2) + 1;
    } 

    // Return total min required votes
    cout << temp << endl;
}