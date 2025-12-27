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

double distance(const Point& a, const Point& b) {
    return sqrt(distance_squared(a, b));
}

vector<Point> cities;
vector<int> ids;
int n;

pair<double, vector<int>> try_source(int source_node) {
    vector<int> vertex_path;
    vector<bool> used(n);

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

    double dist = 0;
    for (int i = 0; i < n - 1; i++)
        dist += distance(cities[vertex_path[i]], cities[vertex_path[i + 1]]);
    dist += distance(cities[vertex_path[0]], cities[vertex_path[n - 1]]);

    return {dist, vertex_path};
}

void solve() {
    read_input_(cities, ids);
    n = cities.size();

    int start_time = time(nullptr);
    int source_node = 0;

    double best_dist = 1e100;
    vector<int> best_path;

    // run until TL
    while (time(nullptr) - start_time < 60 && source_node < n) {
        auto [dist, path] = try_source(source_node);
        source_node++;

        if (dist < best_dist) {
            best_dist = dist;
            best_path = path;
        }
    }

    for (int u : best_path)
        cout << ids[u] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
