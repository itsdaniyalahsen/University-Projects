// House.h
#ifndef HOUSE_H
#define HOUSE_H

#include<iostream>


class House{ 

private:
    int size;
    char border, fill;

public:
    House(int, char, char);

    bool checksize(int);
    bool check_ascii(int);

    int GetSize();
    int Perimeter();
    float Area();

    void SetBorder(int);
    void SetFill(int);

    void Grow();
    void Shrink();

    void Draw();
    void Summary();

};


#include "house.cpp"

#endif
