#include <iostream>
#include <climits>
using namespace std;

struct  edge{
    char strt, des;
    int dis;   
};

void BF(int graph[20][20], int num, char star, int cur[20], int prev[20]){
    vector <edge> edge_list;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int start = alphabet.find(star);


    for (int i = 0; i < num-1; i++){
        for (int j = 0; j < num; j++){
            if (graph[i][j] != 0){
                edge temp = {alphabet[i], alphabet[j], graph[i][j]};
                edge_list.push_back(temp);
            }
        }
    }
    int len = edge_list.size();
    int dist[26];
    for (int i = 0; i < num; i++){
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    for (int i = 0; i < num - 1; i++){
        for (int j = 0; j < len; j++){
            int u = alphabet.find(edge_list[j].strt);
            int v = alphabet.find(edge_list[j].des);
            int d = edge_list[j].dis;
            if (dist[u] != INT_MAX && dist[u] + d < dist[v]){
                dist[v] = dist[u] + d;
                prev[v] = u;
            }
        }
    }
    for (int i = 0; i < num; i++){
        cur [i] = dist[i]  ;
    }
}


string BF_Path(int graph[20][20], int num, char st, char end){
    if (st == end){
        string a = "";
        a += st;
        return a;
    }
    int dist[20], prev[20];
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int start = alphabet.find(st);
    int goal = alphabet.find(end);

    for (int i = 0; i < num; i++){
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    BF(graph, num, st, dist, prev);
    
    vector <char> temp;
    for (int i = goal; i != -1; i = prev[i]){
        temp.push_back(alphabet[i]);
    }
    string a ="";
    while (!temp.empty()){
        a += temp.back();
        a+= " ";
        temp.pop_back();
    }
    return a;

}