#include"ImageProcess.h"

void ImageProcess::Huchidori(std::shared_ptr<FIBITMAP> image
	,std::vector<int>::iterator begin, std::vector<int>::iterator end,std::shared_ptr<FIBITMAP> output,int width,int height)
{
	int i, j, k, m;
	RGBQUAD color;
	RGBQUAD huchi = { 255,255,255,255 };

	for (i = 0; i < width * height; i++)
	{
		FreeImage_GetPixelColor(image.get(), i % width, i / width, &color);
		FreeImage_SetPixelColor(output.get(), i % width, i / width, &color);
	}

	for (; begin != end; begin++)
	{
		//αチェックのコード
	}
}