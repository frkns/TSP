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

// we will use a union-find for cycle detection

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

    vector<int> degree(n);
    UnionFind uf(n);

    using Edge = pair<int, int>;

    vector<pair<double, Edge>> edge_weights;
    edge_weights.reserve(n * (n - 1) / 2);

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            // edge_weights.emplace_back()
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
