/**
 * Author: YouKn0wWho
 * Source: https://github.com/ShahjalalShohag/code-library/blob/master/Geometry/Geometry%202D.cpp#L1151
 * Description: Finds the radius of an inscribed circle of a convex polygon.
 * The truncate(r) method gets the vector in same direction but with magnitude r.
 */

double maximum_inscribed_circle(vector<PT> p) {
	int n = p.size();
	if (n <= 2) return 0;
	double l = 0, r = 20000;
	while (r - l > eps) {
		double mid = (l + r) * 0.5;
		vector<HP> h;
		const int L = 1e9;
		h.push_back(HP(PT(-L, -L), PT(L, -L)));
		h.push_back(HP(PT(L, -L), PT(L, L)));
		h.push_back(HP(PT(L, L), PT(-L, L)));
		h.push_back(HP(PT(-L, L), PT(-L, -L)));
		for (int i = 0; i < n; i++) {
			PT z = (p[(i + 1) % n] - p[i]).perp();
			z = z.truncate(mid);
			PT y = p[i] + z, q = p[(i + 1) % n] + z;
			h.push_back(HP(p[i] + z, p[(i + 1) % n] + z));
		}
		vector<PT> nw = half_plane_intersection(h);
		if (!nw.empty()) l = mid;
		else r = mid;
	}
	return l;
}
