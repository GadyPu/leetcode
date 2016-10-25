#define LOCAL
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		int d = 0;
		string res = "0";
		if(num1 == "0" && num2 == "0") return res;
		size_t i = 0, n = num1.length(), m = num2.length();
		string &A = n <= m ? num1 : num2;
		string &B = n <= m ? num2 : num1;
		res.resize(max(n, m) + 2, '0');
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		for(i = 0; i < A.length(); i++) {
			int v = (A[i] - '0') + (B[i] - '0') + d;
			d = v / 10;
			res[i] = v % 10 + '0';
		}
		for(; i < B.length(); i++) {
			int v = (res[i] - '0') + (B[i] - '0') + d;
			d = v / 10;
			res[i] = v % 10 + '0';
		}
		if(d) res[i] = d + '0';
		i = res.length() - 1;
		if(res[i] == '0') {
			while(res[i] == '0') i--; 
			res.erase(i + 1, res.length());
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
#endif
	Solution d;
	string A, B;
	while(cin >> A >> B) {
		string res = d.addStrings(A, B);
		cout << A << '+' << B << '=' << res << '\n';
	}
	return 0;
}
