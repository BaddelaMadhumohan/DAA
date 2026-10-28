
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>& parent,
              vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u == v) {
        return;
    }

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int V = 4;

    vector<Edge> edges = {
        {0, 1, 1},
        {1, 2, 2},
        {0, 2, 3},
        {2, 3, 4},
        {1, 3, 5}
    };

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalWeight = 0;
    int edgeCount = 0;

    cout << "Edges in MST:\n";

    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        int parentU = findParent(u, parent);
        int parentV = findParent(v, parent);

        if (parentU != parentV) {
            cout << u << " - " << v
                 << " : " << w << endl;

            totalWeight += w;
            edgeCount++;

            unionSet(u, v, parent, rank);

            if (edgeCount == V - 1) {
                break;
            }
        }
    }

    cout << "Total MST weight: " << totalWeight << endl;

    return 0;
}
