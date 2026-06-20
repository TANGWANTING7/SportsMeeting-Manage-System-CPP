#pragma once

#include<string>

struct athlete{
    std::string name;
    int age;
    std::string from;
    athlete(){
        name="ÔÝÎÞ";
        age=0;
        from="ÔÝÎÞ";
    }
};

struct university{
    std::string name;
    struct item *item;
    int score;
};

struct nameList{
    int numName;
    int age[101];
    std::string name[101];
    nameList(){
        memset(age,0,sizeof(age));
    }
};

struct athletes{
    int numAthlete;
    athlete athleteList[1001];
    athletes(){
        numAthlete=0;
    }
};

struct match{
    int numPlayer;
    std::string name;
    athlete athleteList[101];
    int score[101];
    match(){
        numPlayer=0;
        memset(score,0,sizeof(score));
    }
};
