// Задание 1 - Запуск зонда

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long answer = 1;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        answer = answer / __gcd(answer, x) * x;
    }

    cout << answer << '\n';
    return 0;
}

// Задание 2 - Перемножим цифры

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n == 0) {
            cout << 10 << '\n';
            continue;
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        int cnt[10] = {0};
        long long temp = n;

        for (int d = 9; d >= 2; --d) {
            while (temp % d == 0) {
                cnt[d]++;
                temp /= d;
            }
        }

        if (temp > 1) {
            cout << -1 << '\n';
        } else {
            string answer;
            for (int d = 2; d <= 9; ++d) {
                answer.append(cnt[d], char('0' + d));
            }
            cout << answer << '\n';
        }
    }

    return 0;
}

// Задание 3 - Хороводоводы

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long factorial = 1;
    for (int i = 2; i <= N - 1; ++i) {
        factorial = factorial * i % MOD;
    }

    long long answer = factorial * ((MOD+1) / 2) % MOD;

    cout << answer << '\n';
    return 0;
}

// Задание 6 - Делители

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> count(8, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        count[a]++;
    }

    if (count[5] != 0 || count[7] != 0) {
        cout << -1 << '\n';
        return 0;
    }

    int x = count[4];
    int z = count[3];
    int y = count[1] - x - z;

    if (y < 0 || y != count[2] - x || y != count[6] - z) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < x; ++i)
        cout << "1 2 4\n";
    for (int i = 0; i < y; ++i)
        cout << "1 2 6 \n";
    for (int i = 0; i < z; ++i)
        cout << "1 3 6\n";

    return 0;
}

// Задание 9 - Целые точки

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long dx = llabs(x2 - x1);
        long long dy = llabs(y2 - y1);

        long long g = __gcd(dx, dy);
        cout << g + 1 << '\n';
    }

    return 0;
}