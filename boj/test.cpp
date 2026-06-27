#include <bits/stdc++.h>

using namespace std;

long long N, M, P[100001];
long long A[100001];
long long find(long long v) { return v == P[v] ? v : P[v] = find(P[v]); }
bool merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return true;

    if(A[u] >= A[v]) P[u] = v;
    else P[v] = u;

    return true;
}

int main() {
    cin >> N >> M;
    vector<tuple<long long, long long, long long>> E;
    for(long long i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        E.emplace_back(w, u, v);
        E.emplace_back(w, v, u);
    }
    for(long long i = 1; i <= N; i++) cin >> A[i];

    sort(E.begin(), E.end());
    for(long long i = 1; i <= N; i++) P[i] = i;

    long long res = 0;
    bool airport[100001] = {0};

    for(auto [w, u, v]: E) {
        long long u_new = find(u); long long v_new = find(v);
        if(u_new == v_new) continue;

        long long airport_v = 0;
        if(! airport[u_new]) airport_v += A[u_new];
        if(! airport[v_new]) airport_v += A[v_new];

        if(airport_v > w) {
            res += w;
            merge(u_new, v_new);
        } else {
            if(! airport[u_new]) {
                res += A[u_new];
                airport[u_new] = true;
            }
            if(! airport[v_new]) {
                res += A[v_new];
                airport[v_new] = true;
            }
        }
    }

    set<long long> unique;
    for(long long i = 1; i <= N; i++) {
        // cout << find(i) << '\t';
        unique.insert(find(i));
    }

    // cout << res;
    // cout << '\n';

    if(unique.size() >= 2) {
        for(auto v: unique) {
            // cout << v << ' ' << airport[v] << '\t';
            if(! airport[v]) {
                res += A[v];
                airport[v] = true;
            }
        }
    }

    // cout << '\n';
    cout << res << '\n';
}
