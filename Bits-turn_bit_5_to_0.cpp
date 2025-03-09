#include"pch"


int Reg =  0xFFAAA;

int result = Reg & (~(1 << 5));

int result2 = Reg & (~0b010000);