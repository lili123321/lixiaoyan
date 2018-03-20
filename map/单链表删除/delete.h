
 struct ListNode 
 {
    int val;
    ListNode *next;
   // ListNode() : val(x), next(NULL) {}
};
 
class Solution {
public:
    /*
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val)
    {
		
			ListNode *cur;
			ListNode *pre;
			if(head!=NULL)
			{
				pre=head;
				cur=head->next;

				while(cur) 
				{
					if(cur->val==val)
					{
						if(cur->next)
						{
							pre->next=cur->next;
							cur= pre->next;
						}
						else
						{
							pre->next=NULL; 
							cur=NULL;
						}
					}
					else
					{
						if(cur->next)
						{
							pre=cur;
							cur=cur->next;
						}
						else
						{
							pre=cur;
							cur=NULL;
						}
					}
				} 

				if(head->val==val)
				{
					return  head->next;
				}
				else
					return head;
			}      

			else
				return NULL;


	         

	}    
  
};