/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * Source: folklore
 * Description: Disjoint-set data structure
 * Time: $O(\alpha(N))$
 */
#pragma once
#include <vector>
using namespace std;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
	int find(int x) {
		if (e[x] < 0) return x;
		return e[x] = find(e[x]);
	}
};