#pragma once
#include "GetPixelData.h"

GetPixelData::GetPixelData(int w, int h): width(w),height(h)
{
}

void GetPixelData::copyAlpha(FIBITMAP* image, std::vector<int> &edgeLoc)
{
	int i, j;

	int tmp;
	for (i = 1; i < height - 1; i++)
	{
		for (j = 1; j < width - 1; j++)
		{
			tmp = 0;

			FreeImage_GetPixelColor(image, j, i, &color);
			tmp -= color.rgbReserved * 8;

			FreeImage_GetPixelColor(image, j + 1, i, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image, j - 1, i, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image, j, i + 1, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image, j, i - 1, &color);
			tmp += color.rgbReserved;

			FreeImage_GetPixelColor(image, j + 1, i - 1, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image, j - 1, i - 1, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image, j + 1, i + 1, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image, j - 1, i + 1, &color);
			tmp += color.rgbReserved;

			if (tmp != 0)
			{
				edgeLoc[j + i * width];
			}
		}
	}

	edgeLoc.shrink_to_fit();

}

int GetPixelData::getWidth()
{
	return width;
}

int GetPixelData::getHeight()
{
	return height;
}