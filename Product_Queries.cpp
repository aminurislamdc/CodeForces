#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    bool has_one = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) has_one = true;
    }

    sort(a.begin(), a.end());
    vector<int> unique_elements;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) continue;
        if (unique_elements.empty() || a[i] != unique_elements.back()) {
            unique_elements.push_back(a[i]);
        }
    }

    const int INF = 1e9;
    vector<int> dp(n + 1, INF);

    if (has_one) dp[1] = 1;

    for (int x : unique_elements) {
        if (x <= n) dp[x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] == INF) continue;

        for (int x : unique_elements) {
            long long next_val = 1LL * i * x;
            if (next_val > n) break;

            if (dp[next_val] > dp[i] + 1) {
                dp[next_val] = dp[i] + 1;
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        cout << (dp[i] == INF ? -1 : dp[i]) << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
