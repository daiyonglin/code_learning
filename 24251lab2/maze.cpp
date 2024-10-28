#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MaxSize 100
/*用栈解决迷宫寻路问题*/

//定义当前方块结构体and栈结构体
typedef struct{
    int i; //当前方块行号
    int j; //当前方块列号
    int dir; //下一相邻可走方位的方位号
}Box;

typedef struct{
    int top;//栈顶指针
    Box data[MaxSize];
}Stack;

//先设计出来一个迷宫，用1表示不可走方块，0表示可走方块
const int M=8,N=8;
int maze[M+2][N+2]=
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

//栈初始化
void InitStack(Stack*& s){
    s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
}

//销毁栈
void DestroyStack(Stack*& s){
    free(s);
}

//进栈
bool Push(Stack*& s,Box e){
    if(s->top == MaxSize-1){
        cout<<"栈满"<<endl;
        return false;
    }
    else{
        s->top++;
        s->data[s->top] = e;
        return true;
    }
}

//出栈
bool Pop(Stack*& s,Box e){
    if(s->top == -1){
        cout<<"栈空"<<endl;
        return false;
    }
    else{
        e=s->data[s->top];
        s->top--;
        return true;
    }
}

//判断栈是否为空
bool isEmpty(Stack* s){
    return (s->top == -1);
}

//取栈顶元素
void getTop(Stack* s,Box& e){
    if(s->top == -1){
        cout<<"栈空"<<endl;
        return ;
    }
    else{
        e = s->data[s->top];
    }
}

//求解迷宫问题算法
//入口(xi,yi)，出口(xe,ye)
bool maze_path(int xi,int yi,int xe,int ye){
    Box path[MaxSize],e; //路径数组path,当前块e
    int i,j,di,il,jl,k;
    bool find;
    Stack* st;
    InitStack(st);

    e.i = xi;
    e.j = yi;
    e.dir = -1;
    Push(st,e);
    maze[xi][yi] = -1;//走过的块值设置为-1，防止被回头搜索陷入死循环

    while(!isEmpty(st)){
        getTop(st,e);
        i = e.i; j =e.j;di = e.dir;
        if(i==xe && j==ye){//找到出口，打印路径
            cout<<"一条迷宫路径如下："<<endl;
            k=0;
            while(!isEmpty(st)){
                Pop(st,e);
                path[k++] = e;
            }
            while(k>=1){
                k--;
                cout<<"("<<path[k].i<<","<<path[k].j<<")"<<" ";
                if((k+2)%5 == 0){
                    cout<<endl;//每5个数换行
                }
            }
            cout<<endl;
            DestroyStack(st);
            return true;
        }

        else{
            find = false;
            while(di<4 && !find){//找方块(i,j)的下一个可走方块(il,jl)
                di++;
                switch(di)
                {
                    case 0:il=i-1;jl=j;break;//上
                    case 1:il=i;jl=j+1;break;//右
                    case 2:il=i+1;jl=j;break;//下
                    case 3:il=i;jl=j-1;break;//左
                }
                if(maze[il][jl]==0)find = true;//找到相邻可走方块
            }
            if(find){
                st->data[st->top].dir =di;//修改原栈顶di值
                e.i=il;e.j=jl;e.dir=-1;
                Push(st,e);//相邻可走方块e进栈
                maze[il][jl]=-1;//置为-1，避免重复走
            }
            else{//没有路径可走，退栈
                Pop(st,e);
                maze[e.i][e.j]=0;//设置为0，供其他选择
            }
        }  
    }
    DestroyStack(st);
    return false;//找不到路径，销毁栈
}

int main(){
    if(!maze_path(1,1,M,N)){
        cout<<"无解"<<endl;
    }
    return 1;
}