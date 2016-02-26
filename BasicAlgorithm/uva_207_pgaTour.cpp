#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
//#include <unordered_map>

//#define debug

using namespace std;
const int maxn = 144;
const int n_cut = 70;
typedef  struct player{
    char name[25];
    int s[4];
    int s36,s72,nsc;
    bool isPro;
    bool isDq;
}Player;

bool compare1(const Player&l,const Player&r)
{
    if(l.s36 < 0 && r.s36 < 0) return false; // equal
    if(l.s36 < 0) return false; // p2 smaller
    if(r.s36 < 0) return true; // p1 smaller
    return l.s36 < r.s36;
}

bool compare2(const Player&l,const Player&r)
{
    if(l.isDq &&  r.isDq){
        if(l.nsc != r.nsc) return r.nsc < l.nsc;
        if(l.s72 != r.s72) return l.s72 < r.s72;
        return strcmp(l.name, r.name) < 0;
    }
    if(l.isDq) return false;
    if(r.isDq) return true;
    if(l.s72 != r.s72)
        return l.s72 < r.s72;
    return strcmp(l.name, r.name) < 0;
}


//vector<Player> players;
Player players[maxn];
double allPrize;
double percent[70];
int numbers;


void printResult()
{
    printf("Player Name          Place     RD1  RD2");
    printf("  RD3  RD4  TOTAL     Money Won\n");
    printf("---------------------------------------");
    printf("--------------------------------\n");
}

void init()
{
    char str[40];
    gets(str); //read empyt line
    
    gets(str);
    sscanf(str,"%lf",&allPrize);
    for(int i=0; i<70; ++i){
        gets(str);
        sscanf(str,"%lf",&percent[i]);
    }
    
    gets(str);
    sscanf(str,"%d",&numbers);
    
    //get score data
    for(int j=0; j<numbers; ++j){
        gets(str);
        strncpy(players[j].name, str, 20);
        players[j].name[20] = 0;
        players[j].isPro = true;
       
        if(strchr(players[j].name, '*'))
            players[j].isPro = false;
                
        //atoi
        for(int i=0; i<4; ++i)
            players[j].s[i] = -1;
        players[j].s36 = players[j].s72 = 0;
        players[j].isDq = false;
        for(int i=0; i<4; ++i){
            char t[5];
            for(int k=0; k<3; ++k)
             t[k] = str[20 + i*3 + k];
            t[3] = '\0';
            
            // parse
            if(!sscanf(t,"%d", &players[j].s[i])) {
                //DQ
                players[j].nsc = i;
                players[j].isDq = true;
                 if(i<2)
                     players[j].s36 = -1;
                 break;
                
            }
            players[j].s72 += players[j].s[i];
            if(i<2)
                players[j].s36+= players[j].s[i];
            
        }
        
    }
}



void solve()
{
    sort(players,players+numbers,compare1);
    //70th many people a
    //do sth
    
    for(int i= n_cut - 1; i<numbers; ++i){
        if(i == numbers-1 || players[i].s36 != players[i+1].s36)
        {
            numbers = i+1;
            break;
        }
    }
    
    sort(players,players+numbers,compare2);
    //do sth to
    //get prize person Num;
    
    printResult();
    int prizeRank = 0;
    int i = 0;
    while( i < numbers){
        if(players[i].isDq){
            cout<<players[i].name<<"           ";
            for(int z=0; z<players[i].nsc; ++z)
                printf("%-5d",players[i].s[z]);
            for(int z=0; z<4-players[i].nsc; ++z)
                printf("     ");
                
            printf("DQ\n");
            ++i;
            continue;
        }

        int j = i;
        //get every rank interval
        int divCnt = 0;
        double sum = 0;
        bool have_money = false;
        while(j<numbers && players[i].s72 == players[j].s72)
        {
            if(players[j].isPro == true){
                if(prizeRank <n_cut){
                    sum+= percent[prizeRank++];
                    have_money = true;
                }
                divCnt++;
            }
            ++j;
        }
        // order record, and allplayer calculate
        int rankCnt = i+1;
        double amout = allPrize * sum / divCnt;
        while(i<j){
            //print ans
            cout<<players[i].name<<" ";
            //rank
            char t[5];
            sprintf(t, "%d%c", rankCnt, divCnt > 1 && have_money && players[i].isPro ? 'T' : ' ');
            printf("%-10s", t);
            
            for(int z=0; z<4; ++z)
                printf("%-5d",players[i].s[z]);
        
            //score and money
            if( players[i].isPro && have_money){
                printf("%-10d",players[i].s72);
                printf("$%9.2f\n",amout/100.0);
            }
            else
                printf("%d\n",players[i].s72);
            i++;
            
        }
    }
}


int main()
{
#ifdef debug
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    
    
    int t;
    char str[40];
    gets(str);
    sscanf(str,"%d",&t);
    
   
    while(t--){
        //clearData();
        init();
        solve();
        if(t)
            printf("\n");
    }
#ifdef debug
    fclose(stdin);
    fclose(stdout);
#endif
    
    return 0;
}





