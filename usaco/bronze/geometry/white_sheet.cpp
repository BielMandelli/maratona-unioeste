#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

struct Rectangle {
	int x1, y1, x2, y2;
	int area() { return (y2 - y1) * (x2 - x1); }
};

Rectangle intersect(Rectangle p, Rectangle q) {
	Rectangle wb;
	wb.x1 = max(min(p.x1, p.x2), min(q.x1, q.x2));
	wb.x2 = min(max(p.x1, p.x2), max(q.x1, q.x2));
	wb.y2 = min(max(p.y1, p.y2), max(q.y1, q.y2));
	wb.y1 = max(min(p.y1, p.y2), min(q.y1, q.y2));

    if (wb.x2 <= wb.x1 || wb.y2 <= wb.y1) wb.x1 = wb.x2 = wb.y1 = wb.y2 = 0;

	return wb;
}

signed main()
{
    bieo;
    Rectangle a, b, c, wb1, wb2, bb;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;

    wb1 = intersect(a,b);
    wb2 = intersect(a,c);
    bb = intersect(wb1, wb2);

    if(a.area() > wb1.area() + wb2.area() - bb.area()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}