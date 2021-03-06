#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL || root->left == NULL && root->right == NULL) return true;
		return helper(root->left, root->right);
		
	}
	bool helper(TreeNode* left, TreeNode* right) {
		if (!left && !right)
			return true;
		else if (!left || !right )
			return false;
		if (left->val != right->val)
			return false;
		return helper(left->left, right->right) && helper(left->right, right->left);
	}
};

//iteration solution
//class Solution {
//public:
//	bool isSymmetric(TreeNode *root) {
//		TreeNode *left, *right;
//		if (!root)
//			return true;
//
//		queue<TreeNode*> q1, q2;
//		q1.push(root->left);
//		q2.push(root->right);
//		while (!q1.empty() && !q2.empty()) {
//			left = q1.front();
//			q1.pop();
//			right = q2.front();
//			q2.pop();
//			if (NULL == left && NULL == right)
//				continue;
//			if (NULL == left || NULL == right)
//				return false;
//			if (left->val != right->val)
//				return false;
//			q1.push(left->left);
//			q1.push(left->right);
//			q2.push(right->right);
//			q2.push(right->left);
//		}
//		return true;
//	}
//};