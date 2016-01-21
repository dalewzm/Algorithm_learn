//-----------------------------------
//use a integet represent a set，very important method
//------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <memory.h>
#include <map>
#include <stack>
#include <set>
//#include <unordered_map>
using namespace std;
int eleNum;

typedef set<int> Set;
map<Set, int> setm;
stack<int> setStack;
vector<Set> setCache;
void init()
{
    eleNum = 0;
    setm.clear();
    while(!setStack.empty())
        setStack.pop();
    setCache.clear();
}


int getSetId(Set &vec)
{
    if(setm.find(vec)==setm.end())
    {
        int old = eleNum;
        setm[vec] = eleNum;
        setCache.push_back(vec);
        eleNum++;
        return old;
    }
    return setm[vec];
    
}


void solve()
{
    int ncmd;
    cin>>ncmd;
    string cmd;
    int id;
    for(int k=0; k<ncmd; ++k){
        cin>>cmd;
        if(cmd[0]=='P'){
            Set emptyv;
            id = getSetId(emptyv);
            setStack.push(id);
            cout<<setCache[id].size()<<endl;//
        }
        else if(cmd[0]=='D'){
            setStack.push(setStack.top());
            cout<<setCache[setStack.top()].size()<<endl;
        }
        else if(cmd[0]=='U'){
            int t1 = setStack.top();
            setStack.pop();
            int t2 = setStack.top();
            setStack.pop();
            Set s1 = setCache[t1];
            Set s2 = setCache[t2];
            for(Set::iterator it=s1.begin(); it!=s1.end(); it++){
                s2.insert(*it);
            }
            t2 = getSetId(s2);
            setStack.push(t2);
            cout<<setCache[t2].size()<<endl;
        }
        else if(cmd[0] == 'I'){
            int t1 = setStack.top();
            setStack.pop();
            int t2 = setStack.top();
            setStack.pop();
            Set s1 = setCache[t1];
            Set s2 = setCache[t2];
            Set inter;
             for(Set::iterator it=s1.begin(); it!=s1.end(); it++){
                 if(s2.find(*it)!=s2.end()){
                     inter.insert(*it);
                 }
             }
            t2 = getSetId(inter);
            setStack.push(t2);
            cout<<setCache[t2].size()<<endl;
        }
        else{//add
            int t1 = setStack.top();
            setStack.pop();
            int t2 = setStack.top();
            setStack.pop();
            Set s1 = setCache[t1];
            Set s2 = setCache[t2];
            s2.insert(t1);
            t2 = getSetId(s2);
            setStack.push(t2);
            cout<<setCache[t2].size()<<endl;
        }
    }
    cout<<"***"<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        init();
        solve();
    }

    return 0;
}
