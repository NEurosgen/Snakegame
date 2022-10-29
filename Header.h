#pragma once
#include "framework.h"

#include "WindowsX.h"
#define long 5
#define move 8
#define wheght 8
#define X 800
#define Y 600
#define LOCALX 100
#define LOCALY 100

struct POint {
    HDC hdc;
    int x;
    int y;
    int red;
    int green;
    int blue;

};
void wrog(int x, int y, POint* mas, int& size);
void Bline(POint li);
void line(POint li);

void snake(HDC hdc, int  x, int  y, POint* mas, int& size);
void add(POint* mas, int& size);
void Phone(HDC hdc);

POint apple(int s );
bool if1(int x, int y, POint ap, POint* mas);
bool if2(int x, int y, POint ap, POint* mas);
bool if3(int x, int y, POint ap, POint* mas);
bool if4(int x, int y, POint ap, POint* mas);