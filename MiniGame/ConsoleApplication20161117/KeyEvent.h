#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
class KeyEvent{
private:
	HANDLE hIn;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;
public:
	KeyEvent(){
		hIn = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getKey(){
		ReadConsoleInput(hIn, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT){
			if (InRec.Event.KeyEvent.bKeyDown){
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode;
				return downKey;
			}
			else
				return -1;
		}
		return -1;
	}
};