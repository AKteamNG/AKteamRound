## 简单题
 
### 题目描述
 
给你一棵大小为n的树，根是1，现在有q个询问，每次给你k个点，求这k个点到其公共lca的距离之和。（k个点可能部分相同）
    
### 输入格式

第一行输入n，q


第二行给你一个生成种子x,c


数据生成方式。

```cpp
for (int i=2;i<=n;i++) fa[i]=(1ll*x*x+c)%(i-1)+1;
```

后面q行给你生成种子x,c和k
x=x^lastans,c=c^lastans;

数据生成方式。

```cpp
for (int i=1;i<=k;i++) x=(1ll*x*x+c)%(n-2)+2,a[i]=x;
```
每次对lastans取模，模数1e9+7

### 输出格式

输出最后的lastans

### 样例

#### 输入数据：

```plain
4 7
1 1
4 1 3
4 2 2
1 1 3
1 1 3
1 1 3
3 3 3
1 1 2
```

#### 输出数据：

```plain
2
```

#### 数据范围与提示

10%的数据范围 3≤n,q≤1e23\leq n,q \leq 1e23≤n,q≤1e2,∑\displaystyle\sum∑ k≤1e3k\leq 1e3k≤1e3

30%的数据范围 3≤n,q≤1e5 3\leq n,q\leq 1e53≤n,q≤1e5,∑\displaystyle\sum∑ k≤1e6k\leq 1e6k≤1e6

100%的数据范围3≤n≤3e63\leq n\leq3e63≤n≤3e6,1≤q≤3e61\leq q \leq3e61≤q≤3e6,∑\displaystyle\sum∑ k≤3e6k\leq 3e6k≤3e6

本题采用subtask
 
