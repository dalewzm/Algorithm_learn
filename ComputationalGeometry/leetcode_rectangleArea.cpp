//首先将两个矩形按照左下角顶点
//使得我们计算两个矩形相交面积时一定是第二个矩形在右边
//第二个矩形在右边，那么判断第二个矩形左下角顶点，如果左下角顶点不比第在第一个矩形右上角顶点的左下方的话(有点绕)
//肯定没有相交
//即使在左下方，那么第二个矩形的右上角顶点必须在第一个矩形左下角顶点的右上方(已经肯定在右边，只要判断是不是上方)，否则也还没有相交
//如果有相交
//相交矩形的左下角，是两者左下角的最大值
//相交矩形的右上角，是两者右上角顶点的最小值
typedef struct CPoint{
	CPoint(int a = 0, int b = 0) :x(a), y(b){}
	int x;
	int y;
	bool operator < (const CPoint& rhs) const
	{
		if (x != rhs.x)
			return x < rhs.x;
		return y < rhs.y;
	}
}CPoint;
class Solution {
public:
	int compute(CPoint lb1, CPoint rt1, CPoint lb2, CPoint rt2)
	{
		//whether intersect
		// letftBottom 
		if (lb2.x >= rt1.x || lb2.y >= rt1.y)
			return 0;
		if (rt2.y < lb1.y)
		{
			return 0;
		}
		CPoint interLb, interRt;
		interLb.x = lb2.x;
		interLb.y = max(lb1.y, lb2.y);
		interRt.x = min(rt1.x, rt2.x);
		interRt.y = min(rt1.y, rt2.y);
		return (interRt.x - interLb.x)* (interRt.y - interLb.y);
		
	}
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		CPoint lb1(A, B), rt1(C, D);
		CPoint lb2(E, F), rt2(G, H);
		int common = 0;
		if (lb1 < lb2)
		{
			common= compute(lb1, rt1, lb2, rt2);
		}
		else
			common = compute(lb2, rt2, lb1, rt1);
		return (C - A)*(D - B) + (G - E)*(H - F) - common;
	}
};
