#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k;
    cin >> k;

    if (n == 0 || k <= 0) return 0;
    if (k > n) k = n;

    vector<int> prefix(n), suffix(n);
    for (int i = 0; i < n; ++i) {
        if (i % k == 0) prefix[i] = a[i];
        else prefix[i] = max(prefix[i-1], a[i]);
    }
    for (int i = n-1; i >= 0; --i) {
        if (i == n-1 || i % k == k-1) suffix[i] = a[i];
        else suffix[i] = max(suffix[i+1], a[i]);
    }
    vector<int> ans;
    for (int i = 0; i + k - 1 < n; ++i) {
        int j = i + k - 1;
        ans.push_back(max(suffix[i], prefix[j]));
    }
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}