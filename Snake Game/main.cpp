#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int i, y, pons[50], length = 3, tempo, j, f_PonsX, f_PonsY, movement, head_y=12, head_x=25;
int s_pons_X[200], s_pons_Y[200], tempo_x[200], tempo_y[200], game=1, score=0, wait=200, count=0;
char rc=187, hl=205, vl=186, lc=201, ldc=200, rdc=188, t=203, td=202, food=153, sn=254, key;

char snake[200];
void move();
void in_snake();
void pons_val();
void boder();
void food_pons();
void show_food();
void sn_dir();
void pause_play();
void game_play();
void sn_eat();
void check();
void start();

void gotoxy(int x, int y)
{
COORD p = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

//Setting up the 'pause' and 'play' menu
int main()
{
    boder();
    key=getch();
        Sleep(10);

    if(key=='p'|| key=='P')
    {
        start();
    }

    else
    {
        main();
    }
}

//Setting up the movement of the snake.
void move()
{
    if(movement==6)
    {
        gotoxy(s_pons_X[y],s_pons_Y[y]);
            cout<<snake[y];
    }
    if(movement==4)
    {
        gotoxy(s_pons_X[y],s_pons_Y[y]);
            cout<<snake[y];
    }
    if(movement==2)
    {
        gotoxy(s_pons_X[y],s_pons_Y[y]);
            cout<<snake[y];
    }
    if(movement==8)
    {
        gotoxy(s_pons_X[y],s_pons_Y[y]);
            cout<<snake[y];
    }
}

void pons_val()
{
    if(movement==6)
    {
    for(j=0;j<length;j++)
    {
        tempo_x[j]=s_pons_X[j];
        tempo_y[j]=s_pons_Y[j];
    }
    for(j=0;j-1<length;j++)
    {
        s_pons_X[j+1]=tempo_x[j];
        s_pons_Y[j+1]=tempo_y[j];
    }
        head_x=head_x+1;
        s_pons_X[0]=head_x;
    }
    if(movement==4)
    {
    for(j=0;j<length;j++)
    {
        tempo_x[j]=s_pons_X[j];
        tempo_y[j]=s_pons_Y[j];
    }
    for(j=0;j-1<length;j++)
    {
        s_pons_X[j+1]=tempo_x[j];
        s_pons_Y[j+1]=tempo_y[j];
    }
        head_x=head_x-1;
        s_pons_X[0]=head_x;
    }
    if(movement==2)
    {
    for(j=0;j<length;j++)
    {
        tempo_x[j]=s_pons_X[j];
        tempo_y[j]=s_pons_Y[j];
    }
    for(j=0;j-1<length;j++)
    {
        s_pons_X[j+1]=tempo_x[j];
        s_pons_Y[j+1]=tempo_y[j];
    }
        head_y=head_y+1;
        s_pons_Y[0]=head_y;
    }
    if(movement==8)
    {
    for(j=0;j<length;j++)
    {
        tempo_x[j]=s_pons_X[j];
        tempo_y[j]=s_pons_Y[j];
    }
    for(j=0;j-1<length;j++)
    {
        s_pons_X[j+1]=tempo_x[j];
        s_pons_Y[j+1]=tempo_y[j];
    }
        head_y=head_y-1;
        s_pons_Y[0]=head_y;
    }
}

// Display menu of the game.
void intro()
{
        gotoxy(54,4);
        cout<<"The Snake Game";
        gotoxy(54,8);
        cout<<"W : Up";
        gotoxy(54,9);
        cout<<"S : Down";
        gotoxy(54,10);
        cout<<"A : Left";
        gotoxy(54,11);
        cout<<"D : Right";
        gotoxy(54,12);
        cout<<"P : Play/Pause";

    if(score>0)
    {
        gotoxy(52,19);
        cout<<"Player's Score: "<<score;
    }
        gotoxy(55,24);
        cout<<"By Luis Espinosa";
}

//The borders of the game
void boder()
{
        intro();
        gotoxy(0,0);
        cout<<lc;
        gotoxy(1,0);
    for(i=0;i<=74;i++)
    {
        cout<<hl;
    }
        gotoxy(75,0);
        cout<<rc;
    for(i=1;i<=24;i++)
    {
        gotoxy(0,i);
        cout<<vl;
    }
        gotoxy(0,25);
        cout<<ldc;
        gotoxy(1,25);
    for(i=0;i<=74;i++)
    {
        cout<<hl;
    }
        gotoxy(75,25);
        cout<<rdc;
    for(i=1;i<=25;i++)
    {
        gotoxy(75,i);
        cout<<vl;
    }
        gotoxy(75,25);
        cout<<rdc;
        gotoxy(50,0);
        cout<<t;
    for(i=1;i<=25;i++)
    {
        gotoxy(50,i);
        cout<<vl;
    }
        gotoxy(50,25);
        cout<<td;
}

void food_pons()
{
        srand(time(0));
        f_PonsX=rand()%49+1;
        f_PonsY=rand()%24+1;
}

void show_food()
{
        gotoxy(f_PonsX,f_PonsY);
        cout<<food;
}

//The player's control options to play the game.
void sn_dir()
{
    switch(key)
    {
        case'W':
        case 'w': if(movement !=2)
        {
        movement=8;
        }
        break;

        case 'S':
        case 's': if(movement !=8)
        {
            movement=2;
        }
        break;

        case 'D':
        case 'd': if(movement !=4)
        {
            movement=6;
        }
        break;

        case 'A':
        case 'a': if(movement !=6)
        {
            movement=4;
        }
        break;
    }
}

void sn_eat()
{
    if(head_x==f_PonsX && head_y==f_PonsY)
    {
        length=length+1;
        s_pons_X[length-1]=s_pons_X[length-2];
        s_pons_Y[length-1]=s_pons_Y[length-2] - 1;
        snake[length-1]=sn;
        score=score+1;
        food_pons();
        count=count+1;
    }
}

void check()
{
    for(i=1;i<length;i++)
    {
        if(head_x==s_pons_X[i] && head_y==s_pons_Y[i])
        {
            game=0;
        }
    }
    if(head_x==0)
    {
        for(i=0;i<=25;i++)
    {
        if(head_y==i)
        {
            game=0;
        }
    }
    }

    if(head_x==50)
    {
        for(i=0;i<=25;i++)
    {
        if(head_y==i)
            {
            game=0;
            }
    }
    }

    if(head_y==0)
    {
        for(i=0;i<=50;i++)
        {
        if(head_x==i)
            {
            game=0;
            }
        }
    }
    if(head_y==25)
    {
        for(i=0;i<=50;i++)
        {
        if(head_x==i)
            {
            game=0;
            }
        }
    }
}

void in_snake()
{
        snake[0]=1;
        s_pons_X[0]=head_x;
        s_pons_Y[0]=head_y;
        for(i=1;i<length;i++)
    {
        snake[i]=sn;
        s_pons_X[i]=head_x-i;
        s_pons_Y[i]=head_y;
    }
}

//Game's system
void game_play()
{
        in_snake();
        food_pons();
        movement=6;
    while(game==1)
    {
        system("cls");
        if(kbhit())
    {
        key=getch();
        sn_dir();
    if(key=='p')
        {
            system("pause");
        }
    }
    if(count==5)
        {
        count=0;
    if(wait!=100)
        {
        wait=wait-10;
        }
        }
        show_food();
            boder();
    for(y=0;y<length;y++)
        {
        move();
        }
        check();
        sn_eat();
        pons_val();
        Sleep(wait);
    if(game==1)
        {
            system("cls");
        }
    }

    gotoxy(21,12);
        cout<<"GAME OVER";
    gotoxy(10,15);
        cout<<"Press Y to Play again or N to finish.";
    gotoxy(25,16);
        key=getch();
        cout<<key;

switch(key)
{
    case 'y':score=0;
    length=3;
    game=1;
    in_snake();
    system("cls");
    head_x=7;
    head_y=1;
    wait=200;
    movement=6;
    boder();
    game_play();
    break;

    default:system("cls");
        boder();
        gotoxy(15,12);
        cout<<"Thank you for playing!";
    break;
}
    gotoxy(0,26);
}

void start()
    {
        game_play();
    }
