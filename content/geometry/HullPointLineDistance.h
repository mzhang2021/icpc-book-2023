/**
 * Author: YouKn0wWho
 * Source: https://github.com/ShahjalalShohag/code-library/blob/master/Geometry/Geometry%202D.cpp#L845
 * Description: Finds the min dist from point (assuming not inside) or line to convex hull.
 * First 2 arguments of dist\_from\_point\_to\_seg are segment endpoints.
 * Time: $O(\log n)$
 */

int sign(double x) { return (x > eps) - (x < -eps); }

PT angle_bisector(PT &a, PT &b, PT &c){
    PT p = a - b, q = c - b;
    return p + q * sqrt(dot(p, p) / dot(q, q));
}

double dist_from_point_to_polygon(vector<PT> &v, PT p) { // O(log n)
    int n = (int)v.size();
    if (n <= 3) {
    	double ans = inf;
	    for(int i = 0; i < n; i++) ans = min(ans, dist_from_point_to_seg(v[i], v[(i + 1) % n], p));
	    return ans;
	}
    PT bscur, bs = angle_bisector(v[n - 1], v[0], v[1]);
    int ok,  i,  pw = 1,  ans = 0,  sgncur,  sgn = sign(cross(bs, p - v[0]));
    while (pw <= n) pw <<= 1;
    while ((pw >>= 1)) {
        if ((i = ans + pw) < n) {
            bscur = angle_bisector(v[i - 1], v[i], v[(i + 1) % n]);
            sgncur = sign(cross(bscur, p - v[i]));
            ok = sign(cross(bs, bscur)) >= 0 ? (sgn >= 0 || sgncur <= 0) : (sgn >= 0 && sgncur <= 0);
            if (ok) ans = i, bs = bscur, sgn = sgncur;
        }
    }
    return dist_from_point_to_seg(v[ans], v[(ans + 1) % n], p);
}

inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }

// minimum distance from convex polygon p to line ab
// returns 0 is it intersects with the polygon
// top - upper right vertex
double dist_from_polygon_to_line(vector<PT> &p, PT a, PT b, int top) { //O(log n)
	PT orth = (b - a).perp();
	if (orientation(a, b, p[0]) > 0) orth = (a - b).perp();
	int id = extreme_vertex(p, orth, top);
	if (dot(p[id] - a, orth) > 0) return 0.0; //if orth and a are in the same half of the line, then poly and line intersects
	return dist_from_point_to_line(a, b, p[id]); //does not intersect
}
