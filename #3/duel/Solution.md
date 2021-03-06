﻿#### solution决斗

##### subtask1（10%） 

n,m≤5。
爆搜。没什么好说的，想怎么暴力就怎么暴力。

##### subtask2（10%）

n,m≤300
理解题意后不难发现，求最优决策等价于求最大生成树。直接构完全图，然后跑最大生成树。对于每次修改操作重新跑一遍最大生成树。
时间复杂度O(n³）。

##### subtask3（10%）

n≤1000，m≤100000
用Kruskal求出最大生成树，每次修改操作因为是or，显然只会比原数大，所以等价于加了一条新的边。此时原来的生成树上出现了一个环，需要删掉一条环上的边，当然是删最小的边。这个环由原来生成树上的一条链和新的一条边组成，原来生成树上的链上最小值是不用修改的，倍增维护即可。
时间复杂度$O(n^2 \log n+m \log n)$

##### subtask4（10%）

n≤3300，m≤0
反正是完全图，直接用prime求最大生成树显然更好。
时间复杂度O(n²)

##### subtask5（10%）

n≤3300，m≤300000
这就是前两个subtask合在一起，不重复了。
时间复杂度$O(n^2+m \log n)$



##### subtask6（20%）

原图非常特殊，每条边权都是两个点权的异或值。

考虑Boruvka算法

一开始每一个点都是一个独立的连通块

每一轮开始时对每一个连通块找一条边权最大的连向其他连通块的边

然后对每个连通块，如果选出的那条边连向的连通块还没有连通，就选那条边，把两个连通块连起来，否则就跳过。

重复上述过程，直到只剩一个连通块。

不难发现，每一轮连通块个数都至少少一半，所以$O(\log n)$轮就可以结束。

求最大生成树的总复杂度$O(n^2 \log n)$

~~还不如prime呢~~

考虑对每个连通块找那条边权最大的连向其他连通块的边的过程，即要对每个点找一条边权最大的连向其他连通块的边。可以借助trie树完成这一过程。trie树上每一个节点顺带维护子树内最大的连通块编号和最小的连通块编号，每一轮重构trie树，这样就能在$O(\log a)$的时间内对一个点求出那条要找的边。

总复杂度$O(n\log a \log n +m \log n)$