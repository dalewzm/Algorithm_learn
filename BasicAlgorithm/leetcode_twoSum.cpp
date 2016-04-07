//time complexity is O(nlogn)
//space complexity is O(n)
//sort+二分
#include<algorithm>
using namespace std;

typedef struct value{
	int number;
	int pos;
}value;

bool cmp(const value &lf,const value &rh)
{
	return (lf.number<rh.number);
}
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		value *tmp=new value[numbers.size()];
		int i,j;
		for(i=0; i<numbers.size(); ++i){
			tmp[i].number=numbers[i];
			tmp[i].pos=i+1;
		}
		sort(tmp,tmp+numbers.size(),cmp);
		//for(i=0; i<numbers.size(); ++i) cout<<tmp[i].number<<" ";
		int len=numbers.size();
		vector<int> ans;
		int low,high,mid,newtar;
		for(i=0; i<len && tmp[i].number<=target; ++i){
			low=i+1,high=len-1;
			newtar=target-tmp[i].number;
			while(low<high-1){
					
				mid=low+((high-low)>>1);
					//cout<<"Hello"<<low<<" "<<mid<<" "<<high<<endl;
				if(tmp[mid].number<=newtar)
					low=mid;
				else
					high=mid;
			}
		
			if(tmp[high].number==newtar)
			{
				if(tmp[i].pos<tmp[high].pos){
					ans.push_back(tmp[i].pos);
					ans.push_back(tmp[high].pos);
				}
				else{
					ans.push_back(tmp[high].pos);
					ans.push_back(tmp[i].pos);
				}
				break;
			}else if(tmp[low].number==newtar){
				
				if(tmp[i].pos<tmp[low].pos){
					ans.push_back(tmp[i].pos);
					ans.push_back(tmp[low].pos);
				}
				else{
					ans.push_back(tmp[low].pos);
					ans.push_back(tmp[i].pos);
				}
				break;
			}
			else{
			  ;
			}

		}
		return ans;
	}
};
