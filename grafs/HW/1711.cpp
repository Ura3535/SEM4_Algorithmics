#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1000000000

int residualCapacity[100][100];
int parent[100];
vector<int> adj[100];

bool bfs(int source, int sink, int n) {
    bool visited[1000];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v] && residualCapacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[sink];
}

int maxFlow(int source, int sink, int n) {
    int maxFlow = 0;
    while (bfs(source, sink, n)) {
        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualCapacity[u][v]);
        }
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualCapacity[u][v] -= pathFlow;
            residualCapacity[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(residualCapacity, 0, sizeof(residualCapacity));
    for (int i = 0; i < m; ++i) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        adj[u].push_back(v);
        adj[v].push_back(u);
        residualCapacity[u][v] = capacity;
    }

    int maxFlowResult = maxFlow(1, n, n);
    cout << maxFlowResult;

    return 0;
}