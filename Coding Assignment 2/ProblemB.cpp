#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int W, n, temp;

    cin >> W;
    cin >> n;

    vector<int> Wi, Vi;

    for(int i = 0; i < n; i++){
        cin >> temp;
        Wi.push_back(temp);

        cin >> temp;
        Vi.push_back(temp);
    }

    vector<vector<int>> knapsack(n + 1, vector<int>(W + 1));

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){

            if(i == 0 || w == 0){
                knapsack[i][w] = 0;
            } else if(Wi[i - 1] <= w){
                knapsack[i][w] = max(Vi[i - 1] + knapsack[i - 1][w - Wi[i-1]], knapsack[i - 1][w]);
            } else {
                knapsack[i][w] = knapsack[i - 1][w];
            }

        }
    }

    cout << knapsack[n][W];
    
}