#include "process.h"
#include "usr.h"
#include "OS.h"

void init();
int main(){
    // process a(0, 10, "root");
    // cout<<"!"<<endl;
    // usr u("root");
    // for (int i = 1; i <= 100; i ++){
    //     cout<<u.GetRandomNum(10, 15)<<endl;
    // }
    int ArriveTime[10000];
    for (int T = 0;;T++){
        
        
        if (ArriveTime[T] == 1){
            
        }   
    }
}

void init(){
    OS os;
    usr root("root");
    for (int i = 0;i < 10; i++){
        root.Write(os);
    }
}