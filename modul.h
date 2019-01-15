#ifndef modul_h
#define modul_h
#include<iostream>
#include<time.h>
#include <stdlib.h>

using namespace std;

void lose();
void taoDuLieu (int n=10, int m=10);
void taoLinkList ();
void taoBom ();
bool openCell (int x, int y, int n);
int checkCell (int x, int y,int n);
bool checkBoom (int x, int y, int n=10);
int checkFlag (int x, int y, int n);

class flag {
	public:
		int xFlag, yFlag ;
		flag * next;
		void taoFlag (int x, int y){
			xFlag = x;
			yFlag = y;
		} 
}fl[10];

class boom {
	public:
		int xBoom, yBoom;
		void taoBoom (int x, int y){
			xBoom = x;
			yBoom = y;
		} 
}bom[10];
#endif
