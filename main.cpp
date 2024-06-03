#include "bellman.h"
#include <fstream>


int main(){
    int numVer = 5;
    char start = 'A';
    int graph[20][20];
    int cur[20], prev[20]; 

    for (int i  = 0; i < numVer; i++){
        cur[i] = -1;
        prev[i] = -1;
    }
    ifstream inputfile("ex.txt");

    for (int i = 0; i < numVer; i++){
        for(int j = 0; j < numVer; j++){
            inputfile >> graph[i][j];
        }
    }
    BF(graph, numVer, start, cur, prev);
    cout << BF_Path(graph, numVer, 'A', 'E') << endl;

    for(int i = 0; i < numVer; i++ ){
        cout << cur[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < numVer; i++ ){
        cout << prev[i] << " ";
    }
    inputfile.close();
}
