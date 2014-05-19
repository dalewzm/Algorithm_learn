My algorithm exercise
========

My submission for some problems of some OJ

[wikioi oi训练](http://www.wikioi.com/training/ )

[leetCode 求职，基础+算法](http://oj.leetcode.com/problems/)

### Wikioi
#####  骑士周游[1219](http://www.wikioi.com/problem/1219/)
	棋盘型dp，状态转移方程
    dp[i][j]=dp[i-2][j-1]+dp[i-2][j+1]+dp[i-1][j-2]+dp[i-1][j+2]
    另外根据n,m的范围，int范围不够，我使用了自己写的高精度，可以ull	

### LetCode
##### Merge Sorted Array
    有使用中间数组和不使用两种方法，前者AC，后者超时


##### Reverse Integer
     简单，练手感

##### Two Sum (编程之美)
	给定一个数组和一个数T，找出数组中的两个数，它们的和是T
	返回的是两个数的下标，从1开始
    　 先排序，然后依次遍历数组，比如遍历到a，从剩下的数组中二分查找(T-a),不先判相等的二分查找有点坑....

##### ADD Two Num
     拿一个指针记录链表尾就可以了，每次在末尾加元素
 

	
	
