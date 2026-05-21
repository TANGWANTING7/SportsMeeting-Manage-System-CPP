#include<iostream>

#include "utils.h"

#include "windows.h"

int main(){
    std::cout<<"正在进行初始化，请稍后\n";
    int res=initialSetting();
    if(res==3||res==5||res==6){
        printf("初始化失败，返回代码为%d\n",res);
        return 0;
    }
    while(true){
        system("cls");
        int key=showMenu();
        if(key==1){//运动员报名登记

        }
        else if(key==2){//参赛信息查询

        }
        else if(key==3){//竞赛检录

        }
        else if(key==4){//填写比赛结果

        }
        else if(key==5){//比赛成绩查询

        }
        else if(key==6){//竞赛成绩查询

        }
        else if(key==7){//退出系统
            break;
        }
    }
    return 0;
}