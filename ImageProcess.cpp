#include"ImageProcess.h"

void ImageProcess::Huchidori(FIBITMAP* image,std::vector<int> &edgeLoc,int width,int height)
{
	int a = 0;

	x = edgeLoc.begin();
	for (; x != edgeLoc.end(); ++x)
	{
		//Žl•ûŒü
		FreeImage_GetPixelColor(image, *x % width, (*x / width) - 1, &color);
		if (color.rgbReserved == a)
		{
			FreeImage_SetPixelColor(image, *x % width, (*x / width) - 1, &huchi);
		}

		FreeImage_GetPixelColor(image, (*x % width) + 1, *x / width, &color);
		if (color.rgbReserved == a)
		{
			FreeImage_SetPixelColor(image, (*x % width) + 1, *x / width, &huchi);
		}

		FreeImage_GetPixelColor(image, (*x % width) - 1, *x / width, &color);
		if (color.rgbReserved == a)
		{
			FreeImage_SetPixelColor(image, (*x % width) - 1, *x / width, &huchi);
		}

		//ŽÎ‚ß
		FreeImage_GetPixelColor(image, (*x % width) - 1, (*x / width) - 1, &color);
		if (color.rgbReserved == a)
		{
			FreeImage_SetPixelColor(image, (*x % width) - 1, (*x / width) - 1, &huchi);
		}

		FreeImage_GetPixelColor(image, (*x % width) + 1, (*x / width) - 1, &color);
		if (color.rgbReserved == a)
		{
			FreeImage_SetPixelColor(image, (*x % width) + 1, (*x / width) - 1, &huchi);
		}
	}
}