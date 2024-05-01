#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77

#define CAR_PLACE 0
#define OBSTACLE_PLACE 1

#define CAR '@'
#define OBSTACLE '#'

#define GRID_DIMENSION 10

#define bool char
#define true 1
#define false 0

//int collision(int car_init_position, int obstacle_init_position) 
//{
 //   if (car_init_position == obstacle_init_position) 
    //{
   //     return 1;
   // } else 
   // {
    //    return 0;
   // }
//}

int main(void)
{
    int gameGrid[GRID_DIMENSION * GRID_DIMENSION];
    
    int car_init_position_x = (GRID_DIMENSION - 1) / 2;
    int car_init_position_y = GRID_DIMENSION - 1;
    int car_direction_x = 0;
    gameGrid[CAR_PLACE] = (car_init_position_y * GRID_DIMENSION) + car_init_position_x;

    srand(time(NULL));
    int obstacle_init_position_y = 0;
    int obstacle_init_position_x = rand() % GRID_DIMENSION;
    gameGrid[OBSTACLE_PLACE] = (obstacle_init_position_y * GRID_DIMENSION) + obstacle_init_position_x;


    while (true)
    {
        system("cls");

        for(int r = 0; r < GRID_DIMENSION; ++r)
        {
            for(int c = 0; c < GRID_DIMENSION; ++c)
            {
                bool is_car = false;
                bool is_obstacle = false;

                if(r == gameGrid[CAR_PLACE] / GRID_DIMENSION && c == gameGrid[CAR_PLACE] % GRID_DIMENSION)
                {
                    printf("%c", CAR);
                    is_car = true;
                }
                else if(r == obstacle_init_position_y && c == gameGrid[OBSTACLE_PLACE] % GRID_DIMENSION)
                {
                    printf("%c", OBSTACLE);
                    is_obstacle = true;
                }

                if(!is_car && !is_obstacle)
                {
                    printf(".");
                }

                if(c != GRID_DIMENSION - 1)
                {
                    printf(" ");
                }

            }
            printf("\n");
        }

        if (kbhit())
        {
            int key = getch();
            switch(key)
            {
                case KEY_RIGHT:
                    car_direction_x = 1;
                    break;
                case KEY_LEFT:
                    car_direction_x = -1;
                    break;
                default:
                    break;
            }
        }

        int car_x = gameGrid[CAR_PLACE] % GRID_DIMENSION;
        int move_car_x = car_x + car_direction_x;
        if (move_car_x >= 0 && move_car_x < GRID_DIMENSION)
        {
            gameGrid[CAR_PLACE] = (car_init_position_y * GRID_DIMENSION) + move_car_x;
        }

        obstacle_init_position_y += 1; 
        if (obstacle_init_position_y >= GRID_DIMENSION)
        {
            obstacle_init_position_y = 0; 
            obstacle_init_position_x = rand() % GRID_DIMENSION; 
            gameGrid[OBSTACLE_PLACE] = (obstacle_init_position_y * GRID_DIMENSION) + obstacle_init_position_x;
        }

        if(move_car_x == obstacle_init_position_x && car_init_position_y == obstacle_init_position_y)
        {
            break;
        }


        //if (collision(gameGrid[CAR_PLACE], gameGrid[OBSTACLE_PLACE]))
       // {
        //    break;
        //}

        Sleep(60); 
    }



    return 0;
}