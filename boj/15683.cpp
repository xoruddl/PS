#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int ans = 987654321;
int MAP[9][9];
vector<pair<int, int>> cctv;

void check(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
            return;
        }
        if (MAP[ny][nx] == 6) return;
        if (MAP[ny][nx] != 0) continue;
        MAP[ny][nx] = -1;
    }
}

void dfs(int idx) {
    if (idx == cctv.size()) {
        int val = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!MAP[i][j]) {
                    val++;
                }
            }
        }
        ans = min(ans, val);
        return;
    }

    int x = cctv[idx].second;
    int y = cctv[idx].first;
    int tmp[9][9];

    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[i][j] = MAP[i][j];
            }
        }

        if (MAP[y][x] == 1) {
            check(x, y, dir);
        }
        else if (MAP[y][x] == 2) {
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (MAP[y][x] == 3) {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (MAP[y][x] == 4) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        else if (MAP[y][x] == 5) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx + 1);

        // cctv 하나가 방향 바꿀 때 이전 기록 지우기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                MAP[i][j] = tmp[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] != 0 && MAP[i][j] != 6) {
                cctv.push_back({i, j});
            }
        }
    }

    dfs(0);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cout << MAP[i][j];
//        }
//        cout << '\n';
//    }
    cout << ans;
    return 0;
}
