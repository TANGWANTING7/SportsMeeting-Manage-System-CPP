#include <windows.h>

#include "input_module.h"

#include "utils.h"

#include "models.h"

#include<iostream>

#include<cstdio>

#include<conio.h>

#include<iomanip>

#include<fstream>

int inputFunc(int maxVal,int defaultKey){
    int key=defaultKey;
    
    system("cls");
    
    puts("请通过'W'、'S'键选择数字，通过回车键确定你要选的数字");
    
    for(int i=key-1;i<=key+1;i++){
        if(key==i){
            printf(" -> %d\n",i);
        }
        else{
            printf("    %d\n",i);
        }
    }
    
    while(true){
        char ch=getch();
        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }
        if(ch=='S'||ch=='s'){
            key++;
            if(key>maxVal){
                key=maxVal;
            }
        }
        if(ch=='\r'||ch=='\n'){
            return key;
        }
        system("cls");
        puts("请通过'W'、'S'键选择数字，通过回车键确定你要选的数字");
        for(int i=key-1;i<=key+1;i++){
            if(key==i){
                printf(" -> %d\n",i);
            }
            else{
                printf("    %d\n",i);
            }
        }
    }
}


std::string universityNameInput(){
    std::string name;

    system("cls");

    puts("请在下方输入学校名称，确认后回车");

    std::cin>>name;

    return name;
}

std::string itemNameInput(){
    std::string name;

    system("cls");

    puts("请在下方输入项目名称，确认后回车");

    std::cin>>name;

    return name;
}

std::string athleteNameInput(){
    std::string name;

    system("cls");

    puts("请在下方输入运动员姓名，确认后回车");

    std::cin>>name;

    return name;
}

int athleteAgeInput(int age){
    return inputFunc(100,age);
}

void athleteDecider(nameList &athleteList){
    int numPlayer=athleteList.numName;

    int key=1;

    system("cls");

    printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员姓名，按'Q'键退出编辑页面\n",numPlayer);

    if(key==1){
        for(int i=1;i<=3;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
        }
    }
    else if(key==numPlayer){
        for(int i=key-2;i<=key;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
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
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
        }
    }

    while(true){
        char ch=getch();

        system("cls");

        //printf("key=%d\n",key);

        printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员姓名，按'Q'键退出编辑页面\n",numPlayer);

        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }

        if(ch=='S'||ch=='s'){
            key++;
            if(key>numPlayer){
                key=numPlayer;
            }
        }

        if(ch=='\r'||ch=='\n'){
            athleteList.name[key]=athleteNameInput();
            system("cls");
            printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员姓名，按'Q'键退出编辑页面\n",numPlayer);
        }

        if(ch=='Q'||ch=='q'){
            return;
        }

        if(key==1){
            for(int i=1;i<=3;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
            }
        }
        else if(key==numPlayer){
            for(int i=key-2;i<=key;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
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
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
            }
        }
    }
}

void athleteAgeDecider(nameList &athleteList){
    int numPlayer=athleteList.numName;

    int key=1;

    system("cls");

    printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员姓名，按'Q'键退出编辑页面\n",numPlayer);

    if(key==1){
        for(int i=1;i<=3;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
        }
    }
    else if(key==numPlayer){
        for(int i=key-2;i<=key;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
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
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
        }
    }

    while(true){
        char ch=getch();

        system("cls");

        //printf("key=%d\n",key);

        printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员年龄，按'Q'键退出编辑页面\n",numPlayer);

        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }

        if(ch=='S'||ch=='s'){
            key++;
            if(key>numPlayer){
                key=numPlayer;
            }
        }

        if(ch=='\r'||ch=='\n'){
            athleteList.age[key]=athleteAgeInput(athleteList.age[key]);
            system("cls");
            printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员年龄，按'Q'键退出编辑页面\n",numPlayer);
        }

        if(ch=='Q'||ch=='q'){
            return;
        }

        if(key==1){
            for(int i=1;i<=3;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
            }
        }
        else if(key==numPlayer){
            for(int i=key-2;i<=key;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
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
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<athleteList.name[i]<<"  年龄："<<athleteList.age[i]<<std::endl;
            }
        }
    }
}

int athleteRegister(){
    std::string universityName="NULL";
    
    int numPlayer=1;
    
    std::string athleteName[101];
    
    std::string opt[10];

    nameList athleteList;

    athleteList.numName=numPlayer;

    opt[1]="填写学校名称";
    opt[2]="选择运动员人数";
    opt[3]="填写运动员名称";
    opt[4]="填写运动员年龄";
    opt[5]="提交报表";

    //system("pause");

    std::cout<<"当前学校名称为："<<universityName<<"     "<<"运动员人数为："<<numPlayer<<std::endl<<std::endl;

    int key=1;

    puts("通过'W'、'S'键移动光标、按回车键选择\n");
    for(int i=1;i<=5;i++){
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
        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }
        if(ch=='S'||ch=='s'){
            key++;
            if(key>5){
                key=5;
            }
        }
        if(ch=='\r'||ch=='\n'){
            if(key==1){
                universityName=universityNameInput();
            }
            else if(key==2){
                numPlayer=inputFunc(100,1);
                athleteList.numName=numPlayer;
            }
            else if(key==3){
                athleteDecider(athleteList);
            }
            else if(key==4){
                athleteAgeDecider(athleteList);
            }
            else if(key==5){//提交报表
                if(universityName=="NULL"){
                    puts("学校名称不能为空");
                    continue;
                }
                registerInfoSubmit(universityName,athleteList);
                return 0;
            }
        }

        system("cls");

        std::cout<<"当前学校名称为："<<universityName<<"     "<<"运动员人数为："<<numPlayer<<std::endl<<std::endl;


        puts("通过'W'、'S'键移动光标、按回车键选择\n");
        for(int i=1;i<=5;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<opt[i]<<std::endl;
        }
    }

    return 0;
}

void athleteListLoader(athletes &overall){
    std::ifstream infile("data/university.dat");

    overall.numAthlete=0;

    if(!infile.is_open()){
        return;
    }

    int numAthlete=0;

    int numUniversity=0;

    infile>>numUniversity;

    std::string nowUniversity;

    int nowNumPlayer=0;

    for(int i=1;i<=numUniversity;i++){
        infile>>nowUniversity;
        infile>>nowNumPlayer;
        for(int j=1;j<=nowNumPlayer;j++){
            overall.numAthlete++;
            infile>>overall.athleteList[overall.numAthlete].name;
            infile>>overall.athleteList[overall.numAthlete].age;
            overall.athleteList[overall.numAthlete].from=nowUniversity;
        }
    }

    infile.close();

    return;

}

athlete athleteRegisterDecider(){
    athletes overall;

    athleteListLoader(overall);

    int key=1;

    int maxVal=overall.numAthlete;

    int numPlayer=overall.numAthlete;

    system("cls");

    printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员\n",numPlayer);

    if(key==1){
        for(int i=1;i<=3;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<overall.athleteList[i].name<<"  年龄："<<std::setw(10)<<overall.athleteList[i].age<<"  学校："<<overall.athleteList[i].from<<std::endl;
        }
    }
    else if(key==numPlayer){
        for(int i=key-2;i<=key;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<overall.athleteList[i].name<<"  年龄："<<std::setw(10)<<overall.athleteList[i].age<<"  学校："<<overall.athleteList[i].from<<std::endl;
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
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<overall.athleteList[i].name<<"  年龄："<<std::setw(10)<<overall.athleteList[i].age<<"  学校："<<overall.athleteList[i].from<<std::endl;
        }
    }

    while(true){
        char ch=getch();

        system("cls");

        //printf("key=%d\n",key);

        printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键选择运动员\n",numPlayer);

        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }

        if(ch=='S'||ch=='s'){
            key++;
            if(key>numPlayer){
                key=numPlayer;
            }
        }

        if(ch=='\r'||ch=='\n'){
            system("cls");
            return overall.athleteList[key];
        }


        if(key==1){
            for(int i=1;i<=3;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<overall.athleteList[i].name<<"  年龄："<<std::setw(10)<<overall.athleteList[i].age<<"  学校："<<overall.athleteList[i].from<<std::endl;
            }
        }
        else if(key==numPlayer){
            for(int i=key-2;i<=key;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<overall.athleteList[i].name<<"  年龄："<<std::setw(10)<<overall.athleteList[i].age<<"  学校："<<overall.athleteList[i].from<<std::endl;
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
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<overall.athleteList[i].name<<"  年龄："<<std::setw(10)<<overall.athleteList[i].age<<"  学校："<<overall.athleteList[i].from<<std::endl;
            }
        }
    }
}

void showAthleteList(match &newMatch){
    int numPlayer=newMatch.numPlayer;

    int key=1;

    system("cls");

    printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键更改运动员姓名，按'Q'键退出编辑页面\n",numPlayer);

    if(key==1){
        for(int i=1;i<=3;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<newMatch.athleteList[i].name<<"  年龄："<<std::setw(10)<<newMatch.athleteList[i].age<<"  学校："<<newMatch.athleteList[i].from<<std::endl;
        }
    }
    else if(key==numPlayer){
        for(int i=key-2;i<=key;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<newMatch.athleteList[i].name<<"  年龄："<<std::setw(10)<<newMatch.athleteList[i].age<<"  学校："<<newMatch.athleteList[i].from<<std::endl;
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
            std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<newMatch.athleteList[i].name<<"  年龄："<<std::setw(10)<<newMatch.athleteList[i].age<<"  学校："<<newMatch.athleteList[i].from<<std::endl;
        }
    }

    while(true){
        char ch=getch();

        system("cls");

        //printf("key=%d\n",key);

        printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键填入运动员，按'Q'键退出编辑页面\n",numPlayer);

        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }

        if(ch=='S'||ch=='s'){
            key++;
            if(key>numPlayer){
                key=numPlayer;
            }
        }

        if(ch=='\r'||ch=='\n'){
            newMatch.athleteList[key]=athleteRegisterDecider();
            system("cls");
            printf("共有以下%d位运动员及其名字，请通过'W'、'S'选择运动员，并通过回车键填入运动员，按'Q'键退出编辑页面\n",numPlayer);
        }

        if(ch=='Q'||ch=='q'){
            return;
        }

        if(key==1){
            for(int i=1;i<=3;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<newMatch.athleteList[i].name<<"  年龄："<<std::setw(10)<<newMatch.athleteList[i].age<<"  学校："<<newMatch.athleteList[i].from<<std::endl;
            }
        }
        else if(key==numPlayer){
            for(int i=key-2;i<=key;i++){
                if(key==i){
                    std::cout<<" -> ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<newMatch.athleteList[i].name<<"  年龄："<<std::setw(10)<<newMatch.athleteList[i].age<<"  学校："<<newMatch.athleteList[i].from<<std::endl;
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
                std::cout<<"运动员 "<<i<<" 姓名："<<std::setw(10)<<newMatch.athleteList[i].name<<"  年龄："<<std::setw(10)<<newMatch.athleteList[i].age<<"  学校："<<newMatch.athleteList[i].from<<std::endl;
            }
        }
    }
}

int createItem(){
    std::string itemName="NULL";

    int numPlayer=1;
    
    std::string opt[6];

    athlete athleteList[1001];

    match newMatch;

    newMatch.numPlayer=numPlayer;

    opt[1]="填写项目名称";
    opt[2]="选择运动员人数";
    opt[3]="填写参赛运动员";
    opt[4]="提交报表";

    //system("pause");

    std::cout<<"当前项目名称为："<<itemName<<"     "<<"运动员人数为："<<numPlayer<<std::endl<<std::endl;

    int key=1;

    puts("通过'W'、'S'键移动光标、按回车键选择\n");
    for(int i=1;i<=4;i++){
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
        if(ch=='W'||ch=='w'){
            key--;
            if(!key){
                key=1;
            }
        }
        if(ch=='S'||ch=='s'){
            key++;
            if(key>4){
                key=4;
            }
        }
        if(ch=='\r'||ch=='\n'){
            if(key==1){
                itemName=itemNameInput();
                newMatch.name=itemName;
            }
            else if(key==2){
                numPlayer=inputFunc(100,1);
                newMatch.numPlayer=numPlayer;
            }
            else if(key==3){
                showAthleteList(newMatch);
            }
            else if(key==4){//提交报表
                if(itemName=="NULL"){
                    puts("项目名称不能为空");
                    continue;
                }
                matchInfoSubmit(newMatch);
                return 0;
            }
        }

        system("cls");

        std::cout<<"当前项目名称为："<<itemName<<"     "<<"运动员人数为："<<numPlayer<<std::endl<<std::endl;


        puts("通过'W'、'S'键移动光标、按回车键选择\n");
        for(int i=1;i<=5;i++){
            if(key==i){
                std::cout<<" -> ";
            }
            else{
                std::cout<<"    ";
            }
            std::cout<<opt[i]<<std::endl;
        }
    }

    return 0;

}

