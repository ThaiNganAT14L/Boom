#include "modul.h"

int table[10][10];
bool freeCell[10][10];

void taoDuLieu (int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			table[i][j] = 0;
			freeCell[i][j] = true;
		}
	}
}

void taoLinkList (){
	for (int i=0; i<9; i++){
		fl[i].next = &fl[i+1];
	}
	fl[9].next = 0;
}

void taoBom (){
	int x, y;
	for (int i=0; i<10; i++){
		fflush(stdin);
		x = rand()%10;
		fflush(stdin);
		y= rand()%10;
		if ( checkBoom(x,y,i) == 0)
		bom[i].taoBoom(x,y);
	}
}

bool openCell (int x, int y, int n){
	if (freeCell[x][y] == true and checkFlag(x,y,n) == 0){
		freeCell[x][y] = false;
		if(table[x][y] == 0){
			for (int i=-1; i<=1; i++){
				for (int j=-1; j<=1; j++){
					if (i == 0 and j==0)
						continue;
					else if ( x+i>=0 and x+i<10 and y+j>=0 and y+j<10 )
						openCell ( x+i, y+j, n );	
				}
			}
		}
		else if (table[x][y] == -1){
			return 0;
		}
		return 1;
	}
}

int flagOnBoom (int n){
	int count =0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (fl[i].xFlag == bom[j].xBoom and fl[i].yFlag == bom[j].yBoom){
				count++ ;
			}
		}
	}
	return count;	
}

int xoaFlag (int i){
	for (i; i<9; i++){
		fl[i] = *fl[i].next;
	}
	taoLinkList ();
}

void creatFlag (int x, int y, int n){
	fl[n].taoFlag (x,y);
}

void creatTable (){
	for (int z=0; z<10; z++){
		for (int i=-1; i<=1; i++){
			for (int j=-1; j<=1; j++){
				if (bom[z].xBoom+i >= 0 and bom[z].xBoom+i < 10 and bom[z].yBoom+j >= 0 and bom[z].yBoom+j < 10){
					if (i == 0 and j==0)
						table[bom[z].xBoom+i][bom[z].yBoom+j] =-1;
					if (table[bom[z].xBoom+i][bom[z].yBoom+j] != -1)	
						table[bom[z].xBoom+i][bom[z].yBoom+j] ++;	
				}
			}
		}
	}
}

int checkCell (int x, int y, int n){
	if( freeCell[x][y] == true){
		if (checkFlag(x,y,n) != 0){
			return -1;
		}
		return -3;
	}
	else {
		if (checkBoom(x,y)==true){
			return -2;
		}
		else if (table[x][y] >= 0 ){
			return table[x][y];
		}
	}
}

bool checkBoom (int x, int y, int n){
	for (int i=0; i<n; i++){
		if (bom[i].xBoom == x and bom[i].yBoom == y )
			return 1;
	}
	return 0;
}
int checkFlag (int x, int y, int n){
	for (int i=0; i<n; i++){
		if (fl[i].xFlag == x and fl[i].yFlag == y )
			return i+1;
	}
	return 0;
}

void lose(){
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			freeCell[i][j] = false;
		}
	}
}
