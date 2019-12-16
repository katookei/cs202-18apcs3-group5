#pragma once
#include<iostream>
#include<thread>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<vector>
#include<mutex>
#define TOP 4
#define BOTTOM 28
#define LEFT 2
#define RIGHT 116
#define LINE1 7
#define LINE2 13
#define LINE3 19
#define LINE4 25

using namespace std;

void gotoXY(int, int);
void fixConsoleWindow();
//mutex g_i_mutex;