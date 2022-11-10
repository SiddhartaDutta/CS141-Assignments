#include <iostream>
#include <vector>

using namespace std;

int min(int, int, int);

int main(){

    int n1, n2, temp;
    vector<int> a, b;

    cin >> n1;
    cin >> n2;

    for(int i = 0; i < n1; i++){
        cin >> temp;
        a.push_back(temp);
    }

    for(int i = 0; i < n2; i++){
        cin >> temp;
        b.push_back(temp);
    }

    int dp[n1 + 1][n2 + 1];

    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){

            if(i == 0 && j == 0){
                dp[i][j] = 0;
            } else if(i == 0){
                dp[i][j] = dp[i][j - 1] + b[j - 1];
            } else if(j == 0){
                dp[i][j] = dp[i - 1][j] + a[i - 1];
            } else {
                dp[i][j] = min(dp[i][j - 1] + b[j - 1], dp[i - 1][j] + a[i - 1], dp[i - 1][j - 1] + abs(b[j - 1] - a[i - 1]));
            }

        }
    }

    // cout << endl;
    // for(int i = 0; i <= n1; i++){
    //     for(int j = 0; j <= n2; j++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << dp[n1][n2];

}

int min(int num1, int num2, int num3){
    return min(min(num1, num2), num3);
}