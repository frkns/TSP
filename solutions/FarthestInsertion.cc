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

void solve() {
    vector<Point> cities;
    vector<int> ids;
    read_input_(cities, ids);
    int n = cities.size();

    // precompute distances
    vector<vector<double>> d(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            d[i][j] = d[j][i] = distance(cities[i], cities[j]);

    // farthest pair to start
    assert(n >= 2);
    int a = 0, b = 1;
    {
        double best_dist = -1; // farthest
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (d[i][j] > best_dist)
                    best_dist = d[i][j], a = i, b = j;
    }

    // init stuff
    vector<int> tour = {a, b};
    vector<bool> in_tour(n);
    in_tour[a] = in_tour[b] = true;

    vector<double> dist_to_tour(n, 1e100);
    for (int u = 0; u < n; u++)
        if (!in_tour[u])
            dist_to_tour[u] = min(d[u][a], d[u][b]);

    // main loop

    for (int iter = 0; iter < n - 2; iter++) {
        // find node: argmax distance
        int u_star = -1;
        double best_dist = -1; // farthest
        for (int u = 0; u < n; u++)
            if (!in_tour[u] && dist_to_tour[u] > best_dist)
                best_dist = dist_to_tour[u], u_star = u;

        // insert it at cheapest pos
        int best_pos = -1;
        double best_cost = 1e100;
        int m = tour.size();
        for (int i = 0; i < m; i++) {
            int v = tour[i];
            int w = tour[(i + 1) % m];

            // cost to replace v-w with v-(u*)-w
            double cost = d[v][u_star] + d[u_star][w] - d[v][w];

            if (cost < best_cost)
                best_cost = cost, best_pos = i + 1;
        }
        tour.insert(tour.begin() + best_pos, u_star); // vec vs set should not matter
        in_tour[u_star] = true;

        // update dist_to_tour based off new insertion
        for (int u = 0; u < n; u++)
            if (!in_tour[u])
                dist_to_tour[u] = min(dist_to_tour[u], d[u][u_star]);
    }

    for (auto u : tour)
        cout << ids[u] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
