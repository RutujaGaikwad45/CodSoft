

#include<iostream>
using namespace std;

#define max 10

class graph
{
    public:
    int g[max][max];
    int visited[max], n;
    
    void readg();
    void dfs(int);
};

void graph::readg()
{
    cout << "How many nodes: ";
    cin >> n;
    
    
    cout << "Enter adjacency matrix (0 or 1 for each pair of nodes):\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    
    
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    int v;
    cout << "Enter starting vertex (1 to " << n  << "): ";
    cin >> v;
    
   
    dfs(v);
}

void graph::dfs(int i)
{
    
    cout << i << " ";
    
    
    visited[i] = 1;
    
    
    for (int j = 1; j <= n; j++)
    {
        if (visited[j] != 1 && g[i][j] == 1)
        {
            dfs(j);
        }
    }
}

int main()
{
    graph g;
    g.readg();
    return 0;
}
