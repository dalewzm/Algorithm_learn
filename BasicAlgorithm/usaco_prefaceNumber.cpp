/*
 ID: dalewzm1
 PROG: preface
 LANG: C++
 */


#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<memory.h>
#include <cmath>
#include <cassert>
using namespace std;

ofstream fou("preface.out");
ifstream fin("preface.in");


char value[7];
int n;

//#define fou cout
//#define fin cin


int digits[4];
void getEveryDidit(int num)
{
    
    for(int i=0; i<4; ++i)
    {
        digits[i] = num % 10;
        num/=10;
    }
}

int sum[7];
char roman[7] ={'I','V','X','L','C','D','M'};
int romanValue[3][3] = {{0,1,2},{2,3,4},{4,5,6}};
void changeDigitToRoman(int num)
{
    for(int i=0; i<3; ++i){
        if(digits[i]!=0)
        {
            if(digits[i]<=3)
            {
                sum[romanValue[i][0]]+=digits[i];
            }
            else if(digits[i] == 4)
            {
                sum[romanValue[i][0]]++;
                sum[romanValue[i][1]]++;
            }
            else if(digits[i] == 5)
            {
                 sum[romanValue[i][1]]++;
            }
            else if(digits[i]<=8)
            {
                sum[romanValue[i][1]]++;
                sum[romanValue[i][0]]+= (digits[i]-5);
            }
            else{
                sum[romanValue[i][0]]++;
                sum[romanValue[i][2]]++;
            }
            
        }
    }
    if(digits[3]!=0)
    {
        sum[romanValue[2][2]]+= digits[3];
    }
}

void init()
{
    fin>>n;
    
}

void solve()
{
    for(int i=1; i<=n; ++i)
    {
        getEveryDidit(i);
        changeDigitToRoman(i);
    }
    for(int i=0; i<7; ++i)
    {
        if(sum[i])
        {
            fou<<roman[i]<<" "<<sum[i]<<endl;
        }
    }
}

int main()
{
    init();
    solve();

    return 0;
}

