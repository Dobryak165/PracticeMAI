// Задача E - Диггер

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> gold(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> gold[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = gold[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;

            int max_gold = 0;
            if (i > 0) max_gold = max(max_gold, dp[i-1][j]);
            if (j > 0) max_gold = max(max_gold, dp[i][j-1]);
            if (i > 0 && j > 0) max_gold = max(max_gold, dp[i-1][j-1]);

            dp[i][j] = gold[i][j] + max_gold;
        }
    }

    cout << dp[n-1][m-1] << '\n';
    return 0;
}