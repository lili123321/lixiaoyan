#include <iostream>
#include "delete.h"
int main()
{
	/*ɾ�������е��ڸ���ֵval�����нڵ㡣
	�������� 1->2->3->3->4->5->3, �� val = 3, ����Ҫ����ɾ��3֮�������1->2->4->5��*/
	Solution  s;
	struct ListNode a,b,c,d,e,f,g,*head;
	a.val=1;
	b.val=2;
	c.val=3;
	d.val=3;
	e.val=4;
	f.val=5;
	g.val=6;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=&e;
	e.next=&f;
	f.next=&g;
	g.next=NULL;

	s.removeElements(head,3);
}