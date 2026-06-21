#include "utils.h"
// utils 实现
#include<windows.h>
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<filesystem>
#include<fstream>

int showMenu(){
    std::string opt[15];
    opt[1]="运动员报名登记";
    opt[2]="新建项目及注册";
    opt[3]="参赛信息查询";
    opt[4]="填写比赛结果";
    opt[5]="比赛成绩查询";
    opt[6]="竞赛成绩查询";
    opt[7]="退出系统";
    int key=1;
    puts("通过'W'、'S'键移动光标、按回车键选择");
    for(int i=1;i<=7;i++){
        if(key==i){
            std::cout<<" -> ";
        }
        else{
            std::cout<<"    ";
        }
        std::cout<<opt[i]<<std::endl;
    }
    while(true){
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
        if(ch=='\r'||ch=='\n'){
            return key;
        }
        puts("通过'W'、'S'键移动光标、按回车键选择");
        for(int i=1;i<=7;i++){
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

int overallTest(){
    int res=dataTest();
    if(res==3||res==5||res==6){
        printf("data文件夹创建失败，错误代码为%d\n",res);
        return 0;
    }
    res=universityTest();
    if(!res){
        puts("university.dat文件创建失败");
        return 0;
    }
    res=itemTest();
    if(!res){
        puts("item.dat文件创建失败");
        return 0;
    }
    res=scoreTest();
    if(!res){
        puts("score.dat文件创建失败");
        return 0;
    }
    return 1;
}

int dataTest(){//已有data文件夹返回1，有data文件但无文件夹、创建成功后返回2、失败返回3，无data文件和文件夹、创建成功后返回4、失败返回5，创建失败返回6
    std::string folderName="data";

    if(std::filesystem::exists(folderName)){
        if(std::filesystem::is_directory(folderName)){
            return 1;
        }
        else{
            std::filesystem::remove(folderName); //如果是文件，需要先删除再创建文件夹
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

int createUniversityFile(){//成功返回1，否则返回0
    std::ofstream outfile("data/university.dat",std::ios::app);
    if(outfile.is_open()){
        outfile<<0<<std::endl;
        outfile.close();
        return 1;
    }
    else{
        return 0;
    }
}

int universityTest(){//成功返回1，否则返回0
    std::string filePath="data/university.dat";
    if(std::filesystem::exists(filePath)){
        if(std::filesystem::is_directory(filePath)){
            int cnt=0;
            while(cnt<100){
                if(createUniversityFile())
                return 1;
                cnt++;
            }
            puts("university.dat文件创建失败，已尝试100次");
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        int cnt=0;
        while(cnt<100){
            if(createUniversityFile())
            return 1;
            cnt++;
        }
        puts("university.dat文件创建失败，已尝试100次");
        return 0;
    }
    return 0;
}

int createItemFile(){//成功返回1，否则返回0
    std::ofstream outfile("data/item.dat",std::ios::app);
    if(outfile.is_open()){
        outfile<<0<<std::endl;
        outfile.close();
        return 1;
    }
    else{
        outfile.close();
        return 0;
    }

}

int itemTest(){//成功返回1，否则返回0
    std::string filePath="data/item.dat";
    if(std::filesystem::exists(filePath)){
        if(std::filesystem::is_directory(filePath)){
            int cnt=0;
            while(cnt<100){
                if(createItemFile())
                return 1;
                cnt++;
            }
            puts("item.dat文件创建失败，已尝试100次");
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        int cnt=0;
        while(cnt<100){
            if(createItemFile())
            return 1;
            cnt++;
        }
        puts("item.dat文件创建失败，已尝试100次");
        return 0;
    }
    return 0;
}

int createScoreFile(){//成功返回1，否则返回0
    std::ofstream outfile("data/score.dat",std::ios::app);
    if(outfile.is_open()){
        outfile<<0<<std::endl;
        outfile.close();
        return 1;
    }
    else{
        outfile.close();
        return 0;
    }

}

int scoreTest(){//成功返回1，否则返回0
    std::string filePath="data/score.dat";
    if(std::filesystem::exists(filePath)){
        if(std::filesystem::is_directory(filePath)){
            int cnt=0;
            while(cnt<100){
                if(createScoreFile())
                return 1;
                cnt++;
            }
            puts("score.dat文件创建失败，已尝试100次");
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        int cnt=0;
        while(cnt<100){
            if(createScoreFile())
            return 1;
            cnt++;
        }
        puts("score.dat文件创建失败，已尝试100次");
        return 0;
    }
    return 0;
}

int registerInfoSubmit(std::string universityName,nameList newAthleteList){

    std::ifstream infile("data/university.dat");
    
    std::string university[101];

    nameList athleteList[101];

    int numUniversity=0;

    if(!infile.is_open()){
        return 0;
    }

    infile>>numUniversity;

    //std::cerr<<"numUniversity = "<<numUniversity<<"\n";

    for(int i=1;i<=numUniversity;i++){
        infile>>university[i];
        infile>>athleteList[i].numName;
        for(int j=1;j<=athleteList[i].numName;j++){
            infile>>athleteList[i].name[j]>>athleteList[i].age[j];
        }
    }

    infile.close();

    university[++numUniversity]=universityName;

    athleteList[numUniversity]=newAthleteList;

    //std::cerr<<"numUniversity = "<<numUniversity<<"\n";

    std::ofstream outfile("data/university.dat",std::ios::trunc);

    outfile<<numUniversity<<std::endl;

    for(int i=1;i<=numUniversity;i++){
        outfile<<university[i]<<std::endl;
        outfile<<athleteList[i].numName<<std::endl;
        for(int j=1;j<=athleteList[i].numName;j++){
            outfile<<athleteList[i].name[j]<<" "<<athleteList[i].age[j]<<std::endl;
        }
    }

    outfile.close();

    //puts("mark");
    //system("pause");

    return 0;
}



int matchInfoSubmit(match newMatch){
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

    matchList[++numMatch]=newMatch;

    std::ofstream outfile("data/item.dat",std::ios::trunc);

    outfile<<numMatch<<std::endl;

    for(int i=1;i<=numMatch;i++){
        outfile<<matchList[i].name<<std::endl;
        outfile<<matchList[i].numPlayer<<std::endl;
        for(int j=1;j<=matchList[i].numPlayer;j++){
            outfile<<matchList[i].athleteList[j].name<<" ";
            outfile<<matchList[i].athleteList[j].age<<" ";
            outfile<<matchList[i].athleteList[j].from<<std::endl;
        }
    }

    outfile.close();

}

