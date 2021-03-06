//母函数基本
//整数划分
//(1+x+x^2+x^3+x^4...)(1+x^2+x^4+x^6+...)(1+x^3+x^6+...)(....)=x^100
//实际上是求这个表达式的系数
//
const int maxn = 1000;
int c1[maxn]; //c1 储存结果，c1[i]代表整数i的划分方案
int c2[maxn];
for(int i=0; i<=n; ++i) //代表初始化第一个括号内容
{
  c1[i] = 1;
  c2[i] = 0;
}

for(int i=2; i<=n; ++i)//计算第2个括号到i个括号
{
	for(int j=0; j<=n; ++j){ //j代表前i-1个表达式乘积第j项
		for(int k=0; j+k<=n; k+=i) //和第i个表达式的每一项相乘(k每次增加i)，
			c2[j+k] =c2[j+k] + c1[k];
	}
	
	for(int j=0; j<=n; ++j)
	{
		c1[j] = c2[j];
		c2[j] = 0;
	}
	
}

cout<<c1[n]<<endl;
