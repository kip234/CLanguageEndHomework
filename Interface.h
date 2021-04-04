#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "Global.h"
#include <graphics.h>

IMAGE imgs[all + 1];

void LoadImg();
void InitWindow();
void Draw();

void LoadImg() {
	loadimage(imgs + x + 1, _T("x.bmp"), IMG_SIZE, IMG_SIZE);
	loadimage(imgs + empty + 1, _T("empty.bmp"), IMG_SIZE, IMG_SIZE);
	loadimage(imgs + o +1, _T("o.bmp"), IMG_SIZE, IMG_SIZE);
}

void InitWindow() {
	initgraph(IMG_SIZE * 3 + INTERVAL * 2, IMG_SIZE * 3 + INTERVAL * 2);
}

void Draw() {
	for (int i = 0; i < 9;i++) {
		unsigned int x = (i % 3) * (IMG_SIZE+INTERVAL), 
					 y = (i / 3) * (IMG_SIZE+INTERVAL);
		putimage(x, y, &imgs[map[i]+1]);
	}
}

int getTouch() {//获取鼠标点击的位置
	MOUSEMSG m = GetMouseMsg();
	while (m.uMsg != WM_LBUTTONDOWN) m = GetMouseMsg();//等待左键按下
	return m.x / (IMG_SIZE + INTERVAL)+ m.y / (IMG_SIZE + INTERVAL)*3;
}

#endif