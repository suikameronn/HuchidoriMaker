#pragma once
#include "GetPixelData.h"

GetPixelData::GetPixelData(int w, int h): width(w),height(h)
{
}

void GetPixelData::copyAlpha(std::shared_ptr<FIBITMAP> image, std::vector<int> &edgeLoc)
{
	int i, j;
	RGBQUAD color;

	itr = edgeLoc.begin();

	int tmp;
	for (i = 1; i < height - 1; i++)
	{
		for (j = 1; j < width - 1; j++)
		{
			tmp = 0;

			FreeImage_GetPixelColor(image.get(), j, i, &color);
			tmp -= color.rgbReserved * 4;

			FreeImage_GetPixelColor(image.get(), j + 1, i, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image.get(), j - 1, i, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image.get(), j, i + 1, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image.get(), j, i - 1, &color);
			tmp += color.rgbReserved;

			if (tmp != 0)
			{
				*itr = j + (width - 2) * i;
				itr++;
			}
		}
	}

	//int f = edgeLoc.capacity();
	//printf("%d\n", f);
	edgeLoc.erase(itr, edgeLoc.end());//“úX‚Ìƒƒ‚’ std::vector‚ðŽQÆ
	//f = edgeLoc.capacity();
	//printf("%d\n", f);
	
}

int GetPixelData::getWidth()
{
	return width;
}

int GetPixelData::getHeight()
{
	return height;
}