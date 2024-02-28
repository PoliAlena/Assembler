#include <iostream>
using namespace std;

int main()
{
	int a, b, s;
	cout << "A = "; cin >> a;
	cout << "B = "; cin >> b;

	_asm {
		mov edi, a
		mov ecx, b
		sub ecx, edi
		FOR :
		mov eax, edi
			xor edx, edx
			mov esi, 4
			div esi
			cmp edx, 0
			je SUM
			SUM : add s, esi
			inc edi
			loop FOR
	}
	cout << "s = " << s << endl;
	return 0;
}