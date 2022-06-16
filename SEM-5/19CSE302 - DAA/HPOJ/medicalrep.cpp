#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
const int INF = -1e7;
int dis[MAXN][MAXN];
int Next[MAXN][MAXN];
void initialise(int V, vector<vector<int>> &adjmat)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dis[i][j] = adjmat[i][j];
            if (adjmat[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}
vector<int> constructPath(int u, int v)
{
    if (Next[u][v] == -1)
        return {};
    vector<int> path = {u};
    while (u != v)
    {
        u = Next[u][v];
        path.push_back(u);
    }
    return path;
}
void floydWarshall(int V)
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dis[i][k] == INF || dis[k][j] == INF)
                    continue;

                if (dis[i][j] < dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

void printPath(vector<int> &path)
{
    int n = path.size();
    for (int i = 0; i < n - 1; i++)
        cout << path[i] + 1 << ",";
    cout << path[n - 1] + 1 << endl;
}

int main()
{

    int n, k;
    cin >> n >> k;
    int V = n;
    int inputarray[n];
    vector<vector<int>> adjmat;
    for (int i = 0; i < n; i++)
    {
        cin >> inputarray[i];
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> inner;
        for (int j = 0; j < n; j++)
        {
            if (inputarray[i] == inputarray[j] - 1)
            {
                inner.push_back(abs(j - i));
            }
            else
            {
                inner.push_back(INF);
            }
        }
        adjmat.push_back(inner);
    }
    initialise(V, adjmat);
    floydWarshall(V);
    vector<int> path;

    int max = INF;
    int from, to;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (inputarray[j] == k && dis[i][j] != INF && max < dis[i][j])
            {
                max = dis[i][j];
                from = i;
                to = j;
            }
        }
    }
    if (max == INF)
        cout << 0;
    else
        cout << max << endl;

    if (max != INF)
    {
        path = constructPath(from, to);
        printPath(path);
    }

    return 0;
}