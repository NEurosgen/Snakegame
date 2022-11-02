#pragma once
#include "framework.h"

#include "WindowsX.h"
#define lon 5
#define move 4
#define wheght 8
#define X 800
#define Y 600
#define LOCALX 100
#define LOCALY 100
#define COLWALL 30
struct Wall {
    HDC hdc;
    int x;
    int y;
    int xk;
    int yk;
    int red = 0; int blue = 0;
    int green = 0;
};
struct POint {
    HDC hdc;
    int x;
    int y;
    int xk;
    int yk;
    int red;
    int green;
    int blue;

};
void wrog(int x, int y, POint* mas, int& size);
void Bline(POint li);
void line(POint li);

void snake(HDC hdc, int  x, int  y, POint* mas, int& size, Wall* wal);
void add(POint* mas, int& size);
void Phone(HDC hdc);

POint  apple(int s, Wall* wal);
bool if1(int x, int y, POint ap, POint* mas);
bool if2(int x, int y, POint ap, POint* mas);
bool if3(int x, int y, POint ap, POint* mas);
bool if4(int x, int y, POint ap, POint* mas);
bool inaarea(POint* mas, int x1, int y1, int x1k, int y1k);
void wall(Wall base);