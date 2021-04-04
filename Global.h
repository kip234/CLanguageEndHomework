#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned int MapType;

const unsigned int IMG_SIZE = 50;//ÿһ��ͼƬ�Ĵ�С
const unsigned int INTERVAL = 5;//ÿ��ͼƬ֮��Ŀո�

/*�˴���X��O��ֵ����Ϊ
* �ɳ��ֵı߽�ֵ���������
* ��ֵ��ж�
*/
enum symbol{
	x = -1,//
	empty,//0
	o,//1
	all//2
};


MapType* map = (MapType*)malloc(9 * sizeof(MapType));

void InitGlobal() {
	memset(map, empty, 9 * sizeof(MapType));
}

#endif
