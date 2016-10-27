#include <bits/stdc++.h>
using namespace std;
class Solution {
	using vec = vector<string>;
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
		for(auto &r: bank) dic.insert(r);
		int cur = 0, rcur = 0;
		Q[cur].push_back(start);
		rQ[rcur].push_back(end);
		bfs.insert(start); rbfs.insert(end);
		auto expandState = [&, this](vec &from, vec &to, unordered_set<string> &hash) {
			to.clear();
			for(auto &r: from) {
				for(size_t i = 0; i < r.length(); i++) {
					for(int j = 0; j < 4; j++) {
						string x = r;
						x[i] = buf[j];
						if(dic.find(x) == dic.end() || hash.find(x) != hash.end()) continue;
						hash.insert(x);
						to.push_back(x);
					}
				}
			}
		};
		for(int step = 0; !Q[cur].empty() && !rQ[rcur].empty(); step++) {
			if(Q[cur].size() <= rQ[rcur].size()) {
				expandState(Q[cur], Q[cur ^ 1], bfs);
				cur ^= 1;
				for(auto &r: Q[cur]) {
					if(rbfs.find(r) != rbfs.end()) return step + 1;
				}
			} else {
				expandState(rQ[rcur], rQ[rcur ^ 1], rbfs);
				rcur ^= 1;	
				for(auto &r: rQ[rcur]) {
					if(bfs.find(r) != bfs.end()) return step + 1;
				}
			}
		}
		return -1;
    }
private:
	vec Q[2], rQ[2];
	const char *buf = "AGCT";
	unordered_set<string> dic, bfs, rbfs;
};
int main() {
	Solution d;
	vector<string> bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
	cout <<	d.minMutation("AAAAACCC", "AACCCCCC", bank) << '\n';
	return 0;
}
