#include"ImageProcess.h"

void ImageProcess::Huchidori(std::shared_ptr<FIBITMAP> image,std::vector<int> edgeLoc)
{
	RGBQUAD color;
	RGBQUAD huchi = { 255,255,255,255 };
	

	for (; begin != edgeLoc.end(); begin++)
	{
		if (*begin != -1)
		{
			//printf("%d\n", *begin);
		}
	}
}