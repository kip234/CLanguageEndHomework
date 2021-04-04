#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned int MapType;

const unsigned int IMG_SIZE = 50;//每一张图片的大小
const unsigned int INTERVAL = 5;//每张图片之间的空格

/*此处将X与O的值设置为
* 可出现的边界值将方便后面
* 结局的判断
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
