leetCode
========

My submission for some problem of leetCode OJ

#### Merge Sorted Array
>  * 有使用中间数组和不使用两种方法，前者AC，后者超时

#### Two Sum
给定一个数组和一个数T，找出数组中的两个数，它们的和是T
返回的是两个数的下标，从1开始
> * 先排序，然后依次遍历数组，比如遍历到a，从剩下的数组中二分查找(T-a),不先判相等的二分查找有点坑....
