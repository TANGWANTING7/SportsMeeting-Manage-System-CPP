#include "query_module.h"
// query_module 实现

#include "models.h"

#include <iostream>

#include<fstream>

#include<conio.h>

#include<iomanip>

int matchQuery(){
    match matchList[101];

    int key=1;

    int numMatch=0;

    std::ifstream infile("data/item.dat");

    if(!infile.is_open()){
        return 1;
    }

    infile>>numMatch;

    for(int i=1;i<=numMatch;i++){
        infile>>matchList[i].name;
        infile>>matchList[i].numPlayer;
        for(int j=1;j<=matchList[i].numPlayer;j++){
            infile>>matchList[i].athleteList[j].name;
            infile>>matchList[i].athleteList[j].age;
            infile>>matchList[i].athleteList[j].from;
        }
    }

    infile.close();

    printf("共有以下%d个项目，通过'W'、'S'键选择项目，并回车以查看参赛情况，按Q退出\n",numMatch);

    if(key==1){
        for(int i=1;i<=3;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"项目："<<matchList[i].name<<std::endl;
        }
    }
    else if(key==numMatch){
        for(int i=key-2;i<=key;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"项目："<<matchList[i].name<<std::endl;
        }
    }
    else{
        for(int i=key-1;i<=key+1;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"项目："<<matchList[i].name<<std::endl;
        }
    }
    while(true){
        char ch=getch();

        system("cls");

        printf("共有以下%d个项目，通过'W'、'S'键选择项目，并回车以查看参赛情况，按Q退出\n",numMatch);

        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }

        if(ch=='S'||ch=='s'){
            key++;
            if(key>numMatch){
                key=numMatch;
            }
        }

        if(ch=='Q'||ch=='q'){
            system("cls");
            return 0;
        }

        if(ch=='\r'||ch=='\n'){
            system("cls");
            std::cout<<"项目："<<matchList[key].name<<" 共有以下参赛运动员，按任意键即可退出"<<std::endl;
            for(int j=1;j<=matchList[key].numPlayer;j++){
                std::cout<<"运动员 "<<j<<" 姓名："<<std::setw(10)<<matchList[key].athleteList[j].name<<"  年龄："<<std::setw(10)<<matchList[key].athleteList[j].age<<"  学校："<<matchList[key].athleteList[j].from<<std::endl;
            }
            char quit=getch();
            system("cls");
            
            printf("共有以下%d个项目，通过'W'、'S'键选择项目，并回车以查看参赛情况，按Q退出\n",numMatch);

            if(key==1){
                for(int i=1;i<=3;i++){
                    if(key==i){
                        std::cout<<" -> ";
                    }
                    else{
                        std::cout<<"    ";
                    }
                    std::cout<<"项目："<<matchList[i].name<<std::endl;
                }
            }
            else if(key==numMatch){
                for(int i=key-2;i<=key;i++){
                    if(key==i){
                        std::cout<<" -> ";
                    }
                    else{
                        std::cout<<"    ";
                    }
                    std::cout<<"项目："<<matchList[i].name<<std::endl;
                }
            }
            else{
                for(int i=key-1;i<=key+1;i++){
                    if(key==i){
                        std::cout<<" -> ";
                    }
                    else{
                        std::cout<<"    ";
                    }
                    std::cout<<"项目："<<matchList[i].name<<std::endl;
                }
            }
            continue;
        }

        if(key==1){
            for(int i=1;i<=3;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"项目："<<matchList[i].name<<std::endl;
            }
        }
        else if(key==numMatch){
            for(int i=key-2;i<=key;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"项目："<<matchList[i].name<<std::endl;
            }
        }
        else{
            for(int i=key-1;i<=key+1;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"项目："<<matchList[i].name<<std::endl;
            }
        }
    }

}