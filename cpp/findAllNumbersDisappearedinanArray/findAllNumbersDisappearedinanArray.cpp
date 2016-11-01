#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();
		if(!n) return res;
		vector<bool> d(n + 1, false);
		for(int &r: nums) d[r] = true; 
		for(int i = 1; i <= n; i++) {
			if(!d[i]) res.emplace_back(i);
		}
		return res;
    }
};
int main() {
	vector<int> d = { 4, 3, 2, 7, 8, 2, 3, 1 };
	Solution a;
	auto ans = a.findDisappearedNumbers(d);
	for(int &i: ans) cout << i << ' ';
	cout << '\n';
	return 0;
}
