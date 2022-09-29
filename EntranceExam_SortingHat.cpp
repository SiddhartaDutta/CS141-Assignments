#include <bits/stdc++.h>

using namespace std;

int main(){

    int numStudents = 0;
    vector<string> Gryffindor, Hufflepuff, Ravenclaw, Slytherin;

    cin >> numStudents;

    string tempName;
    string tempHouse;

    for(int i = 0; i < (numStudents); i++){
        cin >> tempName;
        cin >> tempHouse;

        if(tempHouse == "Gryffindor"){
            Gryffindor.push_back(tempName);
        } else if(tempHouse == "Hufflepuff"){
            Hufflepuff.push_back(tempName);
        } else if(tempHouse == "Ravenclaw"){
            Ravenclaw.push_back(tempName);
        } else {
            Slytherin.push_back(tempName);
        }
    }

    // Sort vectors
    sort(begin(Gryffindor), end(Gryffindor));
    sort(begin(Hufflepuff), end(Hufflepuff));
    sort(begin(Ravenclaw), end(Ravenclaw));
    sort(begin(Slytherin), end(Slytherin));

    // Print all
    cout << "Gryffindor\n";
    for(auto i:Gryffindor){
        cout << i << endl;
    }

    cout << "Hufflepuff\n";
    for(auto i:Hufflepuff){
        cout << i << endl;
    }

    cout << "Ravenclaw\n";
    for(auto i:Ravenclaw){
        cout << i << endl;
    }

    cout << "Slytherin\n";
    for(auto i:Slytherin){
        cout << i << endl;
    }

}