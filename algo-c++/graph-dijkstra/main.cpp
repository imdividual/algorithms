#include <bits/stdc++.h>
using namespace std;

// https://brilliant.org/wiki/dijkstras-short-path-finder/

void graph_dijkstra(vector<vector<pair<int, int>>> &G, vector<int> &dist, int src) {
    int nodes = G.size();
    for(int i = 0; i < nodes; ++i)
        dist.emplace_back(INT_MAX);

    vector<bool> visited;
    for(int i = 0; i < nodes; ++i)
        visited.emplace_back(false);

    dist[src] = 0;
    queue<int> queue;
    queue.push(src);

    while(!queue.empty()) {
        int cur = queue.front();
        queue.pop();

        for(int i = 0; i < G[cur].size(); ++i) {
            int next = G[cur][i].first;
            int d = G[cur][i].second;
            if(visited[next]) {
                dist[next] = min(dist[next], dist[cur] + d);
                queue.push(next);
            }
        }

        visited[cur] = true;
    }
}

int main() {
    string ln;
    getline(cin, ln);
    int N = stoi(ln);
    getline(cin, ln);
    int M = stoi(ln);

    vector<vector<pair<int, int>>> G;
    for(int i = 0; i < N; ++i) {
        vector<pair<int, int>> node;
        G.emplace_back(node);
    }

    for(int i = 0; i < M; ++i) {
        getline(cin, ln);
        istringstream ss{ln};
        int a, b, d;
        ss >> a >> b >> d;
        G[a].emplace_back(make_pair(b, d));
    }

    vector<int> dist;
    graph_dijkstra(G, dist, 0);

    for(auto i : dist) cout << i << endl;

    return 0;
}
