#include "process.h"
#include "usr.h"
#include "OS.h"
#include<queue>

void init();
int main(){
    // process a(0, 10, "root");
    // cout<<"!"<<endl;
    // usr u("root");
    // for (int i = 1; i <= 100; i ++){
    //     cout<<u.GetRandomNum(10, 15)<<endl;
    // }
    // init();
    
    OS os;
    usr root("root");
    for (int i = 0;i < 10; i++){
        root.Write(os);
    }
    
    for (int T = 0; T < 30;T++){   //时钟
        if(rand() % 2 == 1){    //0.5概率产生新进程
            int len = root.Write(os);
            /*
                st_pos :os中开始存储位置
                len 代码行长度


            */
            int st_pos = 1;
            process tp(st_pos, len, "root");
            //tp.state = READY;
            //tp.level = 0;
            //tp.cnt = 0;
            tp.arrivetime = T;
            os.Ready_q.push(tp);
        } 
        os.run(T);
    }
}

// void init(){
//     usr root("root");
//     for (int i = 0;i < 10; i++){
//         root.Write(os);
//     }
// }