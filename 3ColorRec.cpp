#include <iostream>
using namespace std;

void graphcolor(int g_size,int **graph,int *c,bool &flag,int k);
void colorrec(int g_size,int **graph);

void colorrec(int g_size,int **graph){
    /*int *c=new int[g_size];
    for(int i=0;i<g_size;i++)
        c[i]=0;
    */
    int c[g_size];
    memset(c,0,sizeof(c));

    bool flag=false;
    graphcolor(g_size,graph,c,flag,0);
    if(flag)
        for(int i=0;i<g_size;i++)
            cout<<c[i]<<' ';
    else
        cout<<"no solution"<<endl;
}

void graphcolor(int g_size,int **graph,int *c,bool &flag,int k){

    bool jump;
    for(int color=1;color<=3;color++) {
        jump = false;
        c[k] = color;
        for (int node = 0; node < k; node++)
            if (graph[node][k] == 1 && c[node] == c[k]) {
                jump = true;
                break;
            }
        if (!jump) {
            if (k == g_size - 1) {
                flag = true;
                return;
            } else {
                return graphcolor(g_size, graph, c, flag, k + 1);
            }
        }
    }
}

int main(){
    int i,j;
    int g_size;
    cin>>g_size;
    int **graph=new int*[g_size];
    for(i=0;i<g_size;i++)
        graph[i]=new int[g_size];

    for(i=0;i<g_size;i++)
        for(j=0;j<g_size;j++)
            cin>>graph[i][j];

    colorrec(g_size,graph);
    return 0;
}

/*
input:
5
0 1 1 0 0
1 0 0 1 1
1 0 0 1 1
0 1 1 0 1
0 1 1 1 0
 *
output:
1 2 2 1 3 
 *
 *
 */
