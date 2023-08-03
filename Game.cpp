#include "Engine.h"
#include "Ball.h"
#include "AppearBall.h"
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <cmath>

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()

#define R SCREEN_HEIGHT/4
#define A SCREEN_WIDTH/2
#define B SCREEN_HEIGHT/2
//SCREEN_WIDTH 1024
//SCREEN_HEIGHT 768
Ball firstBall;
Ball secondBall;
AppearBall* balls;
int n;
double currentTime;
double delayForSpace;
double speed;
double spawnTime;
bool isWin;
double restartGame;

int GetRandomNumber(int min, int max)
{

    int num = min + rand() % (max - min + 1);
    return num;
}

// initialize game data in this function
void initialize()
{
    firstBall = Ball((SCREEN_WIDTH - (2 * R)) / 2, B, M_PI);
    secondBall = Ball(((SCREEN_WIDTH - (R * 2)) / 2) + (2 * R), B, 0);
    currentTime = clock();
    spawnTime = clock();
    delayForSpace = clock();
    restartGame = clock();
    n = 2;
    balls = new AppearBall[n]{
        AppearBall(0, GetRandomNumber(0, SCREEN_HEIGHT), GetRandomNumber(SCREEN_WIDTH - (2 * R), ((SCREEN_WIDTH - (R * 2)) / 2) + (2 * R)), GetRandomNumber(SCREEN_HEIGHT - (2 * R), ((SCREEN_HEIGHT - (R * 2)) / 2) + (2 * R)), rand(), true),
        AppearBall(0, GetRandomNumber(0, SCREEN_HEIGHT), GetRandomNumber(SCREEN_WIDTH - (2 * R), ((SCREEN_WIDTH - (R * 2)) / 2) + (2 * R)), GetRandomNumber(SCREEN_HEIGHT - (2 * R), ((SCREEN_HEIGHT - (R * 2)) / 2) + (2 * R)), rand(), false)
    };
    speed = 0.05;
    isWin = true;
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();

  if (is_key_pressed(VK_SPACE) && clock() - delayForSpace >= 200)
  {
      delayForSpace = clock();
      firstBall.changeWise();
      secondBall.changeWise();
  }

  if (clock() - currentTime >= 20)
  {
      currentTime = clock();
      
      //dissapear balls from right wall
      for (int i = 0; i < n; i++)
      {
          if (balls[i].getX() >= SCREEN_WIDTH)
              balls[i] = AppearBall(0, GetRandomNumber(0, SCREEN_HEIGHT), GetRandomNumber(SCREEN_WIDTH - (2 * R), ((SCREEN_WIDTH - (R * 2)) / 2) + (2 * R)), GetRandomNumber(SCREEN_HEIGHT - (2 * R), ((SCREEN_HEIGHT - (R * 2)) / 2) + (2 * R)), rand(), false);
      }

      //dissappear balls from each other
      for (int k = 0; k < n && isWin; k++)
      {
          for (int i = 0; i < balls[k].getLength() && isWin; i++)
          {
              for (int j = 0; j < balls[k].getLength() && isWin; j++)
              {
                  if (i + balls[k].getX() == firstBall.getX() && j + balls[k].getY() == firstBall.getY() || i + balls[k].getX() == secondBall.getX() && j + balls[k].getY() == secondBall.getY())
                  {
                      if (balls[k].getType() == Type::Danger)
                      {
                          isWin = false;
                          restartGame = clock();
                      }
                      else
                      {
                          balls[k] = AppearBall(0, GetRandomNumber(0, SCREEN_HEIGHT), GetRandomNumber(SCREEN_WIDTH - (2 * R), ((SCREEN_WIDTH - (R * 2)) / 2) + (2 * R)), GetRandomNumber(SCREEN_HEIGHT - (2 * R), ((SCREEN_HEIGHT - (R * 2)) / 2) + (2 * R)), rand(), false);
                      }
                  }
              }
          }
      }

      //gameRestart
      if(!isWin && clock() - restartGame >=3000)
      {
          initialize();
      }

      //move main balls
      if (firstBall.getWise())
      {
          firstBall.addAlpha(-speed);
          secondBall.addAlpha(-speed);
      }
      else
      {
          firstBall.addAlpha(speed);
          secondBall.addAlpha(speed);
      }
      
      firstBall.setX(R * cos(firstBall.getAlpha()) + A);
      firstBall.setY(R * sin(firstBall.getAlpha()) + B);
      secondBall.setX(R * cos(secondBall.getAlpha()) + A);
      secondBall.setY(R * sin(secondBall.getAlpha()) + B);
      int check = 0;

      //move coins and dangers
      for (int i = 0; i < n; i++)
      {
          if (balls[i].getMove())
              balls[i].updateBall();
          else if (clock() - spawnTime >= 3000)
          {
              balls[i].setMove(true);
              spawnTime = clock();
          }
      }
  }
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
  // clear backbuffer
  memset(buffer, 33333333, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

  //draw main balls
  if (isWin)
  {
      for (int i = -firstBall.getLength() / 2; i < firstBall.getLength() / 2; i++)
      {
          for (int j = -firstBall.getLength() / 2; j < firstBall.getLength() / 2; j++)
          {
              buffer[i + firstBall.getY()][j + firstBall.getX()] = firstBall.getColor();
          }
      }
      for (int i = -secondBall.getLength() / 2; i < secondBall.getLength() / 2; i++)
      {
          for (int j = -secondBall.getLength() / 2; j < secondBall.getLength() / 2; j++)
          {
              buffer[i + secondBall.getY()][j + secondBall.getX()] = secondBall.getColor();
          }
      }
  }

  //draw coins and enemys
  for (int k = 0; k < n; k++)
  {
      for (int i = 0; i < balls[k].getLength(); i++)
      {
          for (int j = 0; j < balls[k].getLength(); j++)
          {
              if (i + balls[k].getY() < 0 || i + balls[k].getY() >= SCREEN_HEIGHT || j + balls[k].getX() < 0 || j + balls[k].getX() >= SCREEN_WIDTH)
                  continue;
              buffer[i + balls[k].getY()][j + balls[k].getX()] = balls[k].getColor();
          }
      }
  }
}

// free game data in this function
void finalize()
{
    delete[] balls;
}

