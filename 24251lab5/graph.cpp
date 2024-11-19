#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxNum 100 //最大顶点数

//边结点
typedef struct edge_node{
    int pos;//该边所连的顶点位置
    struct edge_node* next; //和该边连接在同一顶点的下一条边
}edge_node;

//顶点结点
typedef struct ding_node{
    char info; //顶点信息
    edge_node* first_edge; //连接该顶点的第一个边
}ding_node;

//无向图类
class Graph
{
    public:
    bool visited[MaxNum]; //标志数组，标记该顶点是否被访问过
    ding_node ding_list[MaxNum]; //顶点数组
    int edge_num,ding_num;//边数量、顶点数量

    void CreatGraph(); //创建图
    void Print(); //打印由无向图创建的邻接表
    void DFS(int v); //深度优先搜索，从顶点v开始
    void BFS(int v); //广度优先搜索，从顶点v开始
};

void Graph::CreatGraph(){
    memset(this->visited,0,sizeof(visited)); //标志数组全部置为0
    cout<<"请输入总顶点数";
    cin>>ding_num;
    cout<<"请输入总边数";
    cin>>edge_num;

    cout<<"请输入顶点信息：";
    for(int i=0;i<this->ding_num;i++){
        cin>>this->ding_list[i].info; //输入顶点信息
        this->ding_list[i].first_edge = NULL; //初始化表头结点指针域为NULL
    }
    cout<<"请输入每条边的两顶点(数值):";
    for(int i=0;i<this->edge_num;i++){
        int v1,v2; //一条边的两个顶点
        cin>>v1>>v2;

        //头插法插入边结点
        edge_node* p = new edge_node; //新建边结点
        p->pos = v2;
        p->next = this->ding_list[v1].first_edge;
        this->ding_list[v1].first_edge = p;

        //无向图对称，两个结点都要插
        edge_node* q = new edge_node;
        q->pos = v1;
        q->next = this->ding_list[v2].first_edge;
        this->ding_list[v2].first_edge = q;
    }
}

void Graph::Print(){
    cout<<"由该无向图创建的邻接表为：";
    cout<<endl;
    for(int i=0;i<this->ding_num;i++){
        edge_node *temp;
        temp = this->ding_list[i].first_edge;
        cout<<this->ding_list[i].info<<":";
        while(temp){
            cout<<temp->pos<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void Graph::DFS(int v){
    visited[v] = 1; //标记顶点v已经被访问
    cout<<ding_list[v].info<<" "; //打印顶点信息

    //遍历v的所有邻接边
    edge_node *p = ding_list[v].first_edge;
    while(p != NULL){
        if(!visited[p->pos]){//顶点还未被访问
            DFS(p->pos);//递归进行深搜
        }
        p = p->next; //访问下一条边
    }
}

void Graph::BFS(int v){
    queue<int>q; //队列
    memset(visited,0,sizeof(visited)); //初始化
    visited[v] = 1;
    q.push(v);//起始顶点入队

    while(!q.empty()){
        int u = q.front(); //取队首顶点
        q.pop();
        cout<<ding_list[u].info<<" ";

        edge_node *p = ding_list[u].first_edge;
        while(p != NULL){
            if(!visited[p->pos]){
                visited[p->pos] = 1;
                q.push(p->pos);
            }
            p = p->next;
        }
    }
}

int main(){
    Graph G;
    G.CreatGraph();
    G.Print();

    cout<<"深度优先搜索结果：";
    memset(G.visited, 0, sizeof(G.visited)); // 初始化标志数组
    G.DFS(0);
    cout<<endl;

    cout<<"广度优先搜索结果：";
    G.BFS(0);
    cout<<endl;

    return 0;
}