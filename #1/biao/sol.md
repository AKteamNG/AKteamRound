### 骗分过样例

#### 算法一

暴力枚举最后的a，然后算答案。

时间复杂度： $\Omicron(n! * n)$， 期望得分：30pts

#### 算法二

状压DP，由于当前前缀和只和当前所使用过的数有关，所以没有后效性。

时间复杂度： $\Omicron(2^n *n)$，期望得分：60pts

#### 算法三

这显然是[NP问题](https://baike.baidu.com/item/NP%E9%97%AE%E9%A2%98/2860567)。因此，要让随机算法出场了。

直接随机100000个序列。实际得分：40pts

使用[爬山算法](https://baike.baidu.com/item/%E7%88%AC%E5%B1%B1%E7%AE%97%E6%B3%95/3252408?fr=aladdin)，每次从较优解转移。实际得分：100pts？

使用[模拟退火](https://baike.baidu.com/item/%E6%A8%A1%E6%8B%9F%E9%80%80%E7%81%AB/8664695?fr=aladdin)，每次以一定概率从较优解转移。实际得分：100pts。好吧，这是std。

使用[遗传算法](https://baike.baidu.com/item/%E9%81%97%E4%BC%A0%E7%AE%97%E6%B3%95/838140?fr=aladdin)？

