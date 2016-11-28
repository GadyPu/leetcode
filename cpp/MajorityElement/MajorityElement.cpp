#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> A;
        for(auto &r: nums) {
            if(A.empty())  {
                A.push(r);
            } else if(A.top() == r) {
                A.push(r);
            } else {
                A.pop();
            }
        }
       return A.top();
    }
    int majorityElement_1(vector<int>& nums) {
        int res, tot = 0;
        for(auto &r: nums) {
            if(!tot)  {
                res = r;
                tot++;
            } else if(res == r) {
                tot++;
            } else {
                tot--;
            }
        }
       return res; 
    }
};
int main() {
    vector<int> A = { 3, 2, 1, 3, 3, 4, 3 };
    Solution d;
    cout << d.majorityElement(A) << '\n';
    cout << d.majorityElement_1(A) << '\n';
    return 0;
}
