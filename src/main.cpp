#include<iostream>

#include "utils.h"

#include<input_module.h>

#include "windows.h"



int main(){
    puts("正在进行初始化，请稍后");
    int res=dataTest();
    if(res==3||res==5||res==6){
        printf("data文件夹创建失败，错误代码为%d\n",res);
        return 0;
    }
    while(true){
        system("cls");
        int key=showMenu();
        if(key==1){//运动员报名登记
            int resKey=athleteRegister();
            if(resKey){
                printf("报名程序非正常退出，错误代码为%d\n",resKey);
            }
        }
        else if(key==2){//参赛信息查询
            std::cout<<"success to 2";
        }
        else if(key==3){//竞赛检录
            std::cout<<"success to 3";
        }
        else if(key==4){//填写比赛结果
            std::cout<<"success to 4";
        }
        else if(key==5){//比赛成绩查询
            std::cout<<"success to 5";
        }
        else if(key==6){//竞赛成绩查询
            std::cout<<"success to 6";
        }
        else if(key==7){//退出系统
            break;
        }
    }
    return 0;
}
//请通过'W'、'S'键选择数字，通过'E'键确定你要选的数字
//运动员数量已被确认为