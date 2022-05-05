#include <iostream>
#include <vector>
using namespace std;

double maxRating = 0;
int EmployeeID = -1;
void dfs(int i,int n, vector<vector<int>> adj,vector<int> rating, vector<int>& numberOFChild,vector<int>& RatingUnderTree){
    int temp = 0;
    int child = 0;
    for(int j:adj[i]){
        dfs(j,n,adj,rating,numberOFChild,RatingUnderTree);
        child+=numberOFChild[j];
        temp+=RatingUnderTree[j];
    }
    temp += rating[i];
    child++;
    numberOFChild[i] = child;
    RatingUnderTree[i] = temp;
    maxRating = max(maxRating , (double)(RatingUnderTree[i]/numberOFChild[i]));
}
void solve(int n, vector<vector<int>> adj,vector<int> rating){
    // n is number of employees, starting from 0,1,2.... n-1
    // rating[i] is rating assigned to ith employee
    // adj is adjacency list from 0 to all other nodes
    vector<int> RatingUnderTree(n,0);
    vector<int> numberOFChild(n,0);
    dfs(0 , n , adj , rating , numberOFChild,RatingUnderTree); 
}