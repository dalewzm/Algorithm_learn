//输入8个顶点，矩形只有4个顶点，一个点必然出现两次
//每条边与其他边要么平行，要么垂直
//#define debug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <queue>
#include <set>
//#include <unordered_map>
#define REP(i,n) for(int i=0; i<(n); ++i)

using namespace std;


typedef struct Point{
    int x;
    int y;
    Point(){x=0,y=0;}
    Point(int a,int b):x(a),y(b){}
    bool operator == (const Point &rhs)
    {
        return x == rhs.x && y == rhs.y;
    }
    bool operator !=(const Point &rhs)
    {
        return !operator==(rhs);
    }
    friend bool operator < (const Point& p1, const Point& p2)
    {
        if(p1.x != p2.x)
            return p1.x < p2.x;
        return p1.y < p2.y;
    }
}Point;



typedef Point Vector;

typedef struct Seg{
    Point st;
    Point ed;
}Seg;


typedef struct Rec{
    Vector vec[4];
    Seg se[4];
}Rec;


bool para(Vector &left, Point &rhs)
{
    //bool ret =
    return left.x*rhs.y == left.y*rhs.x;;
}

double dot(Point a, Point b)
{
    return a.x*b.x + a.y*b.y;
}

bool orth(Point &left, Point &rhs)
{
    //int value = left.x*rhs.y + left.y * rhs.x;
    bool ret = ((left.x*rhs.x + left.y * rhs.y)  == 0);
    return ret;
}

bool solve(Rec &rec)
{
    //rec.ver[0] = rec.se[0].st;
    set<Point> pset;
    for(int i=0; i<4; ++i)
    {
        pset.insert(rec.se[i].st);
        pset.insert(rec.se[i].ed);
    }
    if(pset.size() != 4)
        return false;
    for(int i=0; i<4; ++i)
    {
        for(int j=i+1; j<4; ++j)
        {
            if( (!para(rec.vec[i],rec.vec[j])) && (!orth(rec.vec[i],rec.vec[j])))
                return false;
        }
    }
    return true;
}

int main()
{
#ifdef debug
    freopen("input.in","r",stdin);
#endif
    int kase;
    scanf("%d",&kase);
    int x1,x2,y1,y2;
    Rec tmp;
    while(kase--){
        for(int z=0; z<4; ++z){
            scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
            tmp.se[z].st = Point(x1,y1);
            tmp.se[z].ed = Point(x2,y2);
            tmp.vec[z] = Vector(x2-x1,y2-y1);
        }
        if(solve(tmp))
            printf("YES\n");
        else
            printf("NO\n");
    }
    
#ifdef debug
    fclose(stdin);
#endif
    
    return 0;
}






