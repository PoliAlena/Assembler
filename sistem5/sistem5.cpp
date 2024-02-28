#include <iostream>
using namespace std;

int main()
{
    int n, s;
    cout << "n = "; cin >> n;

    _asm {
        // s = 2*0 + 2*1 + 2*3 + ... + 2*i
        mov ebx, 0; //переменная для накопления суммы
        mov ecx, n; // счетчик
        mov esi, 0; //начальное значение i = 0
    RID:
        xor eax, eax;
        mov eax, esi;
        imul eax, 2; // умножение 2*0, 2*1, ..., 2*i
        add ebx, eax; // накопление суммы
        inc esi; // увеличиваем множитель на 1
        loop RID; // возвращаемся к началу цикла, если переменная счетчика не равна 0
        mov s, ebx; // заносим сумму для вывода
    }
    cout << "s = " << s << endl;
    return 0;
}