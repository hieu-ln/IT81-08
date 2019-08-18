#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

void bfs(int n, vector<vector<int>>& edgelist, vector<int>& dist, queue<int>& q) 
{
    
    for (int i : edgelist[n]) 
    {
        if (dist[i] != -1) continue;
        dist[i] = dist[n] + 1;
        q.push(i);
    }
    if (!q.empty()) 
    {
        n = q.front();
        q.pop();
        bfs(n, edgelist, dist, q);
    }
}