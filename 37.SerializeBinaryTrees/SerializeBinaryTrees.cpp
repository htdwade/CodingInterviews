/*

剑指Offer
面试题37：序列化二叉树

题目：请实现两个函数，分别用来序列化和反序列化二叉树。

*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		serializeCore(root, res);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty())
			return nullptr;
		queue<string> node;
		string s = "";
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == ',') {
				node.push(s);
				s.clear();
			}
			else
				s += data[i];
		}
		TreeNode* root = deserializeCore(node);
		return root;
	}

private:
	void serializeCore(TreeNode* root, string& res) {
		if (root == nullptr) {
			res += "$,";
			return;
		}
		res += to_string(root->val) + ',';
		serializeCore(root->left, res);
		serializeCore(root->right, res);
	}

	TreeNode* deserializeCore(queue<string>& node) {
		if (node.empty())
			return nullptr;
		string s = node.front();
		node.pop();
		if (s == "$")
			return nullptr;
		TreeNode* root = new TreeNode(stoi(s));
		root->left = deserializeCore(node);
		root->right = deserializeCore(node);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

TreeNode* createBinaryTree() {
	int x;
	cin >> x;
	if (x == 0)
		return nullptr;
	TreeNode* root = new TreeNode(x);
	root->left = createBinaryTree();
	root->right = createBinaryTree();
	return root;
}

void preorderPrint(TreeNode* root) {
	if (root) {
		cout << root->val << '\t';
		preorderPrint(root->left);
		preorderPrint(root->right);
	}
}

int main()
{
	Codec codec;
	TreeNode* root = createBinaryTree();
	cout << "二叉树创建完成" << endl;
	preorderPrint(root);
	cout << "\n\n";
	TreeNode* newRoot = codec.deserialize(codec.serialize(root));
	preorderPrint(root);
	return 0;
}