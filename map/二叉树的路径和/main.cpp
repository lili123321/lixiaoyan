#include "TreeNode.h"
#include "Solution.h"

int main()
{
	/*给定一个二叉树，找出所有路径中各节点相加总和等于给定 目标值 的路径。
	一个有效的路径，指的是从根节点到叶节点的路径。*/
	Solution  tt;
	///*TreeNode  a(1);
	//TreeNode  b(1);
	//TreeNode  c(1);
	//TreeNode  d(1);
	//TreeNode  e(1);
	//TreeNode  f(1);
	//TreeNode  g(1);
	//TreeNode  h(1);
	//TreeNode  i(1);
	//TreeNode  j(1);
	//TreeNode  k(1);
	//TreeNode  l(1);
	//TreeNode  m(1);
	//TreeNode  n(1);
	//TreeNode  o(1);
	//TreeNode  p(1);
	//TreeNode  q(1);
	//TreeNode  r(1);
	//TreeNode  s(1);
	//TreeNode  t(1);
	//TreeNode  u(1);
	//TreeNode  v(1);
	//TreeNode  w(1);
	//TreeNode  x(1);
	//TreeNode  y(1);
	//TreeNode  z(1);
	//TreeNode  a1(1);
	//TreeNode  a2(1);
	//TreeNode  a3(1);
	//TreeNode  a4(1);
	//TreeNode  a5(1);
	//TreeNode  a6(1);
	//TreeNode  a7(1);
	//TreeNode  a8(1);
	//TreeNode  a9(1);
	//TreeNode  a10(1);
	//TreeNode  a11(1);
	//TreeNode  a12(1);
	//TreeNode  a13(1);
	//TreeNode  a14(1);
	//TreeNode  a15(1);
	//TreeNode  a16(1);
	//TreeNode  a17(1);
	//TreeNode  a18(1);
	//TreeNode  a19(1);
	//TreeNode  a20(1);

	//a.assign(&b,&c);
	//b.assign(&d,&e);
	//c.assign(&f,&g);
	//d.assign(&h,&i);
	//e.assign(&j,&k);
	//f.assign(&l,&m);
	//g.assign(&n,&o);
	//h.assign(&p,&q);
	//i.assign(&r,&s);
	//j.assign(&t,&u);
	//k.assign(&v,&w);
	//l.assign(&x,&y);
	//m.assign(&z,&a1);
	//n.assign(&a2,&a3);
	//o.assign(&a4,&a5);
	//p.assign(&a6,&a7);
	//q.assign(&a8,&a9);
	//r.assign(&a10,&a11);
	//s.assign(&a12,&a13);
	//t.assign(&a14,&a15);
	//u.assign(&a16,&a17);
	//v.assign(&a18,&a19);
	//w.assign(&a20,NULL);*/

	TreeNode  a(1);
	TreeNode  b(2);
	TreeNode  c(4);
	TreeNode  d(2);
	TreeNode  e(3);
	a.assign(&b,&c);
	b.assign(&d,&e);


	tt.binaryTreePathSum(&a,5);
}