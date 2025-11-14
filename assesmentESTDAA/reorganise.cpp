#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    int n = s.size();
    int cnt[256] = {0};
    for (unsigned char c : s) cnt[c]++;
    int maxc = 0;
    for (int i = 1; i < 256; ++i)
        if (cnt[i] > cnt[maxc]) maxc = i;
    int maxf = cnt[maxc];

    if (maxf > (n + 1) / 2) {
        cout << -1;
        return 0;
    }
    string res(n, ' ');
    int idx = 0;
    while (cnt[maxc]--) {
        res[idx] = (char)maxc;
        idx += 2;
    }
    for (int c = 0; c < 256; ++c) {
        while (cnt[c]--) {
            if (idx >= n) idx = 1;
            res[idx] = (char)c;
            idx += 2;
        }
    }
    cout << res;
    return 0;
}