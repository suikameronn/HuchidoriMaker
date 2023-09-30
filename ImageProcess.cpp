#include"ImageProcess.h"

void ImageProcess::Huchidori(std::shared_ptr<FIBITMAP> image,std::vector<int> &edgeLoc,int width,int height)
{
	RGBQUAD huchi = { 255, 255, 255,255};

	x = edgeLoc.begin();
	for (; x != edgeLoc.end(); ++x)
	{
		FreeImage_SetPixelColor(image.get(), *x % width, *x / width, &huchi);
	}
}