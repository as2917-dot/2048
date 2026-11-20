#include<raylib.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int  main()
{
InitWindow(600,600,"2048 GAME");
SetTargetFPS(60);
int i,j,rx,ry,val,flag=0,gflag=1,digits;
int board[4][4]={0};

srand(time(NULL));
rx=rand()%4;
ry=rand()%4;
board[rx][ry]=2;
rx=rand()%4;
ry=rand()%4;
board[rx][ry]=2;

while(!WindowShouldClose())
{
 
if(IsKeyPressed(KEY_DOWN))
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]!=0)
            {
                val=board[i][j];
                if(board[i][j+1]==0) {board[i][j+1]=val; board[i][j]=0;flag=1;}
                if(board[i][j]==board[i][j+1]) {board[i][j+1]=2*board[i][j];board[i][j]=0;flag=1;}
            }
        }
    }
}

if(IsKeyPressed(KEY_UP))
{
    for(i=3;i>=0;i--)
    {
        for(j=3;j>0;j--)
        {
            if(board[i][j]!=0)
            {
                val=board[i][j];
                if(board[i][j-1]==0) {board[i][j-1]=val; board[i][j]=0;flag=1;}
                if(board[i][j]==board[i][j-1]) {board[i][j-1]=2*board[i][j];board[i][j]=0;flag=1;}
            }
        }
    }
}

if(IsKeyPressed(KEY_RIGHT))
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(board[i][j]!=0)
            {
                val=board[i][j];
                if(board[i+1][j]==0) {board[i+1][j]=val; board[i][j]=0;flag=1;}
                if(board[i][j]==board[i+1][j]) {board[i+1][j]=2*board[i][j];board[i][j]=0;flag=1;}               
            }
        }
    }
}

if(IsKeyPressed(KEY_LEFT))
{
    for(i=3;i>0;i--)
    {
        for(j=3;j>=0;j--)
        {
            if(board[i][j]!=0)
            {
                val=board[i][j];
                if(board[i-1][j]==0) {board[i-1][j]=val; board[i][j]=0;flag=1;}
                if(board[i][j]==board[i-1][j]) {board[i-1][j]=2*board[i][j];board[i][j]=0;flag=1;}            
            }
        }
    }
}

if(flag==1)
{
   rx=rand()%4;
   ry=rand()%4;
   if(board[rx][ry]==0) {board[rx][ry]=2;flag=0;}
}

gflag=1;
for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    {
        if(board[i][j]==0) {gflag=0;break;}

        if(j<3 && board[i][j]==board[i][j+1]) {gflag=0;break;}
        if(i<3 && board[i][j]==board[i+1][j])     {gflag=0;break;}
    }
}

BeginDrawing();
ClearBackground(BLACK);
for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    {
        digits=(int)log10(board[i][j]);
        DrawRectangle(5+150*i,5+150*j,140,140,Color{180,150,120,255});
        if(board[i][j]!=0) {DrawRectangle(5+150*i,5+150*j,140,140,BEIGE); DrawText(TextFormat("%d",board[i][j]),50+150*i-6*digits,50+150*j,50,BLACK);}
    }
}

if(gflag==1) { DrawRectangle(0,0,600,600,Color{100,100,100,100}); DrawText("GAME OVER",90,250,70,RED);}

EndDrawing();    
}

}