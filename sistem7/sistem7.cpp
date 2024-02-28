#include <iostream>
using namespace std;

int main()
{
    const unsigned int redBits = 0xFF000000;
    const unsigned int greenBits = 0x00FF0000;
    const unsigned int blueBits = 0x0000FF00;
    const unsigned int alphaBits = 0x000000FF;

    cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    unsigned int pixel;
    cin >> hex >> pixel; // std::hex позволяет вводить шестнадцатеричные значения // используем побитовое И для изоляции red pixels, затем сдвигаем значение вправо в диапазон 0-255
    unsigned char red, green, blue, alpha;

    _asm {
        mov eax, pixel
        and eax, redBits //pixel & redBits
        shr eax, 24 //(pixel & redBits) >> 24
        mov red, al // red

        mov eax, pixel
        and eax, greenBits //pixel & greenBits
        shr eax, 16 //(pixel & greenBits) >> 16
        mov green, al //green

        mov eax, pixel
        and eax, blueBits //pixel & blueBits
        shr eax, 8 //(pixel & blueBits) >> 8
        mov blue, al //blue

        mov eax, pixel
        and eax, alphaBits //pixel & alphaBit
        mov alpha, al //alpha
    }
    cout << "Your color contains:" << endl;;
    cout << static_cast<int>(red) << " of 255 red" << endl;;
    cout << static_cast<int>(green) << " of 255 green" << endl;;
    cout << static_cast<int>(blue) << " of 255 blue" << endl;;
    cout << static_cast<int>(alpha) << " of 255 alpha" << endl;;
    return 0;
