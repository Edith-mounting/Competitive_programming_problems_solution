#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		
		stack<int> arr[a+1];

		for(int j = 0; j < b; j++){
			string s;
			cin >> s;

		//push
			if(s == "push"){
				int x, y;
            	cin >> x >> y;
            	
            	arr[x-1].push(y);
        	}
        //top
        	else if(s == "top"){
        		int q;

        		cin >> q;
        	    if(!arr[q-1].empty()){
        	    	cout << arr[q-1].top() <<endl;
        	    }
        	    else{
        	    	cout << "Empty !" << endl;
        	    }
        	}
        //put
        	else if(s == "put"){
        		int e, r;
        		cin >> r >> e;
        		int x;
        		stack<int> st3;

				x = arr[r-1].size();
				for(int i = 0; i < x; i++){
					st3.push(arr[r-1].top());
					arr[r-1].pop();
				}
				
				
				int y; 
				y = st3.size();
				for(int i = 0; i < y; i++){
					arr[e-1].push(st3.top());
					st3.pop();
				}


        	}
        //pop
        	else if(s == "pop"){
        		int t;
        		cin >> t;
        		if(!arr[t-1].empty()){
        			arr[t-1].pop();
        		}
        	
        	}

			
		}
	}
}