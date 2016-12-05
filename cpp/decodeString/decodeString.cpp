#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i, s.length());
    }
private:
    string helper(string s, int &i, int n) {
        string res;
        while (i != n) {
            int d = 0;
            string temp;
            while (isdigit(s[i])) d = d * 10 + (s[i++] - '0');
            if (s[i] == '[') {
                i++;
                temp = helper(s, i, n);
            }
            for (int i = 0; i < d; i++) {
                res += temp;
            }
            while (isalpha(s[i])) res += s[i++];
            if (s[i] == ']') {
                i++;
                break;
            }
        }
        return res;
    }
};
int main() {
    Solution d;
	string a = "2[abc]3[cd]ef";
    cout << d.decodeString(a) << '\n';
	return 0;
}
