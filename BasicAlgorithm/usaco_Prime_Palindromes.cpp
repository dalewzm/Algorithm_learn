/*
ID: dalewzm1
PROG: pprime
LANG: C++
*/


#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<memory.h>
#include <cmath>
using namespace std;


ofstream fou("pprime.out");
ifstream fin("pprime.in");





int digit[10];
int weight[10];
int cnt = 0;
int first = 0;
int low,upp;

//#define fou cout
//#define fin cin

inline int lenN(int n)
{
    cnt = 0;
    while(n){
        n/=10;
        cnt++;
    }
    return cnt;
}


bool isPrime(int num)
{
    int limit = ceil(sqrt(num));
    for(int i=3; i<=limit; i+=2)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

void dfs(int k)
{
    if(cnt & 1)
    {
        if(k>cnt/2)
        {
            int sum = 0;
            if(cnt == 1){
                sum = digit[0];
                
            }
            else{
                for(int i=0; i<cnt/2; ++i)
                    sum+= digit[i]*weight[i] + digit[cnt-i-1]*weight[cnt-i-1];
                sum+= digit[cnt/2]*weight[cnt/2];
            }
            if(sum<low || sum > upp)
                return;
            if(isPrime(sum))
                fou<<sum<<endl;
                return;
            
        }
    }
    else
    {
        if(k>=cnt/2)
        {
            int sum = 0;
            for(int i=0; i<cnt/2; ++i)
                sum+= digit[i]*weight[i] + digit[cnt-i-1]*weight[cnt-i-1];
            if(sum<low || sum > upp)
                return;
            //printf(": %d\n",sum);
            if(isPrime(sum))
                fou<<sum<<endl;
            return;
        }
    }
    if(0==k)
    {
        for(int i=1; i<=9; i+=2){
            digit[k] =i;
            digit[cnt-k-1] = i;
            dfs(k+1);
        }
    }
    else{
        for(int i=0; i<=9; ++i)
        {
            digit[k] = i;
            digit[cnt-1-k] = i;
            dfs(k+1);
        }
    }
}

/*
void getPalid(int l)
{
    
    if(l & 1)
    {
        
    }
    else{
        for(int i=1; i<=9; i+=2)
        {
            digit[0] = i;
            for(int j=1; j<= l/2; j++)
            {
                for(int k=0; k<=9; ++k)
                    digit[j] = k;
            }
        }
    }
}
*/

void init()
{
    weight[0] =1;
    for(int i=1; i<=9; i++)
        weight[i] =weight[i-1]*10;
        
}

int main()
{
    
    int a,b;
    fin>>low>>upp;
    a = lenN(low);
    b = lenN(upp);
    init();
    for(int i=a; i<=b; ++i)
    {
        cnt = i;
        dfs(0);
    }
    return 0;
}




