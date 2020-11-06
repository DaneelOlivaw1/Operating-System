#include "process.h"
#include "usr.h"
int main(){
    process a(0, 10, "root");
    cout<<"!"<<endl;
    usr u("root");
    for (int i = 1; i <= 100; i ++){
        cout<<u.GetRandomNum(10, 15)<<endl;
    }
}