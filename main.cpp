#include "Interface.h"
#include "control.h"
#include <stdio.h>

int main() {

	InitGlobal();

	symbol computer = o;

	LoadImg();
	InitWindow();
	int location;
begain:
	while (1)
	{
		location = where(computer);
		printf("%d\n", location);
		map[location] = computer;
		Draw();
		if (isOver()) break;

		location = getTouch();
		while (map[location]!=empty) getTouch();
		map[location] = (symbol)-computer;
		Draw();
		if (isOver()) break;
	}
	
	system("pause");
	InitGlobal();
	goto begain;
	return 0;
}