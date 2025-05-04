#include <iostream>
using namespace std;

int main() {
    cout << "===== DFS Traversal (Non-Recursive) =====\n\n";

    int n, e, start;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize adjacency matrix (0 means no edge)
    int cost[10][10] = {0};

    cout << "Enter edges (start end):\n";
    for (int k = 0; k < e; k++) {
        int i, j;
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1; // For undirected graph (remove if directed)
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    // Stack implementation using an array
    int stk[10], top = -1;
    bool visited[10] = {false};

    cout << "\nDFS Traversal: ";
    
    // Push starting node
    stk[++top] = start;
    visited[start] = true;

    while (top != -1) {
        int v = stk[top--]; // Pop
        cout << v << " ";

        // Push all adjacent unvisited nodes (reverse order for left-to-right DFS)
        for (int j = n; j >= 1; j--) {
            if (cost[v][j] == 1 && !visited[j]) {
                //visited[j] = true;
                stk[++top] = j; // Push
                visited[j] = true;
            }
        }
    }

    cout << "\n\n";
    return 0;
}