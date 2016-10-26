#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
  		vector<int> res;
		unordered_set<int> vis;
		for(int &r: nums) {
			if(vis.find(r) == vis.end()) vis.insert(r);
			else res.push_back(r);
		}
		return res;
    }
};
int main() {
	vector<int> A = { 4, 3, 2, 7, 2, 3, 1};
	Solution d;
	vector<int> res = d.findDuplicates(A);
	for(int &r: res) cout << r << ' ';
	cout << '\n';
	return 0;
}
