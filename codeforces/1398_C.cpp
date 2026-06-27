#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, n;
vector<int> A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        string s;
        cin >> s;
        A.clear();

        map<int, int> m;
        m[0] = 1;
        ll ans = 0;
        ll psum = 0;
        for (auto c : s) {
            psum += (c - '0') - 1;
            ans += m[psum];
            m[psum]++;
        }
        
        cout << ans << '\n';
    }
    return 0;
}