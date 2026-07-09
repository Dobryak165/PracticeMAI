// Задание 1 - Сложение

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> diff(N+2, 0);

    while (Q--) {
        int l, r;
        long long v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r+1] -= v;
    }

    long long current = 0;
    for (int i = 1; i <= N; ++i) {
        current += diff[i];
        cout << current << (i == N ? '\n' : ' ');
    }

    return 0;
}

// Задание 2 - Максимумы

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    long long answer = 0;
    for (int i = 0; i < N; ++i) {
        int maximum = a[i];
        for (int j = i; j < N; ++j) {
            if (a[j] > maximum) maximum = a[j];
            answer += maximum;
        }
    }

    cout << answer << '\n';
    return 0;
}

// Задание 3 - Ясновидящий

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long current = a[0], best = a[0];
    int l = 0, r = 0, currentL = 0;

    for (int i = 1; i < n; ++i) {
        if (current + a[i] < a[i]) {
            current = a[i];
            currentL = i;
        } else {
            current += a[i];
        }

        if (current > best) {
            best = current;
            l = currentL;
            r = i;
        } else if (current == best) {
            if (currentL < l || (currentL == l && i < r)) {
                l = currentL;
                r = i;
            }
        }
    }

    if (best > 0)
        cout << l + 1 << ' ' << r + 2 << '\n';
    else   
        cout << "-1 -1\n";

    return 0;

}

// Задание 4 - Дмитрий и дисперсия

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        unordered_map<long long, int> count;
        int left = 0, best = 0;

        for (int right = 0; right < n; ++right) {
            count[a[right]]++;
            while (count[a[right]] > 1) {
                count[a[left]]--;
                if (count[a[left]] == 0) count.erase(a[left]);
                left++;
            }
            best = max(best, right - left + 1);
        }

        cout << best << '\n';
    }

    return 0;
}

// Задание 5 - Большие суммы

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long binpow(long long a, long long e) {
    long long result = 1;
    while (e) {
        if (e & 1) result = result * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        sum = (sum + x) % MOD;
        if (sum < 0) sum += MOD;
    }

    long long answer = sum * binpow(2, n-1) % MOD;
    cout << answer << '\n';

    return 0;
}

// Задание 6 - Счастливые тройки

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    long long answer = 0;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (r < i) r = i;
        while (r + 1 < n && a[r + 1] - a[i] <= k) ++r;
        long long m = r - i;
        if (m >= 2) answer += m * (m - 1) / 2;
    }

    cout << answer << '\n';
    return 0;
}
