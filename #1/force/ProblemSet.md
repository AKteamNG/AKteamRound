### 题目背景

“写呀写呀写暴力，我们一起写暴力”。

这是~~（据说）~~是一首来自**SYXX**的学生都会唱的歌。

### (真)题目描述

AKteam的成员有n个人，所有成员按顺序排队，每个人手上都拿着一个数字。

有一天，老师想来查询一下某一段的“AK-val”。"AK-val"的定义是某一段的[最大子段和](https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=0&rsv_idx=1&tn=baidu&wd=%E6%9C%80%E5%A4%A7%E5%AD%90%E6%AE%B5%E5%92%8C&rsv_pq=ea3fcefe0005a35b&rsv_t=37a3lAxKOPF5CoyRy9KBLEAruGgzwa%2BIetKrVM2CEiiarrjm%2BBw9etgVzjE&rqlang=cn&rsv_enter=1&rsv_sug3=9&rsv_sug1=9&rsv_sug7=100)。

老师还想给所有同学的手上的数字+val

由于老师的任务太过繁重了~~(AKteam有太多成员)~~，因此老师希望你来帮助他完成这个任务。

### 输入格式

第一行有一个数n

接下来一行n个数，第i个数字表示第i个成员手上的数字。

接下来一个数m,表示操作次数。

接下来m行，每行表示一个操作：

Q l r：询问[l,r]区间内成员的"AK-val"值

A val ： 给所有成员手上的值加上val

### 输出格式

对于每个询问，输出"AK-val"的值。

### 样例

#### Sample-Input
```plain
5
2 3 -7 5 6
3
Q 1 5
A 3
Q 2 3
```
#### Sample-Output对于 100% 的数据， 保证有 $1 \leq l \leq r \leq n$ 和 $1 \leq |a_i|,val \leq 10^6$
对于 50% 的数据 $1 \leq n,m \leq 2000$

对于 100% 的数据 $1 \leq n,m \leq 50000$

**注**：子段长度可为0，即最大子段和的最小值为0

~~请参考题目名称~~

```plain 
11
6
```

### 数据范围与提示

对于 100% 的数据， 保证有 $1 \leq l \leq r \leq n$ 和 $1 \leq |a_i|,val \leq 10^6$

对于 50% 的数据 $1 \leq n,m \leq 2000$

对于 100% 的数据 $1 \leq n,m \leq 50000$

**注**：子段长度可为0，即最大子段和的最小值为0

~~请参考题目名称~~