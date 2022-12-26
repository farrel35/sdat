#include <iostream>

using namespace std;

const int N = 5;

struct Node{
    int v;
    Node *next;
};

struct List{
    Node *head;
};

List adj[N];

void tambahEdge(int a, int b){
    Node *node = new Node();
    node->v = b;
    node->next = adj[a].head;
    adj[a].head = node;
}

void cetakGraph(){
    for(int i = 0; i < N; i++){
        Node *p = adj[i].head;
        cout << "Vertex " << i << ": ";
        while(p){
            cout << p->v << " ";
            p = p->next;

        }
        cout << endl;
    }
}

int main()
{
    tambahEdge(0,1);
    tambahEdge(1,2);
    tambahEdge(2,3);
    tambahEdge(3,4);
    tambahEdge(4,5);
    cetakGraph();
    return 0;
}
