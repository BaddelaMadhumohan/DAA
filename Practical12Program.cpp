
#include <iostream>
#include <algorithm>
using namespace std;

int tsp(int cost[10][10], int n) {
    int cities[10];
    
    // Store cities except starting city 0
    for (int i = 0; i < n - 1; i++) {
        cities[i] = i + 1;
    }

    int minCost = 1000000;
    int bestRoute[10];

    // Generate all possible routes
    do {
        int totalCost = 0;
        int currentCity = 0;

        // Calculate cost of the current route
        for (int i = 0; i < n - 1; i++) {
            totalCost += cost[currentCity][cities[i]];
            currentCity = cities[i];
        }

        // Return to the starting city
        totalCost += cost[currentCity][0];

        // Update minimum cost
        if (totalCost < minCost) {
            minCost = totalCost;

            for (int i = 0; i < n - 1; i++) {
                bestRoute[i] = cities[i];
            }
        }

    } while (next_permutation(cities, cities + n - 1));

    cout << "Minimum cost: " << minCost << endl;
    cout << "Best route: 0 ";

    for (int i = 0; i < n - 1; i++) {
        cout << "-> " << bestRoute[i] << " ";
    }

    cout << "-> 0" << endl;

    return minCost;
}

int main() {
    int n;
    int cost[10][10];

    cout << "Enter number of cities (maximum 10): ";
    cin >> n;

    if (n < 2 || n > 10) {
        cout << "Enter a number of cities between 2 and 10.";
        return 0;
    }

    cout << "Enter the cost matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    tsp(cost, n);

    return 0;
}
