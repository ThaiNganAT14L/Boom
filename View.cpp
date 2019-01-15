#include "View.h"

void VeKhung (int n, int m){
	system("cls");
	textcolor (240);
	//Dau
	cout << char (201);
	for (int i=1; i<4*n; i++){
		if (i%4 == 0){
			cout << char (209);
		}
		else {
			cout << char (205);
		}
	}
	cout << char (187) << endl;
	//Than
	for (int i=1; i<2*m; i++){
		if (i%2 == 0){
			cout << char (199);
			for (int i=1; i<4*n; i++){
				if (i%4 == 0){
					cout << char (197);
				}
				else {
					cout << char (196);
				}
			}
			cout << char (182) << endl;
		}
		else {
			cout << char (186);
			for (int i=1; i<4*n; i++){
				if (i%4 == 0){
					cout << char (179);
				}
				else {
					cout << " ";
				}
			}		
			cout << char (186) << endl;
		}
	}
	// cuoi
	cout << char (200);
	for (int i=1; i<4*n; i++){
		if (i%4 == 0){
			cout << char (207);
		}
		else {
			cout << char (205);
		}
	}
	cout << char (188);
	gotoxy(42, 3);
	cout << "CACH CHOI: ";	
	gotoxy(42, 4);
	cout << "Phim 4,5,6,8: Di chuyen.";
	gotoxy(42, 5);
	cout << "Phim F: Dat Flag.";
	gotoxy(42, 6);
	cout << "Phim G: Mo o.";
}
void textcolor(int x){
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x,int y){  
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void point (int x, int y, int values){
	textcolor (158);
	gotoxy (chuyenX (x), chuyenY (y));
	switch (values){
		case -3:{
			textcolor (160);
			cout << "   ";
			break;
		}
		case -2:{
			cout << " B ";
			break;
		}
		case -1:{
			cout << " F ";
			break;
		}
		case 0:{
			cout << "   ";
			break;
		}
		default:{
			cout << " "<< values <<" ";
			break;
		}
	}
	gotoxy(1, 23);
}
int chuyenX (int x){
	return 4*x+2;
}
int chuyenY (int y){
	return 2*y+2;
}
void endGame (string data){
	textcolor (206);
	gotoxy ( 42, 1 );
	cout << data;
	getch();
}
void printCell (int x, int y, int values){
	gotoxy (chuyenX (x), chuyenY (y));
	switch (values){
		case -3:{
			textcolor (240);
			cout << "   ";
			break;
		}
		case -2:{
			textcolor (192);
			cout << " B ";
			break;
		}
		case -1:{
			textcolor (172);
			cout << " F ";
			break;
		}
		case 0:{
			textcolor (12);
			cout << "   ";
			break;
		}
		default:{
			textcolor ( 16-values );
			cout << " "<< values <<" ";
			break;
		}
	}
}
