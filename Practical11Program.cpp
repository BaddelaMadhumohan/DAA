
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& dist, int n) {

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF &&
                    dist[k][j] != INF) {

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    }
}

// Function to print the distance matrix
void printMatrix(vector<vector<int>>& dist, int n) {

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter adjacency matrix (-1 for no edge):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];

            if (dist[i][j] == -1) {
                dist[i][j] = INF;
            }
        }
    }

    floydWarshall(dist, n);

    printMatrix(dist, n);

    return 0;
}
