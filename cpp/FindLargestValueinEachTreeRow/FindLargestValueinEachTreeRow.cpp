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
    using vec = vector<TreeNode *>;
public:
    vector<int> largestValues(TreeNode* root) {
       if (!root) return { };
       size_t cur = 0;
       vector<int> res;
       vec Q[2];
       Q[cur].push_back(root);
       res.push_back(root->val);
       auto expandNode = [&](vec &from, vec &to) {
           to.clear();
           for (auto &i: from) {
               if (i->left) {
                   to.push_back(i->left);
               }
               if (i->right) {
                   to.push_back(i->right);
               }
           }
       };
       while (!Q[cur].empty()) {
           expandNode(Q[cur], Q[cur ^ 1]);
           cur ^= 1;
           if (!Q[cur].empty()) {
               auto value = max_element(Q[cur].begin(), Q[cur].end(), [&](TreeNode *A, TreeNode *B) ->int {
                            return A->val < B->val;
                       });
               res.push_back((*value)->val);
           }
       }
       return res;
    }
};
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    Solution d;
    auto res = d.largestValues(root);
    for (auto &i: res) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
