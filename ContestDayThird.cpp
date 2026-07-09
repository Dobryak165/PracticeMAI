// Задание 1 - Егор строит НВП

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = n; i >= 1; --i) {
        if (i < n) cout << ' ';
        cout << i;
    }
    cout << '\n';

    return 0;
}

// Задание 2 - Кузнечик и опасности

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<bool> danger(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        danger[a] = true;
    }

    vector<long long> dp(n + 1, 0), pref(n + 1, 0);
    dp[0] = 1;
    pref[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if (danger[i]) {
            dp[i] = 0;
        } else {
            int L = max(0, i - k);
            long long sum = pref[i - 1];
            if (L > 0) sum = (sum - pref[L - 1] + MOD) % MOD;
            dp[i] = sum;
        }
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] % MOD << '\n';
    return 0;
}

// Задание 3 - Непростой кузнечик

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r;
    cin >> l >> r;

    vector<int> dp(r + 1, 0);
    dp[1] = 1;

    for (int i = 1; i <= r; ++i) {
        if (dp[i] == 0) continue;
        for (int j = 2 * i; j <= r; j += i) {
            dp[j] += dp[i];
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    long long answer = 0;
    for (int i = l; i <= r; ++i) {
        answer += dp[i];
        if (answer >= MOD) answer -= MOD;
    }

    cout << answer % MOD << '\n';
    return 0;
}

// Задание 4 - Черепашка и опасности

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> danger(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        danger[x][y] = true;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 && j == 0) continue;
            if (danger[i][j]) {
                dp[i][j] = 0;
            } else {
                int answer = 0;
                if (i > 0) answer = (answer + dp[i - 1][j]) % MOD;
                if (j > 0) answer = (answer + dp[i][j - 1]) % MOD;
                dp[i][j] = answer;
            }
        }
    }

    cout << dp[n][m] % MOD << '\n';
    return 0;
}

// Задание 5 - Диггер

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

// Задание 6 - Преобразуй число

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> dp(N + 1, 0);
    dp[1] = 0;

    for (int i = 2; i <= N; ++i) {
        long long best = i + dp[i - 1];
        if (i % 2 == 0) {
            best = min(best, (long long)i + dp[i / 2]);
        }
        if (i % 3 == 0) {
            best = min(best, (long long)i + dp[i / 3]);
        }
        dp[i] = best;
    }

    cout << dp[N] << '\n';
    return 0;
}