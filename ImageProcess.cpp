#include"ImageProcess.h"
#include<iostream>
#include"FreeImage.h"

void ImageProcess::Huchidori(std::shared_ptr<FIBITMAP> image
	,std::shared_ptr<unsigned char[]> alphaDegree,std::shared_ptr<FIBITMAP> output,int width,int height)
{
	int i, j, k, m;
	RGBQUAD color;
	RGBQUAD huchi = { 255,255,255,255 };

	for (i = 0; i < width * height; i++)
	{
		FreeImage_GetPixelColor(image.get(), i % width, i / width, &color);
		FreeImage_SetPixelColor(output.get(), i % width, i / width, &color);
	}

	for (i = 0; i < height - 2; i++)
	{
		for (j = 0; j < width - 2; j++)
		{
			if (alphaDegree[j + i * (width - 2)] == 1)
			{
				FreeImage_GetPixelColor(image.get(), j + 1 + 1, i, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1 + 1, i, &huchi);
				}

				FreeImage_GetPixelColor(image.get(), j + 1 - 1, i, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1 - 1, i + 1, &huchi);
				}

				FreeImage_GetPixelColor(image.get(), j + 1 , i - 1, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1, i - 1, &huchi);
				}

				FreeImage_GetPixelColor(image.get(), j + 1, i + 1, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1, i + 1, &huchi);
				}
			}
		}
	}
}