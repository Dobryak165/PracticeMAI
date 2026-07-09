// Задание 1 - Никогда не играйте с незнакомцами

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    bool ok = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1] + 1) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Deck looks good" : "Scammed") << '\n';
    return 0;

}

// Задание 2 - Объединение

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; ++i) {
        long long clan_size;
        cin >> clan_size;
        pq.push(clan_size); 
    }

    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        cout << a << ' ' << b << '\n';
        pq.push(a+b);
    }

    return 0;

}

// Задание 3 - Быстрые треугольники

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long answer = 0;
    for (int i = 0; i < n - 2; ++i) {
        for(int j = i+1; j < n - 1; ++j) {
            int sum = a[i] + a[j];
            auto it = lower_bound(a.begin() + j + 1, a.end(), sum);
            int pos = it - a.begin();
            answer += pos - (j+1);
        }
    }

    cout << answer << '\n';
    return 0;

}

// Задание 4 - Симулятор чёрных дыр

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long omega;
    cin >> n >> omega;

    vector<pair<long long, int>> black_holes(n);
    for (int i = 0; i < n; ++i) {
        cin >> black_holes[i].first;
        black_holes[i].second = i + 1;
    }

    sort(black_holes.begin(), black_holes.end());

    long long current = omega;
    vector<int> order;

    for (const auto& p : black_holes) {
        long long mass = p.first;
        int index = p.second;
        if (current > mass) {
            current += mass;
            order.push_back(index);
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (size_t i = 0; i < order.size(); ++i) {
        if (i) cout << ' ';
        cout << order[i];
    }

    cout << '\n';
    return 0;

}

// Задание 5 - Одномерный лабиринт

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> d(N);
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    int Q;
    cin >> Q;
    while (Q--) {
        long long s, f;
        cin >> s >> f;
        long long L = min(s, f);
        long long R = max(s, f);

        auto left = lower_bound(d.begin(), d.end(), L);
        auto right = upper_bound(d.begin(), d.end(), R);
        cout << (right - left) << '\n';
    }

    return 0;
}

// Задание 6 - Готовимся к зачёту

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a0;
    cin >> n >> a0;
    const long long MOD = 1000000007LL;

    long long max1 = -1, max2 = -1;
    long long cur = (a0 * 5) % MOD; // i = 1

    for (long long i = 1; i <= n; ++i) {
        if (cur > max1) {
            max2 = max1;
            max1 = cur;
        } else if (cur > max2) {
            max2 = cur;
        }
        if (i < n) {
            cur = (cur * 5) % MOD;
        }
    }

    if (max1 > max2) swap(max1, max2);
    cout << max1 << ' ' << max2 << '\n';

    return 0;
}

// Задание 7 - Медианы

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        left.push(x);
        right.push(left.top());
        left.pop();

        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
      
        cout << left.top() << '\n';    
    }

    return 0;
}
