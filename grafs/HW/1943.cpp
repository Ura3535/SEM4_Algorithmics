#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int a, b, i, n, m, vaxt;
vector<vector<int>> graph;
vector<int> used, d, up;
set<int> Bridges;
map<pair<int, int>, int> mp;

pair<int, int> Edge(int a, int b)
{
	if (a > b) swap(a, b);
	return make_pair(a, b);
}

void dfs(int v, int p = -1)
{
	int i, to;
	used[v] = 1;
	d[v] = up[v] = vaxt++;
	for (i = 0; i < graph[v].size(); i++)
	{
		to = graph[v][i];
		if (to == p)  continue;
		if (used[to]) up[v] = min(up[v], d[to]);
		else
		{
			dfs(to, v);
			up[v] = min(up[v], up[to]);
			if (up[to] > d[v]) Bridges.insert(mp[Edge(v, to)]);
		}
	}
}

void FindBridges()
{
	vaxt = 1;
	for (int i = 1; i <= n; i++) if (!used[i]) dfs(i);
}

int main() {
	scanf("%d %d", &n, &m);
	graph.resize(n + 1); used.resize(n + 1);
	d.resize(n + 1); up.resize(n + 1);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b); graph[b].push_back(a);
		mp[Edge(a, b)] = i;
	}
	FindBridges();

	printf("%d\n", Bridges.size());
	set<int>::iterator iter;
	for (i = 0, iter = Bridges.begin(); iter != Bridges.end(); ++iter)
	{
		if (i++) printf(" ");
		printf("%d", *iter);
	}
	if (Bridges.size()) printf("\n");
	return 0;
}