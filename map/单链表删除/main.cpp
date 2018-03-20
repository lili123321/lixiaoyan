#include <iostream>
#include "delete.h"
int main()
{
	/*删除链表中等于给定值val的所有节点。
	给出链表 1->2->3->3->4->5->3, 和 val = 3, 你需要返回删除3之后的链表：1->2->4->5。*/
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