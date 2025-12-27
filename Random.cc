#include "bits/stdc++.h"
using namespace std;

void solve() {
    vector<int> ids;
    int id;
    double x, y;
    while (cin >> id >> x >> y)
        ids.emplace_back(id);

    mt19937 rand_gen(time(nullptr));

    shuffle(ids.begin(), ids.end(), rand_gen);

    for (int i : ids)
        cout << i << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
