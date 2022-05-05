#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct job
{
    /* data */
    int id;
    int dead;
    int profit;
};
bool comp(const job a, const job b){
        return (a.profit>b.profit);
    }
class Solution 
{
    public:
        
        //Function to find the maximum profit and the number of jobs done.
        vector<int> JobScheduling(job arr[], int n)
        { 
            // your code here
            
            sort(arr , arr + n, comp);
            for(int i=0;i<n;i++){
                cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<"\n";
            }
            vector<int> ans(2,0);
            return ans;
        } 
};


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        job arr[n];
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            arr[i].id=x;
            arr[i].dead=y;
            arr[i].profit=z;
        }
        Solution ob;
        vector<int> ans=ob.JobScheduling(arr,n);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
        return 0;
    }
}