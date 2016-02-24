#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool cmp(const string &a, const string &b)
{
    return a+b<b+a;
}

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    string strs[8];
    while(t--){
        cin>>n;
        for(int i=0; i<n; ++i)
            cin>>strs[i];
        sort(strs,strs+n,cmp);
        for(int i=0; i<n; ++i)
            cout<<strs[i];
        cout<<endl;
    }
}
