
#ifndef BELLMAN_H
#define BELLMAN_H

#include <iostream>
#include <vector>
using namespace std;
struct edge;
void BF(int[20][20], int, char ,int[20], int[20]);

string BF_Path(int[20][20], int, char, char);

#endif