#define NULL 0
class TreeNode 
{
 public:
	     int val;
	     TreeNode *left, *right;
	     TreeNode(int val) 
		 {
		    this->val = val;
			this->left = NULL;
			this->right= NULL;
		        
		  }

		 void   assign(TreeNode *left,TreeNode *right) 
		 {
			 this->left = left;
			 this->right= right;
		 }
 };