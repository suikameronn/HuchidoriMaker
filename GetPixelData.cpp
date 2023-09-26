#pragma once
#include "GetPixelData.h"

GetPixelData::GetPixelData(int w, int h): width(w),height(h)
{
}

void GetPixelData::copyAlpha(std::shared_ptr<FIBITMAP> image, std::shared_ptr<unsigned char[]> alphaDegree)
{
	int i, j;
	RGBQUAD color;

	//œZ‚ğ‰ñ”ğ‚·‚é
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			FreeImage_GetPixelColor(image.get(), j, i, &color);
		}
	}

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
				tmp = 1;
			}

			alphaDegree[(j - 1) + (i - 1) * (width - 2)] = (unsigned char)tmp;
		}
	}
}

int GetPixelData::getWidth()
{
	return width;
}

int GetPixelData::getHeight()
{
	return height;
}