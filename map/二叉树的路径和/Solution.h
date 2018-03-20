#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>>b;
    vector<int>a;
    
	vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) 
    {
        // Write your code here
        if(root!=NULL)
        {
           int sum=0;
           searchleft(root,target,sum);                
        }    
        return  b;
         
    }
    
     void  searchleft(TreeNode *root,int &target, int & sum)
     {
		 if (root)
		 {
			 sum=sum+root->val;
			 a.push_back(root->val);
		 }
		
         if(root->left==NULL&&root->right==NULL&&sum==target)
         { 	 
			 b.push_back(a);    
         }
		 if(root->left!=NULL)
		 {
            searchleft(root->left,target,sum);
		 }
		 if(root->right!=NULL)
		 {
		    searchleft(root->right,target,sum); 
		 }
		 a.pop_back();
		 sum=sum-root->val;
     }
      
};