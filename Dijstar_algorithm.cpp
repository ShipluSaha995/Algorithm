#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cout << "Enter the target amount N: ";
    cin >> N;

    int numCoins;
    cout << "Enter number of coin types: ";
    cin >> numCoins;

    vector<int> coins(numCoins);
    cout << "Enter the coin values: ";
    for (int i = 0; i < numCoins; i++)
        cin >> coins[i];

    vector<int> dp(N + 1, 0);
    dp[0] = 1; 

    for (int coin : coins) {
        for (int i = coin; i <= N; i++) {
            dp[i] += dp[i - coin];
        }
    }

    cout << "Total number of combinations: " << dp[N] << endl;

    return 0;
}