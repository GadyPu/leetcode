#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
		for(auto &r: bank) {
			A[0].insert(r);
		}
		size_t n = end.length();
		q.push({ start, 0 });
		A[1].insert(start);
		while(!q.empty()) {
			auto t = q.front(); q.pop();
			if(t.first == end) return t.second;
			for(size_t i = 0; i < n; i++) {
				auto x = t.first;
				for(int j = 0; j < 4; j++) {
					if(x[i] == dic[j]) continue;
					x[i] = dic[j];
					if(A[0].find(x) != A[0].end() && A[1].find(x) == A[1].end()) {
						q.push({ x, t.second + 1 });
						A[1].insert(x);
					}
				}
			}
		}
		return -1;
    }
private:
	const char *dic = "AGCT";
	queue<pair<string, int>> q;
	unordered_set<string> A[2];
};
int main() {
	Solution d;
	vector<string> bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
	cout <<	d.minMutation("AAAAACCC", "AACCCCCC", bank) << '\n';
	return 0;
}

