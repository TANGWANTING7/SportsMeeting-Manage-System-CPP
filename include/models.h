#pragma once

#include<string>

struct athlete{
    std::string name;
    int age;
    std::string from;
};

struct item{
    std::string name;
    int* weight;
    struct athlete* player;
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