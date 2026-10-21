
#include <iostream>
#include <climits>
using namespace std;

void prims(int graph[10][10], int n) {
    int visited[10] = {0};
    visited[0] = 1;

    int edges = 0;
    int totalWeight = 0;

    while (edges < n - 1) {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (visited[j] == 0 &&
                        graph[i][j] != 0 &&
                        graph[i][j] < minWeight) {

                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "Graph is disconnected!\n";
            return;
        }

        cout << u << " - " << v
             << " : " << minWeight << endl;

        visited[v] = 1;
        totalWeight += minWeight;
        edges++;
    }

    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    int n;
    int graph[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";
    prims(graph, n);

    return 0;
}
