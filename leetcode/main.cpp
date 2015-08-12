#include <iostream>
#include "ValidateBinarySearchTree.cpp"

using namespace std;

int main() {
    Solution s;

    TreeNode *p1 = new TreeNode(0);
    TreeNode *p2 = new TreeNode(-1);
    p1->left = p2;

    cout << s.isValidBST(p1) << endl;

    delete p1;
    delete p2;
    return 0;
}