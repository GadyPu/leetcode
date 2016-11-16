#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = 0;
		vector<int> res;
		multiset<int> H;
		unordered_map<int, int> C;
		if(!(n = nums.size())) return res;
		for(int l = 0, r = k - 1; r < n; l++, r++) {
			if(!l) {
				for(int d = l; d <= r; d++) {
					C[nums[d]]++;
					H.insert(nums[d]);
				}
			} else {
				C[nums[r]]++;
				H.insert(nums[r]);
			}
			res.push_back(*H.rbegin());
			if(--C[nums[l]] > 0) {
				continue;
			}
			H.erase(nums[l]);
		}
		return res;
    }
};
int main() {
	vector<int> nums = { -7, -8, 7, 5, 7, 1, 6, 0 };
	Solution d;
	for(int &i: d.maxSlidingWindow(nums, 4)) {
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}
