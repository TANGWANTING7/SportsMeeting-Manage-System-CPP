#include "utils.h"
// utils 实现

#include<iostream>
#include<cstdio>
#include<conio.h>

bool showMenu(){
    puts("测试主页面，按Q退出");
    char ch=getch();
    return (ch=='Q'||ch=='q');
}