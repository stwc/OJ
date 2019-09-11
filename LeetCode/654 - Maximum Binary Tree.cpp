// Time: O(n^2), need to be optimized

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        return findMax(l, r, nums);
    }

    TreeNode *findMax(int l, int r, vector<int> &nums)
    {
        if (l > r)
            return NULL;

        int maxIdx = l;
        for (int i = l; i <= r; ++i) {
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }
        TreeNode *root = new TreeNode(nums[maxIdx]);
        root->left = findMax(l, maxIdx - 1, nums);
        root->right = findMax(maxIdx + 1, r, nums);
        return root;
    }
};
