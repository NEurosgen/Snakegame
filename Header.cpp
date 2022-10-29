#include "framework.h"
#include<random>

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
    int red=0;
    int green=0;
    int blue=0;

};

void line(POint li) {
    int whize = wheght;
    int lng = wheght;
    RECT size = { li.x,li.y,li.x + whize,li.y + lng };
    HBRUSH bruh = CreateSolidBrush(RGB(li.red, li.green, li.blue));

    FillRect(li.hdc, &size, bruh);
    DeleteObject(bruh);
}
void wrog(int x, int y, POint* mas, int& size);
void Bline(POint li) {
    int whize = wheght*2;
    int lng = wheght*2;
    RECT size = { li.x,li.y,li.x + whize,li.y + lng };
    HBRUSH bruh = CreateSolidBrush(RGB(li.red, li.green, li.blue));

    FillRect(li.hdc, &size, bruh);
    DeleteObject(bruh);
}
void snake(HDC hdc, int  x, int  y, POint* mas, int& size) {
    mas[0].hdc = hdc;

    mas[0].x = x;
    mas[0].y = y;
    line(mas[0]);
    wrog(x, y, mas, size);

    POint block;
    for (int i = size - 1; i >= 1; i--) {
        block = mas[i];

        block.hdc = hdc;
        block.x = mas[i - 1].x;
        block.y = mas[i - 1].y;

        mas[i] = block;
        line(block);


    }
    for (int i = 0; i < size; ++i) {
        if (mas[i].x < 0) {
            int k = 0;
            k++;
        }
    }




    for (int i = 0; i < size; ++i) {
        if (mas[i].x < 0) {
            int k = 0;
            k++;
        }
    }





}
void add(POint* mas, int& size) {
    if (long* 100 > size) {
        POint chage = mas[size - 1];
        if (mas[size - 2].x < mas[size - 1].x) {
            chage.x += move;
        }
        if (mas[size - 2].x > mas[size - 1].x) {
            chage.x -= move;
        }
        if (mas[size - 2].y < mas[size - 1].x) {
            chage.y -= move;
        }
        if (mas[size - 2].y > mas[size - 1].x) {
            chage.y += move;
        }
        mas[size] = chage;
        size++;
    }
}
void Phone(HDC hdc) {
    RECT size = { 0,0,2000,1000 };
    HBRUSH bruh = CreateSolidBrush(RGB(100, 149, 237));

    FillRect(hdc, &size, bruh);
}
void wrog(int x, int y, POint* mas, int& size) {
    for (int i = 1; i < size; ++i) {
        if (mas[i].x == x && mas[i].y == y) {
            mas[i].red = 0;
            size = 0;
            return;
        }
    }
}
POint  apple(int s) {
    POint apple;
    unsigned int k = s;
    
    srand(k);
    apple.x = (rand() %( X/2)+LOCALX);
    apple.y = (rand() % (Y/2)+LOCALY);
    apple.green = 200;
    
    return apple;

    
}
bool if1(int x, int y,POint ap,POint *mas) {
    return (mas[0].x >= ap.x && mas[0].x <= ap.x + wheght * 2 && mas[0].y >= ap.y && mas[0].y <= ap.y + wheght * 2);
}
bool if2(int x, int y, POint ap, POint* mas) {
    return (mas[0].x >= ap.x && mas[0].x <= ap.x + wheght * 2 && mas[0].y+wheght >= ap.y && mas[0].y+wheght <= ap.y + wheght * 2);
}
bool if3(int x, int y, POint ap, POint* mas) {
    return (mas[0].x + wheght >= ap.x && mas[0].x+ wheght <= ap.x + wheght * 2 && mas[0].y >= ap.y && mas[0].y  <= ap.y + wheght * 2);
}
bool if4(int x, int y, POint ap, POint* mas) {
    return (mas[0].x+ wheght >= ap.x && mas[0].x + wheght <= ap.x + wheght * 2 && mas[0].y + wheght >= ap.y && mas[0].y+ wheght <= ap.y + wheght * 2);
}