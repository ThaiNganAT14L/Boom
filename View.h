#ifndef View_h
#define View_h
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

void VeKhung (int n =10, int m =10);
void textcolor(int x);
void gotoxy(int x,int y);
int chuyenX (int x);
int chuyenY (int y);
void point (int x, int y, int values);
void endGame (string data);
void printCell (int x, int y, int values);
#endif
