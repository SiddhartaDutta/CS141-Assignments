#include <bits/stdc++.h>

using namespace std;

int main(){

    string input, temp;

    int takenSquares;
    vector<string> takenSquareCoords;
    queue<string> possibleCoords;

    int moveCount = 0;
    int oldMoveCount;
    string finalPos;
    bool pathFound = false;

    // Get how many taken squares exist
    cin >> takenSquares;

    // Record all taken coords
    for(int i = 0; i < takenSquares; i++){
        cin >> input;
        takenSquareCoords.push_back(input);
    }

    // Push starting point
    cin >> input;
    takenSquareCoords.push_back(input);
    possibleCoords.push(input);

    // Get final position
    cin >> finalPos;

    while(!possibleCoords.empty() && !pathFound){

        input = possibleCoords.front();
        temp = input;
        possibleCoords.pop();

        // Get "North" coords
            // Test height
        if((input[1] + 2) <= 8){
                // Test Right
            if((input[0] + 1) <= 'h'){
                temp[0] += 1;
                temp[1] += 2;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }

            // Reset temp
            temp = input;

                // Test Left
            if((input[0] - 1) >= 'a'){
                temp[0] -= 1;
                temp[1] += 2;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }
        }

        // Reset temp
        temp = input;

        // Get "South" coords
        if((input[1] - 2) >= 1){
                // Test Right
            if((input[0] + 1) <= 'h'){
                temp[0] += 1;
                temp[1] += 2;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }

            // Reset temp
            temp = input;

                // Test Left
            if((input[0] - 1) >= 'a'){
                temp[0] -= 1;
                temp[1] += 2;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }
        }

        // Reset temp
        temp = input;

        // Get "East" coords
        if((input[0] + 2) <= 'h'){
                // Test Up
            if((input[1] + 1) <= 8){
                temp[0] += 2;
                temp[1] += 1;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }

            // Reset temp
            temp = input;

                // Test Down
            if((input[1] - 1) >= 1){
                temp[0] += 2;
                temp[1] -= 1;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }
        }

        // Reset temp
        temp = input;

        // Get "West" coords
        if((input[0] - 2) >= 'a'){
                // Test Up
            if((input[1] + 1) <= 8){
                temp[0] += 2;
                temp[1] += 1;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }

            // Reset temp
            temp = input;

                // Test Down
            if((input[1] - 1) >= 1){
                temp[0] += 2;
                temp[1] -= 1;
                if(find(takenSquareCoords.begin(), takenSquareCoords.end(), temp) == takenSquareCoords.end()){
                    takenSquareCoords.push_back(temp);
                    possibleCoords.push(temp);
                    if(oldMoveCount == moveCount){ moveCount++; }
                }
            }
        }

        // Check if final coord was added
        if(find(takenSquareCoords.begin(), takenSquareCoords.end(), finalPos) != takenSquareCoords.end()){
            pathFound = true;
        }

        // Set old to current
        oldMoveCount = moveCount;
    }

    if(pathFound){
        cout << "Board 1: " << moveCount << " moves\n";
    } else {
        cout << "Board 1: not reachable\n";
    }

}