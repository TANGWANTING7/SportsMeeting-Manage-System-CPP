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
    int nameNum;
    std::string name[101];
};