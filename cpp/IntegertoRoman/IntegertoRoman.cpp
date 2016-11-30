#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<pair<string, int>> mp = {
            { "M", 1000 },
            { "CM", 900 },
            { "D", 500 },
            { "CD", 400 },
            { "C", 100 },
            { "XC", 90 },
            { "L", 50 },
            { "XL", 40 },
            { "X", 10 },
            { "IX", 9 },
            { "V", 5 },
            { "IV", 4 },
            { "I", 1 }
        };
        for(auto &r: mp) {
            int d = num / r.second;
            while(d) {
                res += r.first;
                d--;
            }
            num = num % r.second;
        }
        return res;
    }
};
int main() {
    Solution d;
    cout << d.intToRoman(2016) << '\n';
    return 0;
}
