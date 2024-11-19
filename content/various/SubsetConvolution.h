/**
 * Author: smax
 * Source: https://codeforces.com/blog/entry/72488
 * Description: Computes $\sum_{S' \subseteq S} f(S') g(S \setminus S')$ for all $S$.
 * zetaTransform is SOS DP and mobiusTransform inverts that.
 * Time: O(n^2 2^n)
 * Status: AC on https://codeforces.com/contest/914/problem/G
 */

template<typename T>
vector<T> subsetConvolution(int n, const vector<T> &f, const vector<T> &g) {
	vector<vector<T>> fhat(n + 1, vector<T>(1 << n)), ghat(n + 1, vector<T>(1 << n)), h(n + 1, vector<T>(1 << n));
	for (int mask=0; mask<1<<n; mask++) {
		fhat[__builtin_popcount(mask)][mask] = f[mask];
		ghat[__builtin_popcount(mask)][mask] = g[mask];
	}
	for (int i=0; i<=n; i++) {
		fhat[i] = zetaTransform(n, fhat[i]);
		ghat[i] = zetaTransform(n, ghat[i]);
	}
	for (int mask=0; mask<1<<n; mask++)
		for (int i=0; i<=n; i++) for (int j=0; j<=i; j++)
			h[i][mask] += fhat[j][mask] * ghat[i-j][mask];
	for (int i=0; i<=n; i++) h[i] = mobiusTransform(n, h[i]);
	vector<T> ret(1 << n);
	for (int mask=0; mask<1<<n; mask++)
		ret[mask] = h[__builtin_popcount(mask)][mask];
	return ret;
}
