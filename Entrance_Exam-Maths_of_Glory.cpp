#include <string>
#include <iostream>

using namespace std;

int main(){

    int p1p2_Score = 0, p3p4_Score = 0, health = 0, rounds = 0, temp1 = 0, temp2 = 0, p1p2_RoundWin = 0, p3p4_RoundWin = 0;

    // Set health
    cin >> health;

    // Set rounds
    cin >> rounds;

    // Get inputs
    for(int i = 0; i < rounds; i++){
        cin >> temp1;
        cin >> temp2;

        p1p2_Score += (temp1 * temp2);

        cin >> temp1;
        cin >> temp2;

        p3p4_Score += (temp1 * temp2);

        // Check for win
        if(!p1p2_RoundWin && p1p2_Score > health){
            p1p2_RoundWin = i+1;
        }

        if(!p3p4_RoundWin && p3p4_Score > health){
            p3p4_RoundWin = i+1;
        }

    }

    if(!p1p2_RoundWin && p1p2_RoundWin > p3p4_RoundWin){
        cout << "Team 1 wins at round " << p1p2_RoundWin << "!";
    } else if(!p3p4_RoundWin && p3p4_RoundWin > p1p2_RoundWin){
        cout << "Team 2 wins at round " << p3p4_RoundWin << "!";
    } else if(!p1p2_RoundWin && p1p2_RoundWin == p3p4_RoundWin){
        cout << "It's a tie at round " << p1p2_RoundWin << "!";
    } else {
        cout << "Oh no!"
    }
    
}