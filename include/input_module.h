#pragma once
// 信息输入与报名函数声明

#include "models.h"

int inputFunc(int maxVal,int defaultKey);

std::string universityNameInput();

std::string itemNameInput();

std::string athleteNameInput();

int athleteAgeInput(int age);

void athleteDecider(nameList &athleteList);

void athleteAgeDecider(nameList &athleteList);

int athleteRegister();

void athleteListLoader(athletes &overall);

athlete athleteRegisterDecider();

void showAthleteList(match &newMatch);

int createItem();