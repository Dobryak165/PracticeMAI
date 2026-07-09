// Задача 1 - Развороты 

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

    int l, r;
    while (true) {
        cin >> l >> r;
        if (l == 0 && r == 0) break;

        int left = l - 1;
        int right = r - 1;

        while (left < right) {
            swap(a[left], a[right]);
            ++left;
            --right;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i+1 == n ? '\n' : ' ');
    }

    return 0;
}

// Задача 2 - Треугольники 

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

// Задача 3 - Сортировки

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }

        long long perestanovki = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (a[i] > a[j]) {
                    ++perestanovki;
                }
            }
        }

        cout << perestanovki << '\n';
    }

    return 0;
}

// Задача 4 - Два прямоугольника

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int xmin1 = min(x1, x2), xmax1 = max(x1, x2);
    int ymin1 = min(y1, y2), ymax1 = max(y1, y2);

    int xmin2 = min(x3, x4), xmax2 = max(x3, x4);
    int ymin2 = min(y3, y4), ymax2 = max(y3, y4);

    int area1 = (xmax1 - xmin1) * (ymax1 - ymin1);
    int area2 = (xmax2 - xmin2) * (ymax2 - ymin2);
    
    int xmin_intersection = max(xmin1, xmin2);
    int xmax_intersection = min(xmax1, xmax2);
    int ymin_intersection = max(ymin1, ymin2);
    int ymax_intersection = min(ymax1, ymax2);

    int overlap = 0;
    if (xmin_intersection < xmax_intersection && ymin_intersection < ymax_intersection) {
        overlap = (xmax_intersection - xmin_intersection) * (ymax_intersection - ymin_intersection);
    }

    int union_area = area1 + area2 - overlap;
    cout << union_area << '\n';
    return 0;
}

// Задача 5 - Экстремумы

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

    vector<int> local_min, local_max;

    if (n == 1) {
        local_min.push_back(1);
        local_max.push_back(1);
    } else {
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (a[0] < a[1]) local_min.push_back(1);
                else local_max.push_back(1);
            } else if (i == n - 1) {
                if (a[n - 2] > a[n - 1]) local_min.push_back(n);
                else local_max.push_back(n);
            } else {
                if (a[i - 1] > a[i] && a[i] < a[i + 1]) local_min.push_back(i + 1);
                else if (a[i - 1] < a[i] && a[i] > a[i + 1]) local_max.push_back(i + 1);
            }
        }
    }

    int idx_min = 0, idx_max = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[idx_min]) idx_min = i;
        if (a[i] > a[idx_max]) idx_max = i;
    }

    cout << local_min.size();
    for (int p : local_min) cout << ' ' << p;
    cout << '\n';

    cout << local_max.size();
    for (int p : local_max) cout << ' ' << p;
    cout << '\n';

    cout << idx_min + 1 << ' ' << idx_max + 1 << '\n';

    return 0;
}

// Задача 6 - Снова сумма

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int_sum = 0, frac_sum = 0;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        size_t dot = line.find('.');
        string int_part, frac_part;

        if (dot == string::npos) {
            int_part = line;
            frac_part = string(15, '0');
        } else {
            int_part = line.substr(0, dot);
            frac_part = line.substr(dot + 1);
            if (frac_part.size() < 15) frac_part.append(15 - frac_part.size(), '0');
            else if (frac_part.size() > 15) frac_part = frac_part.substr(0, 15);
        }

        int_sum += stoll(int_part);
        frac_sum += stoll(frac_part);
    }

    int_sum += frac_sum / 1000000000000000LL;
    frac_sum %= 1000000000000000LL;

    cout << int_sum << '.';
    string frac_str = to_string(frac_sum);
    frac_str = string(15 - frac_str.size(), '0') + frac_str;
    cout << frac_str << '\n';

    return 0;
}

// Задача 7 - Пляж

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long total_cells = 0;
    long long total_sum = 0;
    long long d = 1;

    while (true) {
        long long cnt = 4 * (n + d - 1);

        if (total_cells + cnt >= k) {
            long long need = k - total_cells;
            total_sum += need * d;
            break;
        } else {
            total_cells += cnt;
            total_sum += cnt * d;
            ++d;
        }
    }

    cout << total_sum << '\n';
    return 0;
}

// Задача 8 - Любимое число

#include <iostream>
using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;

    long long step = 1LL << k;      
    long long max_t = n / step;     

    if (max_t == 0) {
        cout << -1 << '\n';   
        return 0;
    }

    long long t = max_t;
    if (t % 2 == 0) --t;           

    long long m = step * t;         
    cout << m << '\n';

    return 0;
}