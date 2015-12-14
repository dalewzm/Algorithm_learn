
//Solution 1
class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        
        if(*p == '\0') return *s == '\0';
        if(*(p+1)!='*'){
           
            if((*p=='.'&& *s!='\0') || *s==*p)
                return isMatch(s+1, p+1);
            if(*p == '*')
                return isMatch(s, p+1);
            return false;
        }
        else{
            while(*s == *p || (*p=='.' && *s!='\0') )
            {
                if(isMatch(s,p+2))
                    return true;
                s++;
            }
            return isMatch(s,p+2);
        }
    }
    
};

//solution 2
#include<iostream>
#include<vector>
#include <string>
#include <cassert>
using namespace std;


class Edge {
public:
	Edge(char c, int num) { edgeChar = c, stateNum = num; }
	char edgeChar;
	int stateNum;
};

class State {
public:
	State(int n) { num = n; }
	void addEdge(char edgechar, int tar)
	{
		edgeCollection.push_back(Edge(edgechar, tar));
	}
	int num;
	vector<Edge> edgeCollection;
};

class StateMachine {
public:
	void build(string source)
	{

		int cnt = 0;
		State cur(cnt);
		states.push_back(cur);
		char last = 0;
		for (int i = 0; i < source.size(); ++i) {

			if (i + 1 < source.size() && source[i + 1] == '*')
			{
				if( states[cnt].edgeCollection.size()>0){
					if (states[cnt].edgeCollection[0].edgeChar == source[i])
					{
						i++;
						continue;
					}
				}
				states[cnt].addEdge(' ', cnt+1);
				states.push_back(State(++cnt));
				states[cnt].addEdge(source[i], cnt);
				i++;
				continue;
			}
			else if (source[i] == '.')
			{
				states[cnt].addEdge('.', cnt + 1);//
				states.push_back(State(++cnt));

				last = '.';
			}
			else {
				last = source[i];
				states[cnt].addEdge(last, cnt + 1);//
				states.push_back(State(++cnt));

			}
		}
		int j = 0;
		for (int i = 0; i < states.size(); i = j+1)
		{
			vector<int> ans;
			ans.push_back(i);
			bool find = true;
			j = i;
		    while ((states[j].edgeCollection.size() > 0 && states[j].edgeCollection[0].edgeChar == 32)
				|| (states[j].edgeCollection.size() > 1 && states[j].edgeCollection[1].edgeChar == 32))
			{
				if (states[j].edgeCollection.size() > 0 && states[j].edgeCollection[0].edgeChar == 32){
					ans.push_back(states[j].edgeCollection[0].stateNum);
					j = states[j].edgeCollection[0].stateNum;
				}
				else{
					ans.push_back(states[j].edgeCollection[1].stateNum);
					j = states[j].edgeCollection[1].stateNum;
				}
				
			}
			acStates = ans;
		}
	}

	bool match(string s)
	{
		vector<State> NFA;
		NFA.push_back(states[0]);
		bool find = false;
		//int *visit = new int[states.size()];
		for (int i = 0; i < s.size(); ++i)
		{
			//
			find = false;
			vector<State> tmp;
			//memset(visit, 0, sizeof(int)*states.size());
#pragma  region change state
			while (!NFA.empty())
			{
				State topele = NFA.back();
				NFA.pop_back();
				for (int j = 0; j < topele.edgeCollection.size(); ++j){
					if (topele.edgeCollection[j].edgeChar == ' '){
							NFA.push_back(states[topele.edgeCollection[j].stateNum]);
					}
				}
				for (int j = 0; j < topele.edgeCollection.size(); ++j)
				{
					if (s[i] == topele.edgeCollection[j].edgeChar ||
						topele.edgeCollection[j].edgeChar == '.') {
						tmp.push_back( states[topele.edgeCollection[j].stateNum] );
						find = true;
					}
				}
				
			}
#pragma  endregion 
			if (!find)
				return false;
			NFA = tmp;
		}
		for (int i = 0; i < NFA.size(); ++i)
		{
			for (int j = 0; j < acStates.size(); ++j)
			if (NFA[i].num == acStates[j])
				return true;
		}
		return false;
	}
private:
	vector<State> states;
	vector<int> acStates;
};

class Solution {
public:
	bool isMatch(string s, string p) {
		StateMachine machine;
		char *str = new char[p.size()];
		int cnt = 0;
		bool findAlpha = false;
		
		for (int i = 0; i < p.size(); ++i)
		{
			if (!findAlpha && p[i] == '*')
				continue;
			if (p[i] != '*') {
				str[cnt++] = p[i];
				findAlpha = true;
			}
			else { //p[i] == '*' && find = true
				if (i < p.size() - 1)
				{
					if (p[i + 1] == '*')
						continue;
				}
				str[cnt++] = '*';
			}
		}
		str[cnt] = '\0';
		string np(str);
		machine.build(np);
		return machine.match(s);
	}
};
