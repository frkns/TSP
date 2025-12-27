#include "bits/stdc++.h"
using namespace std;

struct Point {
    double x, y;

    Point(double x_, double y_) : x(x_), y(y_) {} // old C++
};

void read_input_(vector<Point>& cities, vector<int>& ids) {
    int id;
    double x, y;
    while (cin >> id >> x >> y) {
        cities.emplace_back(x, y);
        ids.emplace_back(id);
    }
}

double distance_squared(const Point& a, const Point& b) {
    double xdiff = a.x - b.x;
    double ydiff = a.y - b.y;
    return xdiff * xdiff + ydiff * ydiff;
}

// add the shortest available edge, such that there is
// - no vertex with degree > 2
// - no cycle

// we will use union-find for cycle detection

struct UnionFind {
    vector<int> par, size;

    UnionFind(int n) : par(n), size(n, 1) {
        iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; i++)
            assert(size[i] == 1);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    void unite(int u, int v) {
        int a = find(u); // roots
        int b = find(v);

        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);

        par[b] = a;
        size[a] += size[b];
    }
};

void solve() {
    vector<Point> cities;
    vector<int> ids;
    read_input_(cities, ids);
    int n = cities.size();

    using Edge = pair<int, int>;

    vector<pair<double, Edge>> edge_weights;
    edge_weights.reserve(n * (n - 1) / 2);

    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            Point p = cities[u];
            Point q = cities[v];
            edge_weights.emplace_back(distance_squared(p, q), Edge(u, v));
        }
    }
    ranges::sort(edge_weights);

    UnionFind uf(n);
    vector<int> degree(n);
    vector<Edge> edge_path;
    edge_path.reserve(n - 1);

    for (auto& [_, edge] : edge_weights) {
        auto [u, v] = edge;

        if (uf.find(u) == uf.find(v))
            continue;
        if (degree[u] == 2 || degree[v] == 2)
            continue;

        uf.unite(u, v);
        degree[u]++;
        degree[v]++;
        edge_path.emplace_back(u, v);
    }

    // find euler path on edge_path (euler tour formed by connecting endpoints)

    vector<vector<int>> adj(n);
    for (auto& [u, v] : edge_path) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    // find degree 1 vertex
    int start = 0;
    for (int u = 0; u < n; u++) {
        if (degree[u] == 1) {
            start = u;
            break;
        }
    }

    vector<bool> visited(n);
    vector<int> vertex_path;
    vertex_path.reserve(n);

    int node = start;
    while (true) {
        visited[node] = true;
        vertex_path.emplace_back(node);

        int next_node = -1;
        for (int v : adj[node]) {
            if (!visited[v]) {
                next_node = v;
                break;
            }
        }
        if (next_node == -1)
            break;
        node = next_node;
    }

    for (int u : vertex_path)
        cout << ids[u] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
