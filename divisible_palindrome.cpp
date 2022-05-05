#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x=0;//for number of sundays

    //here last day= (1->sunday 2->monday 3->tuesday 4->wednesday 5->thursday 6->friday 7->saturday)
    
    int last_day=3;//first day of 1901
    
    for(int i=1901;i<=2000;i++){
        /*
        for value of j
        1->jan, 2->feb, 3->march, 4->april, 5->may, 6->june,
        7->july, 8->aug, 9->sep, 10->oct, 11->nov, 12->dec
        */
        for(int j=1;j<=12;j++){
            if(j==4 || j==6 || j==9 || j==11){
                last_day+=30;
            }
            else if(j==2){
                if(i%4==0){
                    last_day+=29;
                }
                else{
                    last_day+=28;
                }
            }
            else{
                last_day+=31;
            }
            last_day%=7;
            if(last_day==0){
                last_day=7;
            }
            if(last_day==1){
                x++;
            }
        }
    }
    if(last_day==1){
        x--;
    }
    cout<<x<<"\n";
}