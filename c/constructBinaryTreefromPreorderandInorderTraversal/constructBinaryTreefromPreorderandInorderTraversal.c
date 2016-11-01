#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/*
struct TreeNode* helper(int *preorder, int *inorder, int pindex, int iindex, int size, int length) {
	if(!size) return NULL;
	int v = preorder[pindex];
	struct TreeNode *x = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	x->val = v;
	int i, rindex = 0;
	for(i = iindex; i < length; i++) {
		if(inorder[i] == v) break;
		rindex++;
	}
	x->left = helper(preorder, inorder, pindex + 1, iindex, rindex, length);
	x->right = helper(preorder, inorder, pindex + rindex + 1, iindex + rindex + 1, size - (rindex + 1), length);
	return x;
}
*/
struct TreeNode* helper(int *preorder, int *inorder, int rindex, int start, int end) {
	if(start > end) return NULL;
	struct TreeNode *x = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	x->val = preorder[rindex];
	int i, pos = 0;
	for(i = start; i <= end; i++) {
		if(x->val == inorder[i]) {
			pos = i;
			break;
		}
	}
	x->left = helper(preorder, inorder, rindex + 1, start, pos - 1);
	x->right = helper(preorder, inorder,  rindex + (pos - start) + 1, pos + 1, end);
	return x;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	if(!preorder || !inorder) return NULL;
	return helper(preorder, inorder, 0, 0, preorderSize = inorderSize - 1);
}
void P(struct TreeNode* root) {
	if(!root) return;
	P(root->left);
	P(root->right);
	printf("%d ", root->val);
}
int main() {
	int preorder[] = { 7, 4, 2, 1, 3, 6, 5, 9, 8, 10 };
	int inorder[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	struct TreeNode *root = buildTree(preorder, sizeof(preorder) / sizeof(int), inorder, sizeof(inorder) / sizeof(int));
	P(root);
	putchar('\n');
	return 0;
}
