// Problem#: 1006
// Submission#: 4523968
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

#pragma warning(disable:4996)
using namespace std;

int n;
const int num = 120;
char ranks[num][6];
int d[num][5][5];
int tmpD[5][5];

int getDis(int l[][5], int r[][5])
{
    int ret = 0;
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            if (l[i][j] != r[i][j])
                ret++;
        }
    }
    return ret/2;
}


void getOrder(int d[][5], char str[])
{
    for (int j = 0; j < 5; ++j){
        for (int k = j + 1; k < 5; ++k){
            d[str[j] - 'A'][str[k] - 'A'] = 1;
        }
    }
}
void init()
{
    for (int i = 0; i < n; ++i)
        scanf("%s", ranks[i]);

    memset(d, 0, sizeof(d));
    memset(tmpD, 0, sizeof(tmpD));
    for (int i = 0; i < n; ++i){
        getOrder(d[i], ranks[i]);
        /*for (int j = 0; j < 5; ++j){
            for (int k = j + 1; k < 5; ++k){
                d[i][ranks[i][j] - 'A'][ranks[i][k] - 'A'] = 1;
            }
        }*/
    }
    
}


void sovle()
{
    char median[6];
    char res[6];
    strncpy(median, "ABCDE", 5);
    median[5] = 0;
    int dis = 12000;
    int sum = 0;
    do{
        memset(tmpD, 0, sizeof(tmpD));
        getOrder(tmpD, median);
        sum = 0;

        for (int i = 0; i < n; ++i){
            sum += getDis(tmpD, d[i]);
        }
        if (sum < dis)
        {
            dis = sum;
            strncpy(res, median, 6);
        }
    } while (next_permutation(median, median + 5));
    printf("%s is the median ranking with value %d.\n",res,dis);
}

int main()
{
   
    while (scanf("%d", &n) && n != 0){
        init();
        sovle();
    }
  
    return 0;
}                                 
