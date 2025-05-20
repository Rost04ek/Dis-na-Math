#include "dijkstra.h"
#include <vector>
#include <queue>
#include <string>
#include <sstream>

void dijkstra(const std::vector<std::vector<int>>& adj, int start, std::vector<int>& dist, std::vector<int>& prev) {
    int n = adj.size();
    dist.assign(n, INF);
    prev.assign(n, -1);
    std::vector<bool> visited(n, false);

    dist[start] = 0;
    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (visited[v]) continue;
        visited[v] = true;

        for (int u = 0; u < n; ++u) {
            if (adj[v][u] < INF) {
                int alt = dist[v] + adj[v][u];
                if (alt < dist[u]) {
                    dist[u] = alt;
                    prev[u] = v;
                    pq.push({dist[u], u});
                }
            }
        }
    }
}

std::string getPath(int start, int end, const std::vector<int>& prev) {
    std::vector<int> path;
    for (int v = end; v != -1; v = prev[v])
        path.push_back(v);
    if (path.back() != start) return "No path";
    std::ostringstream oss;
    for (int i = path.size() - 1; i >= 0; --i) {
        oss << path[i];
        if (i != 0) oss << " -> ";
    }
    return oss.str();
}