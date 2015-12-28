#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 200002
int a[maxn];
int b[maxn];
int c[maxn<<1];


int main()
{
    int n,m;
    cin>>n;
    a[0] = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int ah,bh,suma,sumb,ma,mb;
    int *index = NULL;
    int res = -3*(n+m);
    int i=0,j=0;
    ma = 0;
    mb = 0;
    while(i<n || j<m){
        if(a[i]<b[j])
        {
            //a[i] is 2,>a[i] is 3
            while(a[i+1]==a[i] && i<n)
                i++;
            if(i<n)
                i++;
            else
                ++j;
            suma = 2*i+3*(n-i);
            sumb = 2*j+3*(m-j);
            if(suma - sumb > res || (suma-sumb==res && suma > ma))
            {
                res = suma -sumb;
                ma = suma;
                mb = sumb;
            }
            
        }
        else if(a[i]>b[j]){//a[i]>=b[j]
            while(b[j+1] == b[j] && j<m)
                j++;
            if(j<m)
                ++j;
            else
                ++i;
            suma = 2*i +3*(n-i);
            sumb = 2*j +3*(m-j);
            if(suma - sumb > res || (suma-sumb==res && suma > ma))
            {
                res = suma -sumb;
                ma = suma;
                mb = sumb;
            }
        }
        else{
            while(b[j+1] == b[j])
                j++;
            while(a[i+1]==a[i])
                i++;
            if(i<n)
            i++;
            if(j<m)
            j++;
            suma = 2*i+3*(n-i);
            sumb = 2*j+3*(m-j);
            if(suma - sumb > res|| (suma-sumb==res && suma > ma))
            {
                res = suma -sumb;
                ma = suma;
                mb = sumb;
            }

        }
    }
    if(3*(n-m)>=res)
    {
        res = 3*(n-m);
        ma = 3*n;
        mb = 3*m;
    }
    cout<<ma<<":"<<mb<<endl;
    return 0;
    for(int i=0; i<=n; ++i)
    {
        //a[i] is 2,>a[i] is 3
        ah = i;
        for(int j=i+i; j<n; ++j){
            if(a[j] == a[i])
                ah = j;
            else
                break;
        }
        suma = (ah)*2 + (n-ah)*3;
        index = upper_bound(b,b+m,a[i]);
        int diff = index-b;
        sumb = diff*2 + (m-diff)*3;
        if(suma -sumb> res){
            res = suma - sumb;
            ma = suma;
            mb = sumb;
        }
        
    }
    cout<<ma<<":"<<mb<<endl;
}
