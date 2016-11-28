#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> A(26), B(26);
        for(char &i: s) A[i - 'a']++;
        for(char &i: t) B[i - 'a']++;
        return A == B; 
    }
};
int main() {
    Solution d;
    cout << d.isAnagram("aa", "bb") << '\n';
    return 0;
}
