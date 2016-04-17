//由样例可以推出大致的计算过程
//     __ 
//  __|  |   __
// |  |  |   | |
//  1  2   0  1
//实际上是维护左右边界,单调栈中维护从高到低的左边界,一旦当前遍历的元素
//比栈顶高时,就有可能发生积水(有积水至少有3列,如果只有两列就没有积水),
//计算与栈顶发生的积水面积,然后弹出栈顶
typedef struct AreaNode{
	AreaNode(int h, int p, int w) :height(h), pos(p), width(w){}
	int height;
	int pos;
	int width;
}AreaNode;
class Solution {
public:
	int trap(vector<int>& height) {
		stack<AreaNode> monoStack;
		int sum = 0;

		for (int i = 0; i < height.size(); ++i)
		{
			if (monoStack.empty())
			{
				monoStack.push(AreaNode(height[i],i,1));
			}
			else{
				if (monoStack.top().height > height[i])
				{
					monoStack.push(AreaNode(height[i], i, 1));
				}
				else if (monoStack.top().height == height[i])
				{
					;
				}
				else{ //栈顶小于右边的值,有可能积水了
					int cnt = 0;
					while (monoStack.top().height < height[i])
					{
						AreaNode curNode = monoStack.top();
						monoStack.pop();
						if (!monoStack.empty()){//有积水
							if (monoStack.top().height >= height[i])//pop结束
							{
								int h = height[i] - curNode.height;
								int w = i - curNode.pos ;
								sum += h*w;
								monoStack.push(AreaNode(height[i], curNode.pos, i-curNode.pos+1));
								break;
							}
							else{  //还要继续pop
								int h = monoStack.top().height - curNode.height;
								int w = i - curNode.pos;
								sum += h*w;
								monoStack.top().width = curNode.pos - monoStack.top().pos - 1;
							}
						}
						else{ //无积水
							monoStack.push(AreaNode(height[i], i, 1));
							break;
						}
					}
				}
			}
		
		
		}	
		
		return sum;
	}
	
};
