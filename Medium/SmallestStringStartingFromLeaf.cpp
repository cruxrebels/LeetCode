/*
Weekly Contest 122
988. Smallest String Starting From Leaf
Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0
represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically 
smaller than "aba".  A leaf of a node is a node that has no children.)

Example 1:
Image - https://assets.leetcode.com/uploads/2019/01/30/tree1.png

Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:
Image - https://assets.leetcode.com/uploads/2019/01/30/tree2.png


Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:
Image - https://assets.leetcode.com/uploads/2019/02/01/tree3.png

Input: [2,2,1,null,1,0,null,0]
Output: "abc"

Note:

The number of nodes in the given tree will be between 1 and 1000.
Each node in the tree will have a value between 0 and 25.

https://leetcode.com/problems/smallest-string-starting-from-leaf/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "|";  // ASCII value greater than 'z', to compare with only other child of a non-leaf node.
        if (!root->left && !root->right) return string(1, 'a' + root->val);
        return min(smallestFromLeaf(root->left), smallestFromLeaf(root->right)) + static_cast<char>('a' + root->val);
    }
};
