/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
*/

bool pathSum(TreeNode* root,int targetSum) {
    if(!root){
        return false;
    }
    targetSum-=root->val;

    if(!root->left && !root->right){  // leaf node
        return (targetSum == root->val);
    }

    return pathSum(root->left,targetSum) || pathSum(root->right,targetSum);
}