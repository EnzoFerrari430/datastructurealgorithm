﻿#include <Windows.h>

/*
树的附加说明
内结点：该结点存在孩子，则该结点成为内结点。叶子结点不是内结点
叶子结点：真正的叶子结点是指向null的结点，这些指向null的结点才是真正的叶子结点，也称外部结点


红黑树是具有下列着色性质的二叉查找树:
1.每一个结点或者着成红色，或者着成黑色
2.根是黑色的
3.如果一个结点是红色的，那么它的子结点必须是黑色的
4.从一个结点到一个NULL指针的每一条路径必须包含相同数目的黑色结点
5.每个叶子结点(NULL)是黑色(附加性质，这里的叶子结点是指为空(NULL)的叶子结点)


红黑树的定理：
1.一棵含有n个结点的红黑树的高度至少为2log(n+1)  (有待证明)



红黑树的基本操作

用于完成冲突情况的基本操作是颜色的改变和树的旋转

1.插入：
和通常一样，困难在于将一个新项，插入到树中。通常会把新项作为树叶放到树中。
如果我们把该项涂成黑色，那么我们肯定违反了性质4，因为这样会产生一条更长的黑结点的路径。所以这新的一项必须涂成红色
如果这新项的父结点是黑色的，则我们的插入完成，如果它的父结点是红色的，那么我们会得到连续的红色结点，这样违反了性质3
在这种情况下，我们必须调整该树以确保条件3满足(且不引起条件4被破坏)

1.1
	如果父结点是黑色的，那么将该结点插入到父结点下，然后将该结点涂成红色

1.2
	如果父结点是红色
	1.2.1
	如果父结点的兄弟结点是黑色的，对该新结点、父结点、祖父结点按照伸展树的方式进行旋转
	旋转的方式有"一"字形和"之"字形。然后再对颜色作出相应的调整，使其遵循红黑树的性质
	在编写程序的时候，我们必须记录父结点、祖父结点和曾祖父结点，其中曾祖父结点用来重新进行连接
	旋转后子树的新根被涂成黑色，因此即使原来曾祖父是红的，我们也排除了两个相邻红结点的可能性

	1.2.2




2.删除：

*/