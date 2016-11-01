#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* helper(int *inorder, int *postorder, int rindex, int start, int end) {
	if(start > end || rindex < 0) return NULL;
	struct TreeNode *x = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	x->val = postorder[rindex];
	int i, pos = 0;
	for(i = start; i <= end; i++) {
		if(x->val == inorder[i]) {
			pos = i;
			break;
		}
	}
	x->left = helper(inorder, postorder, rindex - (end - pos) - 1, start, pos - 1);
	x->right = helper(inorder, postorder, rindex - 1, pos + 1, end);
	return x;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	if(!inorder || !postorder) return NULL;
	return helper(inorder, postorder, postorderSize - 1, 0, inorderSize - 1);
}
void P(struct TreeNode *x) {
	if(!x) return;
	printf("%d ", x->val);
	P(x->left);
	P(x->right);
}
int main() {
	int inorder[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int postorder[] = { 1, 3, 2, 5, 6, 4, 8, 10, 9, 7 };
	struct TreeNode *root = buildTree(inorder, sizeof(inorder) / sizeof(int), postorder,  sizeof(postorder) / sizeof(int));
	P(root);
	putchar('\n');
	return 0;
}
