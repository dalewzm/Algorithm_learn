//单调栈
//思想：如果某一列值比较低，后面计算矩形，如果要计算以此矩形及之前的连续矩形，高度就是这个最小值
typedef struct Ele{
	Ele(int a,int b):h(a),p(b){}
	int h;
	int p;
}Ele;

class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			int n = heights.size();
			if (n == 0)
				return 0;
			int maxArea = 0;
			stack<Ele> monoStack;
			Ele tmp(heights[0],0);

			for (int i = 0; i < n; ++i){
				if (monoStack.empty())
				{
					monoStack.push(Ele(heights[i], i));
				}
				else{
					if (monoStack.top().h <= heights[i])
					{
						monoStack.push(Ele(heights[i], i));
					}
					else if (monoStack.top().h > heights[i])
					{
						int end = i;
						int begin = 0;
						while (!monoStack.empty() && monoStack.top().h > heights[i])
						{
							tmp = monoStack.top();
							monoStack.pop();
							begin = tmp.p;
							if ((end - tmp.p ) * tmp.h > maxArea)
								maxArea = (end - tmp.p ) * tmp.h;
						}
						
						monoStack.push(Ele(heights[i], begin));
						
					}
				}
			}
		   int 	end = n;
			if (!monoStack.empty()){
			
				while (!monoStack.empty())
				{
					tmp = monoStack.top();
					monoStack.pop();
					if ((end - tmp.p ) * tmp.h > maxArea)
						maxArea = (end - tmp.p) * tmp.h;
				}
			}
			return maxArea;
		}
};
