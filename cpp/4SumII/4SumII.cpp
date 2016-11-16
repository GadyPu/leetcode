#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int res = 0;
		vector<int> temp;
		for(int &i: A) {
			for(int &j: B) {
				temp.push_back(i + j);
			}
		}
		sort(temp.begin(), temp.end());
		for(int &i: C) {
			for(int &j: D) {
				int d = -(i + j);
				res += upper_bound(temp.begin(), temp.end(), d) - lower_bound(temp.begin(), temp.end(), d);
			}
		}
		return res;
    }
};
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int res = 0;
		unordered_map<int, int> H;
		for(int &i: A) {
			for(int &j: B) {
				H[i + j]++;
			}
		}
		for(int &i: C) {
			for(int &j: D) {
				int d = -(i + j);
				res += H[d];
			}
		}
		return res;
    }
};
int main() {
	vector<int> A = { 1, 2 };
	vector<int> B = { -2, -1 };
	vector<int> C = { -1, 2 };
	vector<int> D = { 0, 2 };
	Solution d;
	cout << d.fourSumCount(A, B, C, D) << '\n';
	return 0;
}
