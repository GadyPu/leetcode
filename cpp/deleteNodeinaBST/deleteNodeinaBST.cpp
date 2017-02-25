#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
		if(!root) return nullptr;
		function<void(TreeNode *&, int)> erase = [&erase](TreeNode *&x, int val) {
			if (!x) return;
			if(x->val == val) {
				TreeNode *temp = x;
				if(!x->left || !x->right) {
					x = x->left ? x->left : x->right;
					delete temp;
				} else {
					for(temp = x->right; temp->left; temp = temp->left);
					x->val = temp->val;
					erase(x->right, x->val);
				}
			} else if(val < x->val) {
				erase(x->left, val);
			} else {
				erase(x->right, val);
			}
		};
		erase(root, key);
		return root;
    }
};
int main() {
	return 0;
}
