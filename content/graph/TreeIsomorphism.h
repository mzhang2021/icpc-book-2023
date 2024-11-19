/**
 * Author: smax
 * Description: Compresses a rooted tree for checking tree isomorphism. To compare unrooted trees, root at centroid.
 * Time: $O(n \log n)$
 * Status: AC on https://cses.fi/problemset/task/1701
 */

vector<vector<string>> isomorphism(const vector<vector<int>> &adj, int r) {
	vector<vector<int>> nodes;
	auto dfs = [&] (auto &self, int u, int p, int d) -> void {
		if (d == (int) nodes.size()) nodes.emplace_back();
		nodes[d].push_back(u);
		for (int v : adj[u]) if (v != p)
			self(self, v, u, d + 1);
	};
	dfs(dfs, r, -1, 0);
	vector<int> id(n, -1);
	vector<vector<string>> ret(nodes.size());
	for (int i=(int)nodes.size()-1; i>=0; i--) {
		vector<pair<string, int>> cur;
		for (int u : nodes[i]) {
			vector<int> all;
			for (int v : adj[u]) if (id[v] != -1)
				all.push_back(id[v]);
			sort(all.begin(), all.end());
			string s; for (int x : all) s += char(x);
			ret[i].push_back(s); cur.emplace_back(s, u);
		}
		sort(ret[i].begin(), ret[i].end());
		sort(cur.begin(), cur.end());
		for (int j=0, x=0; j<(int)cur.size(); x++) {
			int k = j; while (k < (int) cur.size() && cur[j].first == cur[k].first)
				id[cur[k++].second] = x;
			j = k;
		}
	}
	return ret;
}
