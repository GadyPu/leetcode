#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    using vec = vector<int>;
    using mat = vector<vec>;
public:
    mat zigzagLevelOrder(TreeNode* root) {
        if(!root) return ans;
        int cur = 0;
        vector<TreeNode *> Q[2];
        Q[cur].push_back(root);
        auto expandState = [&](vector<TreeNode *>& from, vector<TreeNode *>& to) {
            to.clear();
            for(auto &r: from) {
                if(r->left) to.push_back(r->left);
                if(r->right) to.push_back(r->right);
            }
        };
        while(!Q[cur].empty()) {
            vec temp;
            for(auto &r: Q[cur]) temp.push_back(r->val);
            if(cur & 1) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            expandState(Q[cur], Q[cur ^ 1]);
            cur ^= 1;
        }
        return ans;
    }
private:
    mat ans;
};
int main() {
	return 0; 
}
