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
        dec ecx; // уменьшаем счетчик на 1
        cmp ecx, 0; // проверяем счетчик на равенство 0
        jg RID; // возвращемся к началу цикла, если значение больше
        mov s, ebx; // заносим сумму для вывода
    }
    cout << "s = " << s << endl;
    return 0;
}