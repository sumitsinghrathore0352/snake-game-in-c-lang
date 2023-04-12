#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
int width = 20, height = 20, gameOver, flag;
// vairable declare for initial position of snace and foo. score is also declare
int x, y, foodX,foodY, score;
//for movement of whole snake 
int tailX[100],tailY[100];
int countTail=0;
void board()
{ // this function is for making/settting boundries
    //  (height change by width value &width by height)
    int i, j,k;
    system("cls");
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("*");
                // printf("%d", i);
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("O");
                }
                else if (i == foodX && j == foodY)
                {
                    printf("@");
                }
                else
                {
                     int ch = 0; // to stop printing of o and blank space simultaneously
                    for(k=0;k<countTail;k++)//print O where i or j match only otherwise blank
                    {
                       if(i== tailX[k] && j==tailY[k])
                       {
                        printf("o");
                        ch =1;
                       }
                    }
                    if(ch==0)
                   {
                         printf(" ");
                   } 
                }
            }
        }
        printf("\n");
    }
}
void setup()
{
    gameOver = 0;
    x = width / 2;
    y = height / 2;
label1:
    foodX = rand() % 20;
    if (foodX == 0)
    {
        goto label1;
    }
label2:
    foodY = rand() % 20;
    if (foodY == 0)
    {
        goto label2;
    }
}
void input()
{
    if (kbhit())
    { 
        // making buttons to change direction of snske
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'z':
            flag = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}
void logic()
{
    int i;
    
     int prev2X ,prev2Y ;
    int prevX=tailX[0] ;//store value of previous x co-ordinate
    int prevY=tailY [0];//store value of previous y co-ordinate
    tailX[0]=x;
    tailY[0]=y;
    for(i=1;i<countTail;i++) // i< count because we have to move whole tail of snake 
    {
     prev2X=tailX[i];
     prev2Y=tailY[i];
     tailX[i]=prevX;
     tailY[i]=prevY;
     prevX=prev2X;
     prevY=prev2Y;
    }
    switch (flag)
    {
        // for change the position of snake
    case 1:
        y--;
    case 2:
        y++;
    case 3:
        x--;
    case 4:
        y++;
    default:
        break;
    }
    // if snake touch the boundry gmaeover
    if (x < 0 || x > width || y < 0 || y > height)
    {
        gameOver = 1;
        for(i=0;i<countTail;i++)
        {
            if(x==tailX[i] && y==tailY[i])
            {
                 gameOver = 1;
            }
        }
    }
    // code to regenerating food
    if (x == foodX && y == foodY)
    {
    
	lable3:
        foodX = rand() % 20;
        if (foodX == 0)
        {
            goto lable3;
        }
    label4:
        foodY = rand() % 20;
        if (foodY == 0)
        {
            goto label4;
        }
        score+= 10;
        countTail++; 
    }
}
int main()
{
     int m, n ;
     char c ;
     lable5:
    setup();
    // gmaeOver = 1, loop will run until the value is equal gameOver
    while (!gameOver)
    {
        board();
        input();
        logic();
        // to slow snake speed we have to slow executation speed
        for (m = 0; m < 10000; m++)
        {
            for (n = 0; n < 10000; n++)
            {
            }
        }
    }
    while(1){
         printf("\n ENTER Y TO PLAY AGAIN");
     scanf("%c",&c);
     if(c=='y'||c=='Y'){
          goto lable5;
     }
    return 0;
    }
}
