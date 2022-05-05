#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;


string countIslands(int num)
{
	int x = 0, y = 1;
    int z = 0;
    if(num == x || num == y){
        return "yes";
    }
    while(true){
        if(z > num){
            break;
        }
        z = x + y;
        if(z == num){
            return "yes";
        }
        x = y;
        y = z;
    }
    return "no";
}

// main function
int main()
{
    int num;
    cin >> num;
    cout << countIslands(num);
}
