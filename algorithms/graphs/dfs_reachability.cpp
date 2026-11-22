// Reachability queries with recursive depth-first search.
//
// Input:
//   directed n m        directed = 1 for a directed graph, 0 for undirected;
//                       n vertices (0 .. n-1), m edges
//   m lines: u v        an edge u -> v (or u — v)
//   q                   number of queries
//   q lines: s t        is t reachable from s?
// Output: one line per query, "yes" or "no".
//
// Time: O(n + m) per query, memory: O(n + m).

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int current, int target, const vector<vector<int>>& graph, vector<bool>& visited)
{
    if (current == target) return true;
    visited[current] = true;
    for (int next : graph[current])
    {
        // Try every unvisited neighbour, not just the first one.
        if (!visited[next] && dfs(next, target, graph, visited)) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int directed, n, m;
    cin >> directed >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        if (directed == 0) graph[v].push_back(u);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        vector<bool> visited(n, false);
        cout << (dfs(s, t, graph, visited) ? "yes" : "no") << '\n';
    }
    return 0;
}
