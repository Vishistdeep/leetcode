/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> ans;
    void inorder(TreeNode*root)
    {
        if(root == nullptr)
            return;

        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);

        return;

    }

    bool asec(vector<int>ans)
    {
        if(is_sorted(ans.begin(),ans.end()))
            return true;
        
        return false;
    }

    bool duplicates(vector<int> ans)
    {
        set<int>st;
        for(auto&it:ans)
        {
            st.insert(it);
        }

        cout << st.size() << " " << ans.size();
        if(st.size() != ans.size())
            return false;
        
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        inorder(root);

        return( asec(ans) && duplicates(ans) );
    }
};