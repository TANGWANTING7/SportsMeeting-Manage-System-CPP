#pragma once

struct athlete{
    char name[20];
    int age;
    char from[20];
};

struct item{
    char name[20];
    int* weight;
    struct athlete* player;
};

struct university{
    char name[20];
    struct item *item;
    int score;
};