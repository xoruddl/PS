#include <bits/stdc++.h>
using namespace std;

int chkover(int w, int h, int j, int i);

int main() {
    int field[4][4] = {{0, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 0}, {1, 1, 0, 1}};
    int mines[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int w = 2, h = 3;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (field[y][x] == 0) continue;
            for (int j = y - 1; j <= y + 1; j++) {
                for (int i = x - 1; i <= x + 1; i++) {
                    if (chkover(w, h, i, j) == 1) {
                        mines[j][i] += 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mines[i][j] << ' ';
        }
        cout << '\n';
    }
}

int chkover(int w, int h, int j, int i) {
    if (i >= 1 && i < w && j > 0 && j < h) return 1;
    return 0;
}
