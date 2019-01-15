#include "View.cpp"
#include "modul.cpp"

void dieuKhien();
void printTable(int n);

int main(){
	srand(time(NULL)); 
	VeKhung();
	taoDuLieu();
	taoBom ();
	taoLinkList ();
	creatTable();
	dieuKhien();
	getch();
}
void dieuKhien(){
	int countFlag = 0, x=0, y=0, l=0;
	char key;
	point(0,0,-3);
	while (l==0){
		key = getch();
		printCell (x,y,checkCell(x,y,countFlag));
		switch (key){
			//qua Trai
			case '4':{
				if (x >= 1){
					x -= 1;
				}
				break;
			}
			// Xuong
			case '5':{
				if (y < 9){
					y += 1;
				}	
				break;
			}
			// qua Phai
			case '6':{
				if (x < 9 ){
					x += 1;
				}
				break;
			}
			//Len
			case '8':{
				if (y >= 1){
					y -= 1;
				}
				break;
			}	
			case 'g':{
				if (freeCell[x][y] == true and checkFlag(x,y,countFlag) == 0){
					if (openCell(x,y,countFlag) == 0){
						lose();
						endGame ("YOU ARE LOSER. GOOD LUCK AGAIN!!!");
						l=1;
					}
				printTable(countFlag);
				}
				break;
			}
			case 'f':{
				if( checkFlag(x,y,countFlag) == 0){
					if (countFlag <10){
						creatFlag(x,y,countFlag);
						countFlag++;
					}
					if (countFlag == 10 and flagOnBoom(countFlag) == 10 ){
						lose();
						endGame ("YOU ARE WINNER");
						l=1;						
					}
				}
				else {
					xoaFlag(checkFlag(x,y,countFlag)-1);
					countFlag--;
				}
				break;
			}
		}
		point(x,y,checkCell(x,y,countFlag));
	}
}
void printTable(int n){
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			printCell (i,j,checkCell(i,j,n));
		}
	}
}
