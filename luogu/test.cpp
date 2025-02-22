#include <iomanip>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void printchar(int which) {
	keybd_event(which, 0, 0, 0);
	Sleep(50);
	keybd_event(which, 0, KEYEVENTF_KEYUP, 0);
}

void back(int count) {
	while (count --> 0) printchar(VK_BACK);
}

void chagang() {
	printchar(0xBF);
}

void print(string str) {
	for (char i : str) {
		if (i == '/') {
			chagang();
		} else {
			if ('A' <= i && i <= 'Z') keybd_event(VK_LSHIFT, 0, 0, 0);
			if ('a' <= i && i <= 'z') printchar(i - 'a' + 'A');
			else printchar(i);
			if ('A' <= i && i <= 'Z') keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
	}
}

void leftdown() {
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 593, 308, 0, 0);
}

vector<int> ans;

int main() {
	system("pause");
	Sleep(2000);
	HDC hdc = GetDC(NULL);
	for (int i = 1417; i <= 5000 && GetKeyState('S') >= 0; i++) {
		SetCursorPos(580, 427);
		Sleep(100);
		leftdown();
		Sleep(500);
		leftdown();
		back(5);
		print(string("P") + to_string(i));
		printchar(VK_RETURN);
		Sleep(2000);
		COLORREF col = GetPixel(hdc, 271, 594);
		if (GetRValue(col) != 255) {
			cout << "P" << i << ": Yes" << endl;
			ans.push_back(i);
		} else {
			cout << "P" << i << ": No" << endl;
		}
	}
	cout << "Ok:" << endl;
	for (int i : ans) cout << "P" << i << endl;
//	while (true) {
//		POINT pos;
//		GetCursorPos(&pos);
//		COLORREF col = GetPixel(hdc, pos.x, pos.y);
//		cout << pos.x << ' ' << pos.y << ' ' << (int) GetRValue(col) << ' ' << (int) GetGValue(col) << ' ' << (int) GetBValue(col) << endl;
//	}
	ReleaseDC(NULL, hdc);
	return 0;
}

