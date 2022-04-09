#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

using pdd = pair<double, double>;
using vd = vector<pdd>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto pts = vd(n);
	for (int i = 0; i < n; ++i) {
		double x, y;
		cin >> x >> y;

		pts[i] = { x, y };
	}

	auto mx = double{ 0 };
	for (int i = 0; i < n; ++i) {
		const auto& [x1, y1] = pts[i];
		for (int j = i + 1; j < n; ++j) {
			const auto& [x2, y2] = pts[j];
			for (int k = j + 1; k < n; ++k) {
				const auto& [x3, y3] = pts[k];

				const auto& vx = x3 - x1;
				const auto& vy = y3 - y1;

				const auto& wx = x3 - x2;
				const auto& wy = y3 - y2;

				const auto& area = abs(vx * wy - vy * wx) / 2;
				if (mx < area) {
					mx = area;
				}
			}
		}
	}

	cout << fixed << setprecision(10) << mx;

	return 0;
}