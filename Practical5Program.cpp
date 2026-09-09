#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// Knapsack function
int knapsack(vector<int>& weight, vector<int>& value, int n, int W) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= W; w++) {

            if (weight[i - 1] <= w) {

                dp[i][w] = max(
                    dp[i - 1][w],
                    value[i - 1] + dp[i - 1][w - weight[i - 1]]
                );

            } else {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;


    // Start timer
    auto start = chrono::high_resolution_clock::now();

    // Execute Knapsack
    int result = knapsack(weight, value, n, W);

    // End timer
    auto end = chrono::high_resolution_clock::now();


    // Calculate execution time
    auto time = chrono::duration_cast<chrono::nanoseconds>(end - start);


    // Display result
    cout << "\nMaximum Knapsack Value = " << result << endl;
    cout << "Execution Time = " << time.count() << " ns" << endl;


    return 0;
}