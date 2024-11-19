#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxNum 100 //��󶥵���

//�߽��
typedef struct edge_node{
    int pos;//�ñ������Ķ���λ��
    struct edge_node* next; //�͸ñ�������ͬһ�������һ����
}edge_node;

//������
typedef struct ding_node{
    char info; //������Ϣ
    edge_node* first_edge; //���Ӹö���ĵ�һ����
}ding_node;

//����ͼ��
class Graph
{
    public:
    bool visited[MaxNum]; //��־���飬��Ǹö����Ƿ񱻷��ʹ�
    ding_node ding_list[MaxNum]; //��������
    int edge_num,ding_num;//����������������

    void CreatGraph(); //����ͼ
    void Print(); //��ӡ������ͼ�������ڽӱ�
    void DFS(int v); //��������������Ӷ���v��ʼ
    void BFS(int v); //��������������Ӷ���v��ʼ
};

void Graph::CreatGraph(){
    memset(this->visited,0,sizeof(visited)); //��־����ȫ����Ϊ0
    cout<<"�������ܶ�����";
    cin>>ding_num;
    cout<<"�������ܱ���";
    cin>>edge_num;

    cout<<"�����붥����Ϣ��";
    for(int i=0;i<this->ding_num;i++){
        cin>>this->ding_list[i].info; //���붥����Ϣ
        this->ding_list[i].first_edge = NULL; //��ʼ����ͷ���ָ����ΪNULL
    }
    cout<<"������ÿ���ߵ�������(��ֵ):";
    for(int i=0;i<this->edge_num;i++){
        int v1,v2; //һ���ߵ���������
        cin>>v1>>v2;

        //ͷ�巨����߽��
        edge_node* p = new edge_node; //�½��߽��
        p->pos = v2;
        p->next = this->ding_list[v1].first_edge;
        this->ding_list[v1].first_edge = p;

        //����ͼ�Գƣ�������㶼Ҫ��
        edge_node* q = new edge_node;
        q->pos = v1;
        q->next = this->ding_list[v2].first_edge;
        this->ding_list[v2].first_edge = q;
    }
}

void Graph::Print(){
    cout<<"�ɸ�����ͼ�������ڽӱ�Ϊ��";
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
    visited[v] = 1; //��Ƕ���v�Ѿ�������
    cout<<ding_list[v].info<<" "; //��ӡ������Ϣ

    //����v�������ڽӱ�
    edge_node *p = ding_list[v].first_edge;
    while(p != NULL){
        if(!visited[p->pos]){//���㻹δ������
            DFS(p->pos);//�ݹ��������
        }
        p = p->next; //������һ����
    }
}

void Graph::BFS(int v){
    queue<int>q; //����
    memset(visited,0,sizeof(visited)); //��ʼ��
    visited[v] = 1;
    q.push(v);//��ʼ�������

    while(!q.empty()){
        int u = q.front(); //ȡ���׶���
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

    cout<<"����������������";
    memset(G.visited, 0, sizeof(G.visited)); // ��ʼ����־����
    G.DFS(0);
    cout<<endl;

    cout<<"����������������";
    G.BFS(0);
    cout<<endl;

    return 0;
}