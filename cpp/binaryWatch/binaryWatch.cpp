#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> res;
		if(num < 0 || num > 8) return res;
		if(!num) {
			res.push_back("0:00");
			return res;
		}
		auto F = [&](int ub, int n)->vector<int> {
			vector<int> temp;
			if(!n) return temp;
			auto C = [&](int v, int n)->bool {
				int tot = 0;
				while(v) {
					v &= v - 1;
					tot++;
				}
				return tot == n;
			};
			int l = (1 << n) - 1, r = [=]() mutable ->int {
				int ans = 0;
				while(n--) {
					ans += 1 << (ub - 1);
					ub--;
				}
				return ans;
			}();
			for(int i = l; i <= r; i++) {
				if(C(i, n)) {
					temp.push_back(i);
				}
			}
			return temp;
		};
		for(int i = 0; i < 4; i++) {
			int j = num - i;
			if(j < 0 || j > 6) continue;
			vector<int> A = F(4, i), B = F(6, j);
			if(A.empty()) {
				for(int &r: B) {
					if(r > 59) continue;
					if(r < 10) res.push_back("0:0" + to_string(r));
					else res.push_back("0:" + to_string(r));
				}
			} else if(B.empty()) {
				for(int &r: A) {
					if(r > 11) continue;
					res.push_back(to_string(r) + ":00");
				}
			} else {
				for(int &r: A) {
					for(int &c: B) {
						if(c > 59 || r > 11) continue;
						if(c < 10) res.push_back(to_string(r) + ":0" + to_string(c));
						else res.push_back(to_string(r) + ":" + to_string(c));
					}
				}
			}
		}
		return res;
	}
};
int main() {
	Solution d;
	auto ans = d.readBinaryWatch(6);
	for(auto &r: ans) {
		cout << r << '\n';
	}
	return 0;
}
