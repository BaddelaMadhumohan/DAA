#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution {
public:
    int coinExchange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i <= amount; i++) {

            for (int coin : coins) {

                if (coin <= i && dp[i - coin] != INT_MAX) {

                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if (dp[amount] == INT_MAX) {
            return -1;
        }

        return dp[amount];
    }
};

int main() {

    int n, amount;

    // Take number of coins
    cout << "Enter number of coins: ";
    cin >> n;

    // Create coin array
    vector<int> coins(n);

    // Take coin values
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Take amount
    cout << "Enter amount: ";
    cin >> amount;

    Solution obj;

    // Start timer
    auto startMin = high_resolution_clock::now();

    // Call coin exchange function
    int result = obj.coinExchange(coins, amount);

    // End timer
    auto endMin = high_resolution_clock::now();

    // Calculate execution time
    auto nanoMin = duration_cast<nanoseconds>(endMin - startMin);
    auto microMin = duration_cast<microseconds>(endMin - startMin);
    auto milliMin = duration_cast<milliseconds>(endMin - startMin);

    // Display result
    if (result == -1) {
        cout << "Amount cannot be formed." << endl;
    }
    else {
        cout << "Minimum number of coins: " << result << endl;
    }

    // Display execution time
    cout << "\nExecution Time:" << endl;
    cout << "Nanoseconds  : " << nanoMin.count() << " ns" << endl;
    cout << "Microseconds : " << microMin.count() << " us" << endl;
    cout << "Milliseconds : " << milliMin.count() << " ms" << endl;

    return 0;
}