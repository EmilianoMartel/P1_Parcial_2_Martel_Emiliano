#pragma once
#include "AwesomeLibrary.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

extern const char* TITLE_ART;
const int X_COORDINATE_INIT = 1;
const int Y_COORDINATE_INIT = 1;
const int X_COORDINATE_FINAL = 100;
const int Y_COORDINATE_FINAL = 25;

int drawTitle();

bool intCheacker(string input);

bool floatCheacker(string input);

int questionWithIntReturn(string question, int x, int y);

float quiestionWithFloatReturn(string question, int x, int y);

bool questionWithBoolReturn(string question, int x, int y);

void printData(string& lines, int x, int* startY);