#include "utils.h"
// utils 实现

#include<iostream>
#include<cstdio>
#include<conio.h>
//#include<filesystem>

int showMenu(){//int a[5] : 
    std::string opt[15];
    opt[1]="运动员报名登记";
    opt[2]="参赛信息查询";
    opt[3]="竞赛检录";
    opt[4]="填写比赛结果";
    opt[5]="比赛成绩查询";
    opt[6]="竞赛成绩查询";
    opt[7]="退出系统";
    int key=1;
    for(int i=1;i<=8;i++){
        if(key==i){
            std::cout<<" -> ";
        }
        else{
            std::cout<<"    ";
        }
        std::cout<<opt[i]<<std::endl;
    }
    while (true){
        char ch=getch();
        system("cls");
        if(ch=='w'||ch=='W'){
            key--;
            if(key<=0){
                key=1;
            }
        }
        if(ch=='s'||ch=='S'){
            key++;
            if(key>=8){
                key=7;
            }
        }
        if(ch=='E'||ch=='e'){
            return key;
        }
        for(int i=1;i<=8;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<opt[i]<<std::endl;
        }
    }
}

/*

int dataTest(){//已有data文件夹返回1，有data文件但无文件夹、创建成功后返回2、失败返回3，无data文件和文件夹、创建成功后返回4、失败返回5，创建失败返回6
    std::string folderName="data";

    if(std::filesystem::exists(folderName)){
        if(std::filesystem::is_directory(folderName)){
            return 1;
        }
        else{
            if(std::filesystem::create_directory(folderName)){
                return 2;
            }
            else{
                return 3;
            }
        }
    }
    else{
        if(std::filesystem::create_directory(folderName)){
            return 4;
        }
        else{
            return 5;
        }
    }
    return 6;
}


int itemTest(){
    std::string filePath="data";
}

*/

/*

std::string opt[10];

opt[1]="运动员报名登记";
opt[2]="";
....


opt[7]="";



//key=3

for(int i=1;i<=7;i++){
    std::cout<<" -> ";
    std::cout<<opt[i]<<std::endl;
}


*/