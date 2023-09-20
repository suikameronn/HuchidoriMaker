#pragma once
#include <iostream>
#include "FreeImage.h"

class IO
{
public:

	FIBITMAP* GenericLoader(const char* Path, int flag);//画像をバッファに読み込む

	bool GenericWriter(FIBITMAP* dib, const char* Path, int flag);//画像をファイルに出力する
};