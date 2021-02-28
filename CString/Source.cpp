#include <iostream>
#include <string>

using namespace std;

int power(int a, int b) {
	int c = a;
	for (int i = 0; i < b - 1; i++) {
		a *= c;
	}
	return a;
}

void to_upper(char str[]) {
	for (int i = 0; str[i]; i++) {
		if (str[i] > 96 and str[i] < 123) {
			str[i] -= 32;
		}
	}
}

void to_lower(char str[]) {
	for (int i = 0; str[i]; i++) {
		if (str[i] < 91 and str[i] > 64) {
			str[i] += 32;
		}
	}
}

void capitalize(char str[]) {
	if (str[0] > 96 and str[0] < 123)str[0] -= 32;
	for (int i = 1; str[i]; i++) {
		if (str[i-1] == 32 and str[i] > 96 and str[i] < 123) {
			str[i] -= 32;
		}
	}
}

void shrink(char str[]) {
	for (int i = 0;str[i]; i++) {
		if (str[i - 1] == 32 and str[i] == 32) {
			for (int b = i + 1; str[b-1]; b++) {
				str[b - 1] = str[b];
			}
			i--;
		}
	}
	if (str[0] == 32) {
		for (int b = 1; str[b - 1]; b++) {
			str[b - 1] = str[b];
		}
	}
}

bool is_palyndrom(char str[]) {
	int m = 0;
	for (; str[m]; m++);
	m--;
	for (int i = 0; i < m/2; i++) {
		if (str[i] != str[m - i]) return false;
	}
	return true;
}

bool is_number(char str[]) {
	for (int i = 0; str[i]; i++) {
		if (str[i] < 48 or str[i] > 57) return false;
	}
	return true;
}

int to_int(char str[]) {
	int m = 0;
	for (; str[m]; m++);
	int a = 0;
	int power = 10;
	for (int b = 0; b < m - 2; b++) {
		power*=10;
	}
	for (int i = 0; str[i]; i++) {
		a += (str[i] - 48) * power;
		power/=10;
	}
	return a;
}

bool is_bin(char str[]) {
	for (int i = 0; str[i]; i++) {
		if (str[i] - 48 != 0 and str[i] - 48 != 1) return false;
	}
	return true;
}

int bin_to(char str[]) {
	int a = 0;
	int m = 0;
	for (; str[m]; m++);
	m--;
	for (int i = 0; str[i]; i++) {
		a += (str[i] - 48) * power(2, m);
		m--;
	}
	a--;
	return a;
}

bool is_hex(char str[]) {
	for (int i = 0; str[i]; i++) {
		if ((str[i] < 48 or str[i] > 57) and (str[i] < 65 or str[i] > 70)) return false;
	}
	return true;
}

int hex_to(char str[]) {
	int temp = 0;
	int a = 0;
	int m = 0;
	for (; str[m]; m++);
	m--;
	for (int i = 0; str[i]; i++) {
		if (str[i] > 47 and str[i] < 58) {
			temp = power(16, m);
			if (m == 0) temp /= 16;
			a += (str[i] - 48) * temp;
		}
		else {
			temp = power(16, m);
			if (m == 0) temp /= 16;
			a += (str[i] - 55) * temp;
		}
		m--;
	}
	return a;
}

void main() {
	setlocale(LC_ALL, "Rus");
	const int n = 20;
	char str[n];
	cout << "Введите строку: "; cin.getline(str, n);
	cout << endl;
	cout << str << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	if (is_palyndrom(str) == true) cout << "Строка - Палиндром" << endl;
	else cout << "Строка - Не Палиндром"  << endl;
	capitalize (str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	if (is_number(str) == true) {
		cout << "Строка - число" << endl;
		cout << to_int(str) << endl;
	}
	else cout << "Строка - Не Число" << endl;
	if (is_bin(str) == true) {
		cout << "Строка - двоичное число" << endl;
		cout << bin_to(str) << endl;
	}
	else cout << "Строка - не двоичное число" << endl;
	to_upper(str);
	if (is_hex(str) == true) {
		cout << "Строка - шестнадцатеричное число" << endl;
		cout << hex_to(str) << endl;
	}
	else cout << "Строка - не шестнадцатеричное число" << endl;
	
}