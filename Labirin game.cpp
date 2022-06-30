#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

struct karakter
{
    int posX;
    int posY;
    char simbol;
    int hp;
}player;

struct musuh
{
    int posX;
    int posY;
    char musuh_simbol;
};

void player_hit()
{
    player.posX = 1;
    player.posY = 1;
    player.hp --;
}
int main()
{
    musuh musuh_horizontal = {5,6,'H'};
    musuh musuh_vertical = {6,8,'V'};
    musuh musuh_jump = {1,3,'J'};

    const char HEIGHT = 10, WIDTH = 10;
    bool update = false;
    char move_key = 'd';

    player.posX = 1;
    player.posY = 1;
    player.simbol = 'O';

    player.hp = 3;

    unsigned char labirin[WIDTH][HEIGHT] =
    {
        '#','#','#','#','#','#','#','#',' ',' ',
        '#',' ',' ',' ',' ',' ','#','#',' ',' ',
        '#',' ','#',' ','#','#','#','#',' ',' ',
        '#',' ',' ',' ',' ','#','#','#',' ','#',
        '#',' ','#','#',' ','#',' ','#',' ','#',
        '#',' ','#','#',' ','#',' ','#',' ','#',
        '#',' ','#',' ',' ',' ',' ','#',' ','#',
        '#','#','#',' ','#','#',' ','#',' ','#',
        '#','#',' ',' ','#',' ',' ',' ',' ','#',
        '#','#','#','#','#','#','#','#','#','#',
    };
    cout<<"press(d), (w), (a), or (s) and then return to start the game\n";
    cout<<"press(q) then return to quit the game\n";

    while (move_key !='q')
    {
        srand(time(NULL));
        int random_move = rand()%2+1;

        cin>>move_key;
        update = true;

        if (update == true)
        {
            system("CLS");

            labirin[musuh_horizontal.posX][musuh_horizontal.posY]=musuh_horizontal.musuh_simbol;
            labirin[musuh_vertical.posX][musuh_vertical.posY]=musuh_vertical.musuh_simbol;
            labirin[musuh_jump.posX][musuh_jump.posY]=musuh_jump.musuh_simbol;

            labirin[player.posX][player.posY]=player.simbol;

            for (int y=0;y<HEIGHT;y++)
            {
                cout<<endl;
                for (int x=0;x<WIDTH;x++)
                {
                    cout<<labirin[x][y];
                }
            }
            cout<<endl<<endl<<"   health : "<<player.hp<<endl<<"_____________\n \n";
            update = false;
        }
        switch (move_key)
        {
            case'w':
                update = true;
            if  (labirin[player.posX][player.posY+1]!= '#')
            {
                labirin[player.posX][player.posY]= ' ';
                player.posY --;

                if (labirin[player.posX][player.posY]==labirin[musuh_horizontal.posX][musuh_horizontal.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_vertical.posX][musuh_vertical.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_jump.posX][musuh_jump.posY])
                {
                    player_hit();
                }
                cout<<player.posX<<" "<<player.posY<<endl;
            }
            else
                cout<<"you hit a wall";
                break;

            case 's':
                update = true;
            if (labirin[player.posX][player.posY+1]!= '#')
            {
                labirin[player.posX][player.posY]= ' ';
                player.posY ++;

                if (labirin[player.posX][player.posY]==labirin[musuh_horizontal.posX][musuh_horizontal.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_vertical.posX][musuh_vertical.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_jump.posX][musuh_jump.posY])
                {
                    player_hit();
                }
                 cout<<player.posX<<" "<<player.posY<<endl;
            }
            else
                cout<<"you hit a wall";
                break;

            case 'a':
                update = true;
            if (labirin[player.posX][player.posY+1]!= '#')
            {
                labirin[player.posX][player.posY]= ' ';
                player.posY ++;

                if (labirin[player.posX][player.posY]==labirin[musuh_horizontal.posX][musuh_horizontal.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_vertical.posX][musuh_vertical.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_jump.posX][musuh_jump.posY])
                {
                    player_hit();
                }
                 cout<<player.posX<<" "<<player.posY<<endl;
            }
            else
                cout<<"you hit a wall";
                break;

            case 'd':
                update = true;
            if (labirin[player.posX][player.posY+1]!= '#')
            {
                labirin[player.posX][player.posY]= ' ';
                player.posY ++;

                if (labirin[player.posX][player.posY]==labirin[musuh_horizontal.posX][musuh_horizontal.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_vertical.posX][musuh_vertical.posY]||
                    labirin[player.posX][player.posY]==labirin[musuh_jump.posX][musuh_jump.posY])
                {
                    player_hit();
                }
                 cout<<player.posX<<" "<<player.posY<<endl;
            }
            else
                cout<<"you hit a wall";
                break;
        }
            switch (random_move)
            {
            case 1:

                if (labirin[musuh_horizontal.posX+1][musuh_horizontal.posY]!= '#')
                {
                    labirin[musuh_horizontal.posX][musuh_horizontal.posY]= ' ';
                    musuh_horizontal.posX ++;
                }
                break;

            case 2:
                if (labirin[musuh_horizontal.posX-1][musuh_horizontal.posY]!= '#')
                {
                    labirin[musuh_horizontal.posX][musuh_horizontal.posY]= ' ';
                    musuh_horizontal.posX --;
                }
                break;
            }
                if (labirin[musuh_vertical.posX][musuh_vertical.posY+1]!= '#')
                {
                     labirin[musuh_vertical.posX][musuh_vertical.posY]= ' ';
                     musuh_vertical.posX ++;
                }
                else if (labirin[musuh_vertical.posX][musuh_vertical.posY-5]!= '#')
                {
                     labirin[musuh_vertical.posX][musuh_vertical.posY]= ' ';
                     musuh_vertical.posX -=6;
                }
                if (labirin[musuh_jump.posX+2][musuh_jump.posY]!= '#')
                {
                    labirin[musuh_jump.posX][musuh_jump.posY]= ' ';
                    musuh_jump.posX +-2;
                }
                else if (labirin[musuh_jump.posX-14][musuh_jump.posY]!= '#')
                {
                    labirin[musuh_jump.posX][musuh_jump.posY]= ' ';
                    musuh_jump.posX -=14;
                }
                if (player.hp==0)
                {
                    move_key = 'q';
                    cout<<"you have lost the game \n";
                }
                if (player.posY==17)
                {
                    cout<<"\n congrats!!!You have won the game \n";
                }

    }
    return 0;
}
