#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MaxSize 100
/*��ջ����Թ�Ѱ·����*/

//���嵱ǰ����ṹ��andջ�ṹ��
typedef struct{
    int i; //��ǰ�����к�
    int j; //��ǰ�����к�
    int dir; //��һ���ڿ��߷�λ�ķ�λ��
}Box;

typedef struct{
    int top;//ջ��ָ��
    Box data[MaxSize];
}Stack;

//����Ƴ���һ���Թ�����1��ʾ�����߷��飬0��ʾ���߷���
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

//ջ��ʼ��
void InitStack(Stack*& s){
    s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
}

//����ջ
void DestroyStack(Stack*& s){
    free(s);
}

//��ջ
bool Push(Stack*& s,Box e){
    if(s->top == MaxSize-1){
        cout<<"ջ��"<<endl;
        return false;
    }
    else{
        s->top++;
        s->data[s->top] = e;
        return true;
    }
}

//��ջ
bool Pop(Stack*& s,Box e){
    if(s->top == -1){
        cout<<"ջ��"<<endl;
        return false;
    }
    else{
        e=s->data[s->top];
        s->top--;
        return true;
    }
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack* s){
    return (s->top == -1);
}

//ȡջ��Ԫ��
void getTop(Stack* s,Box& e){
    if(s->top == -1){
        cout<<"ջ��"<<endl;
        return ;
    }
    else{
        e = s->data[s->top];
    }
}

//����Թ������㷨
//���(xi,yi)������(xe,ye)
bool maze_path(int xi,int yi,int xe,int ye){
    Box path[MaxSize],e; //·������path,��ǰ��e
    int i,j,di,il,jl,k;
    bool find;
    Stack* st;
    InitStack(st);

    e.i = xi;
    e.j = yi;
    e.dir = -1;
    Push(st,e);
    maze[xi][yi] = -1;//�߹��Ŀ�ֵ����Ϊ-1����ֹ����ͷ����������ѭ��

    while(!isEmpty(st)){
        getTop(st,e);
        i = e.i; j =e.j;di = e.dir;
        if(i==xe && j==ye){//�ҵ����ڣ���ӡ·��
            cout<<"һ���Թ�·�����£�"<<endl;
            k=0;
            while(!isEmpty(st)){
                Pop(st,e);
                path[k++] = e;
            }
            while(k>=1){
                k--;
                cout<<"("<<path[k].i<<","<<path[k].j<<")"<<" ";
                if((k+2)%5 == 0){
                    cout<<endl;//ÿ5��������
                }
            }
            cout<<endl;
            DestroyStack(st);
            return true;
        }

        else{
            find = false;
            while(di<4 && !find){//�ҷ���(i,j)����һ�����߷���(il,jl)
                di++;
                switch(di)
                {
                    case 0:il=i-1;jl=j;break;//��
                    case 1:il=i;jl=j+1;break;//��
                    case 2:il=i+1;jl=j;break;//��
                    case 3:il=i;jl=j-1;break;//��
                }
                if(maze[il][jl]==0)find = true;//�ҵ����ڿ��߷���
            }
            if(find){
                st->data[st->top].dir =di;//�޸�ԭջ��diֵ
                e.i=il;e.j=jl;e.dir=-1;
                Push(st,e);//���ڿ��߷���e��ջ
                maze[il][jl]=-1;//��Ϊ-1�������ظ���
            }
            else{//û��·�����ߣ���ջ
                Pop(st,e);
                maze[e.i][e.j]=0;//����Ϊ0��������ѡ��
            }
        }  
    }
    DestroyStack(st);
    return false;//�Ҳ���·��������ջ
}

int main(){
    if(!maze_path(1,1,M,N)){
        cout<<"�޽�"<<endl;
    }
    return 1;
}