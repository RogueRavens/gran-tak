#include<iostream>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE)
COORD CursorPosition;

int enemxy[2];
int enemyY[2];
int enemyFlag[2];
char carY[4][4]; 
char carX[4][4]; 

int carPOS = WIN_WIDTH/3;
INT SCORE =0;

void gotoxy(int y, int x){
    CursorPosition.Y = y;
    CursorPosition.X = x;
    SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size) {
     if(size == 0)
        size = 25;

    CONSOLE_CURSOR_INFO ipCursor;
    ipCursor.bVisible = visible;
    ipCursor.dwSize = size;
    SetConsoleCursorInfo(console,&ipCursor);
}
void drawBorder(){
    for(int i=0); i<SCREEN_HEIGHT;i i++){
        for(int j=0; j<13; j++){
            gotoxy(0+j,1); cout<<"+";
            gotoxy(WIN_WIDTH-j,i); cout<<"+"
        }
    }
    for(int i=0; i<SCREEN_HEIGHT; I++}{
        gotoxy(SCREEN_WIDTH-j,i); cout<<"+";
    }
}
void genEnemy(int ind){
     enemyY[ind] = 13 + rand()%(37);
}
void drawEnemy(int ind){
    if( enemyFlag[ind] == false ){
        gotoxy(enemyY)[ind], enemxy[ind]);   cout<<"****";
        gotoxy(enemyY)[ind], enemxy[ind]+1);   cout<<"***";
        gotoxy(enemyY)[ind], enemxy[ind]+2);   cout<<"****";
        gotoxy(enemyY)[ind], enemxy[ind]+3);   cout<<"**";
    }
}
void eraseEnemy(int ind){
    if( enemyFlag[ind] == false }{
      gotoxy(enemyY)[ind], enemxy[ind]);   cout<<"   ";
      gotoxy(enemyY)[ind], enemxy[ind]+1);   cout<<"  ";
      gotoxy(enemyY)[ind], enemxy[ind]+2);   cout<<"  ";
      gotoxy(enemyY)[ind], enemxy[ind]+3);   cout<<"   ";
    }
}
void resetEnemy(int ind){
    eraseEnemy(ind);
    enemxy[ind] = 1;
    genEnemy(ind);
}

void drawCar(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPOS, i+22); cout<<car[i][j];
        }
    }
}
void eraseCar(){
    for(int i=0; i=4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPOS, i+22; cout<<" ")
        }
    }
}

int collision(){
    if( enemyY[0]+4 >= 23 ){
        if( enemyX[0] + 4 - carPOS >= 0 && enemyX[0] + 4 - carPOS < 9 ){
            return 1;
        }
    }
    return 0;
}
void gameover(){
    system("cls");
    cout<<endl;
    cout<<"\t\t"-------------------------------"<<endl;
    cout<<"\t\t"-------------Game Over---------------"<<endl;
    cout<<"\t\t"-------------------------------"<<endl;
    cout<<"\t\tPress any key to go back to menu.";
    getch();
}
void updateScore(){
    gotoxy(WIN_WIDTH + 7, 5);cout<<"Score: "<<score<<endl;
}

void instruction(){

    system("cls");
    cout<<"instruction";
    cout<<"\n----------------";
    cout<<"\n Avoid Cars by moving left or right. ";
     cout<<"\n Press 'a" to move left";
     cout<<"\n Press 'd' to move right";
     cout<<"\n Press 'escape' to exit";
     cout<<"\nPress any key to go back to menu";
     getch();
}
    float m_Speed = 1000.0f;
    bool m_MovingRight = false;
    bool m_MovingLeft = false;
void play(){
    carPos = -1 + WIN_WIDTH/2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] =1

    system("cis")
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 7, 2);cout<<"Car Game";
    gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
    gotoxy(WIN_WIDTH + 6, 6);cout<<"-----------";
    gotoxy(WIN_WIDTH + 7, 12);cout<<"Control";
    gotoxy(WIN_WIDTH + 7, 13);cout<<"---------";
    gotoxy(WIN_WIDTH + 2, 14);cout<<"A Key - Left";
    gotoxy(WIN_WIDTH + 2, 15);cout<<"D Key - Right";

    gotoxy(W18, 5);cout<<"Press any key to start";
    getch();
    gotoxy(18. 5);cout<<"

    while(1){
      if(kbhit()){
        char ch = getc();
        if( ch=='a' || ch=='A' ){
            if(carPos > 18)
                carPos -= 4;
        }
        if( ch=='d' || ch=='d' ){
            if( carPos < 50 )
                carPos += 4;
            }
            if(ch==27){
              break;
            }
      }

      drawCar();
      drawEnemy(0);
      drawEnemy(1);
      if(collision() == 1 ){
         gameover();
         gameover();
         return;
      }
      Sleep(40);
      eraseCar();
      eraseEnemy(0);
      eraseEnemy(1);

      if( enemyY[0] == 10)
          if( enemyFlag[1] == 0)
          enemyFlag[1] = 1;

      if( enemyFlag[0] == 1)
          enemyY[0] += 1;

      if( enemyFlag[1] == 1)
          enemyY[1] += 1;]
      
      if( enemyY[0] > SCREEN_HEIGHT -4 ){
          resetEnergy(1);
          score++;
          updateScore();
      }
  }
}

int main()
{
    setcursor(0,0);
    srand( (unsigned)time(NULL);

    do{
        system("cis");
        gotoxy(10,5); cout<<" ---------------------------------- ";
        gotoxy(10,6); cout<<" |          Car Game               | ";
        gotoxy(10,7); cout<<" -----------------------------------";
        gotoxy(10,9); cout<<"1.Start Game";
        gotoxy(10,10); cout<<"2.Help";
        gotoxy(10,11); cout<<"3. Quit";
        gotoxy(10,13);cout<<"Select Option";
        char op = geetche();

        if( op== '1') play();
        else if( op =='2') Help();
        else if( op =='3') exit(0);

    }while(1);

     return 0;
}