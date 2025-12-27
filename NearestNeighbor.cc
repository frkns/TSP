#include "bits/stdc++.h"
using namespace std;

struct point {
    double x, y;

    point(double x_, double y_) : x(x_), y(y_) {} // old C++
};

void read_input_(vector<point>& cities, vector<int>& ids) {
    int id;
    double x, y;
    while (cin >> id >> x >> y) {
        cities.emplace_back(x, y);
        ids.emplace_back(id);
    }
}

double distance_squared(const point& a, const point& b) {
    double xdiff = a.x - b.x;
    double ydiff = a.y - b.y;
    return xdiff * xdiff + ydiff * ydiff;
}

void solve() {
    vector<point> cities;
    vector<int> ids;
    read_input_(cities, ids);
    int n = cities.size();

    vector<int> vertex_path;
    vector<bool> used(n);

    const int source_node = 0;
    int node = source_node;
    used[node] = true;
    vertex_path.emplace_back(node);

    while (vertex_path.size() != n) {
        int best_node = -1;
        double best_dist = 1e100;

        for (int u = 0; u < n; u++) {
            if (used[u])
                continue;
            if (u == source_node)
                continue;

            double d = distance_squared(cities[node], cities[u]);
            if (d < best_dist) {
                best_dist = d;
                best_node = u;
            }
        }

        node = best_node;
        used[node] = true;
        vertex_path.emplace_back(node);
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
