#include <iostream>
using namespace std;

int main()
{
    short a, b, c, y;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    //5*a+b a>b
    //-125 a=b
    //(a-5)/b a<b
    _asm {
        mov bx, b
        cmp a, bx
        jg great1
        jl low1
        mov ax, -125  // a = b = -125
        jmp end1;
    great1: mov ax, a    // a > b
        imul ax, 5   //5*a
        add ax, bx  //5*a+b
        jmp end1;
    low1: cmp bx, 0   // a < b
       je null1
       mov ax, a
       sub ax, 5   //a-5
       xor dx, dx
       div bx      //(a-5)/b
       jmp end1;
       null1:  mov ax, 0  //b=0
       jmp end1;
       end1: mov y, ax;
    }
    cout << "y = " << y << endl;
    system("pause");
    return 0;
}