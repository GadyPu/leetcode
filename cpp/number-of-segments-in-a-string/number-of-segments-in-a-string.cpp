#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && (!i || s[i - 1] == ' ')) ans++;
        }
        return ans;
    }
};
int main() {
    Solution d;
    cout << d.countSegments("Hello, my name is John Hello World             Gady Pu") << '\n';
    return 0;
}
