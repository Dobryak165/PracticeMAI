// Задача D - Два прямоугольника

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