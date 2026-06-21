#include "match_module.h"
// match_module 实现

#include "models.h"

#include <iostream>

#include<fstream>

#include<conio.h>

#include<iomanip>

int scoreInput(){
    puts("输入该运动员该项目得分");
    int x=0;
    std::cin>>x;
    return x;
}

int scoreInit(){
    std::ifstream infile("data/item.dat");

    match matchList[11];

    int numMatch=0;

    if(!infile.is_open()){
        return 0;
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

    std::ofstream outfile("data/score.dat",std::ios::trunc);

    outfile<<numMatch<<std::endl;

    for(int i=1;i<=numMatch;i++){
        outfile<<matchList[i].name<<std::endl;
        outfile<<matchList[i].numPlayer<<std::endl;
        for(int j=1;j<=matchList[i].numPlayer;j++){
            outfile<<matchList[i].athleteList[j].name<<" ";
            outfile<<matchList[i].athleteList[j].age<<" ";
            outfile<<matchList[i].athleteList[j].from<<" ";
            outfile<<matchList[i].score[j]<<std::endl;
        }
    }

    outfile.close();

}

int matchScoreInput(){
    std::ifstream infile("data/score.dat");

    match matchList[11];

    int numMatch=0;

    if(!infile.is_open()){
        return 0;
    }

    infile>>numMatch;

    if(!numMatch){
        infile.close();
        scoreInit();
        infile>>numMatch;

        for(int i=1;i<=numMatch;i++){
            
            infile>>matchList[i].name;
            infile>>matchList[i].numPlayer;

            for(int j=1;j<=matchList[i].numPlayer;j++){
                infile>>matchList[i].athleteList[j].name;
                infile>>matchList[i].athleteList[j].age;
                infile>>matchList[i].athleteList[j].from;
                infile>>matchList[i].score[j];
            }
        }
    }
    else{
        for(int i=1;i<=numMatch;i++){
            infile>>matchList[i].name;
            infile>>matchList[i].numPlayer;
            for(int j=1;j<=matchList[i].numPlayer;j++){
                infile>>matchList[i].athleteList[j].name;
                infile>>matchList[i].athleteList[j].age;
                infile>>matchList[i].athleteList[j].from;
                infile>>matchList[i].score[j];
            }
        }
    }

    infile.close();

    printf("共有以下%d个项目，通过'W'、'S'键选择项目，并回车以查看参赛情况，按Q退出\n",numMatch);

    int key=1;

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

            std::ofstream outfile("data/item.dat",std::ios::trunc);

            outfile<<numMatch<<std::endl;

            for(int k=1;k<=numMatch;k++){
                outfile<<matchList[k].name<<std::endl;
                outfile<<matchList[k].numPlayer<<std::endl;
                for(int l=1;l<=matchList[k].numPlayer;l++){
                    outfile<<matchList[k].athleteList[l].name<<" ";
                    outfile<<matchList[k].athleteList[l].age<<" ";
                    outfile<<matchList[k].athleteList[l].from<<" ";
                    outfile<<matchList[k].score[l]<<std::endl;
                }
            }

            outfile.close();

            return 0;
        }

        if(ch=='\r'||ch=='\n'){
            system("cls");
            std::cout<<"项目："<<matchList[key].name<<" 共有以下参赛运动员，通过'W'、'S'选择运动员，并回车以记分"<<std::endl;

            int key2=1;

            if(key2==1){
                for(int j=1;j<=3;j++){
                    if(j==key2){
                        std::cout<<" -> ";
                    }
                    else{
                        std::cout<<"    ";
                    }
                    std::cout<<"运动员 "<<j<<" 姓名："<<std::setw(10)<<matchList[key].athleteList[j].name<<"  年龄："<<std::setw(10)<<matchList[key].athleteList[j].age<<"  学校："<<std::setw(10)<<matchList[key].athleteList[j].from<<" 分数："<<matchList[key].score[j]<<std::endl;
                }
            }
            else if(key2==matchList[key].numPlayer){
                for(int j=key2-2;j<=key2;j++){
                    if(j==key2){
                        std::cout<<" -> ";
                    }
                    else{
                        std::cout<<"    ";
                    }
                    std::cout<<"运动员 "<<j<<" 姓名："<<std::setw(10)<<matchList[key].athleteList[j].name<<"  年龄："<<std::setw(10)<<matchList[key].athleteList[j].age<<"  学校："<<std::setw(10)<<matchList[key].athleteList[j].from<<" 分数："<<matchList[key].score[j]<<std::endl;
                }
            }
            else{
                for(int j=key2-1;j<=key2+1;j++){
                    if(j==key2){
                        std::cout<<" -> ";
                    }
                    else{
                        std::cout<<"    ";
                    }
                    std::cout<<"运动员 "<<j<<" 姓名："<<std::setw(10)<<matchList[key].athleteList[j].name<<"  年龄："<<std::setw(10)<<matchList[key].athleteList[j].age<<"  学校："<<std::setw(10)<<matchList[key].athleteList[j].from<<" 分数："<<matchList[key].score[j]<<std::endl;
                }
            }

            
            while(true){
                char ch2=getch();

                system("cls");

                std::cout<<"项目："<<matchList[key].name<<" 共有以下参赛运动员，通过'W'、'S'选择运动员，并回车以记分"<<std::endl;

                if(ch2=='W'||ch2=='w'){
                    key2--;
                    if(!key2)
                    key2=1;
                }

                if(ch2=='S'||ch2=='s'){
                    key2++;
                    if(key2>matchList[key].numPlayer)
                    key2=matchList[key].numPlayer;
                }

                if(ch2=='\n'||ch2=='\r'){
                    matchList[key].score[key2]=scoreInput();
                    system("cls");
                    std::cout<<"项目："<<matchList[key].name<<" 共有以下参赛运动员，通过'W'、'S'选择运动员，并回车以记分"<<std::endl;
                }

                if(ch2=='Q'||ch2=='q'){
                    break;
                }

                if(key2==1){
                    for(int j=1;j<=3;j++){
                        if(j==key2){
                            std::cout<<" -> ";
                        }
                        else{
                            std::cout<<"    ";
                        }
                        std::cout<<"运动员 "<<j<<" 姓名："<<std::setw(10)<<matchList[key].athleteList[j].name<<"  年龄："<<std::setw(10)<<matchList[key].athleteList[j].age<<"  学校："<<std::setw(10)<<matchList[key].athleteList[j].from<<" 分数："<<matchList[key].score[j]<<std::endl;
                    }
                }
                else if(key2==matchList[key].numPlayer){
                    for(int j=key2-2;j<=key2;j++){
                        if(j==key2){
                            std::cout<<" -> ";
                        }
                        else{
                            std::cout<<"    ";
                        }
                        std::cout<<"运动员 "<<j<<" 姓名："<<std::setw(10)<<matchList[key].athleteList[j].name<<"  年龄："<<std::setw(10)<<matchList[key].athleteList[j].age<<"  学校："<<std::setw(10)<<matchList[key].athleteList[j].from<<" 分数："<<matchList[key].score[j]<<std::endl;
                    }    
                }
                else{
                    for(int j=key2-1;j<=key2+1;j++){
                        if(j==key2){
                            std::cout<<" -> ";
                        }
                        else{
                            std::cout<<"    ";
                        }
                        std::cout<<"运动员 "<<j<<" 姓名："<<std::setw(10)<<matchList[key].athleteList[j].name<<"  年龄："<<std::setw(10)<<matchList[key].athleteList[j].age<<"  学校："<<std::setw(10)<<matchList[key].athleteList[j].from<<" 分数："<<matchList[key].score[j]<<std::endl;
                    }
                }
            }
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