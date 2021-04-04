#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "Global.h"
#include <stdlib.h>

symbol Win(MapType* map) {
	if (NULL == map) return empty;
	int m = 0;
	for (int i = 0; i < 3; i++) {
		//行
		m = map[i * 3] + map[i * 3 + 1] + map[i * 3 + 2];
		if (m == 3 * x) return x;
		if (m == 3 * o) return o;
		//列
		m = map[i] + map[i + 3] + map[i + 6];
		if (m == 3 * x) return x;
		if (m == 3 * o) return o;
	}
	//对角线
	m = map[0] + map[4] + map[8];
	if (m == 3 * x) return x;
	if (m == 3 * o) return o;
	m = map[6] + map[4] + map[2];
	if (m == 3 * x) return x;
	if (m == 3 * o) return o;
	return empty;
}

int translation(int x,int y) {
	return x + y * 3;
}

int where(symbol player) {
	MapType* tmp = (MapType*)malloc(9*sizeof(MapType));
	for (int i = 0; i < 9; i++) {
		if (map[i] != empty) continue;
		//printf("%d", i);
		memcpy(tmp, map, 9 * sizeof(MapType));

		tmp[i] = player;
		if (Win(tmp) == player) return i;

		tmp[i] = -player;
		if (Win(tmp) == (symbol)-player) return i;
	}
	//printf("\n");

	free(tmp);
	int re;
	for (re = 0; re < 9; re++) {
		if (map[re] == empty) {
			if ((re == 1 || re == 7) && map[re - 1] + map[re + 1] == 0) continue;
			if ((re == 3 || re == 5) && map[re - 3] + map[re + 3] == 0) continue;		
			if (re == 0 && (map[re + 1] + map[re + 2] == 0 || map[re + 3] + map[re + 6] == 0)) continue;
			if (re == 2 && (map[re - 1] + map[re - 2] == 0 || map[re + 3] + map[re + 6] == 0)) continue;
			if (re == 6 && (map[re + 1] + map[re + 2] == 0 || map[re - 3] + map[re - 6] == 0)) continue;
			if (re == 8 && (map[re - 1] + map[re - 2] == 0 || map[re + 3] - map[re - 6] == 0)) continue;
			break;
		}
	}
	while (map[re] != empty) re = rand() % 9;
	return re;
}

int isOver() {
	if (Win(map) != empty) return 1;
	for (int i = 0; i < 9; i++) {
		if (map[i] == empty) return 0;
	}
	return 1;
}

void outMap(const char* c) {
	printf(
		"%s{\n"
		"	%2d %2d %2d\n"
		"	%2d %2d %2d\n"
		"	%2d %2d %2d\n"
		"}\n",c,
		map[0], map[1], map[2],
		map[3], map[4], map[5],
		map[6], map[7], map[8]);
}

#endif