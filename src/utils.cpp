#include "utils.h"
// utils 实现

#include<iostream>
#include<cstdio>
#include<conio.h>
#include<filesystem>

int showMenu(){
    puts("测试主页面，按Q退出");
    char ch=getch();
    return (ch=='Q'||ch=='q');
}

int dataTest(){//已有data文件夹返回1，有data文件但无文件夹、创建成功后返回2、失败返回3，无data文件和文件夹、创建成功后返回4、失败返回5，创建失败返回6
    std::string folderName="data";

    if(filesystem::exists(folderName)){
        if(fs::is_directory(folderName)){
            return 1;
        }
        else{
            if(filesystem::create_directory(folderName)){
                return 2;
            }
            else{
                return 3;
            }
        }
    }
    else{
        if(filesystem::create_directory(folderName)){
            return 4;
        }
        else{
            return 5;
        }
    }
    return 6;
}


int itemTest(){
    std::string filePath="data"
}