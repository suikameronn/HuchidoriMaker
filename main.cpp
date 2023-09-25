#include<iostream>
#include"FreeImage.h"
#include"IO.h"
#include"GetPixelData.h"

int main(void)
{
    FreeImage_Initialise();

    std::cout << "FreeImage ver. " << FreeImage_GetVersion() << std::endl;
    std::cout << FreeImage_GetCopyrightMessage() << std::endl;

    try
    {
        char path[] = "a.png";

        IO io;
        std::shared_ptr<FIBITMAP> image = std::shared_ptr<FIBITMAP>(io.GenericLoader(path, 0), FreeImage_Unload);
        if (!image)
        {
            throw std::runtime_error("Load failed");
        }

        RGBQUAD* color;
        GetPixelData pixels(FreeImage_GetWidth(image.get()), FreeImage_GetHeight(image.get()));

        std::shared_ptr<FIBITMAP> alpha = std::shared_ptr<FIBITMAP>(FreeImage_Allocate(pixels.getWidth(), pixels.getHeight(), FreeImage_GetBPP(image.get())));
        std::shared_ptr<unsigned char[]> alphaDegree(new unsigned char[(pixels.getWidth() - 2) * (pixels.getHeight() - 2)]);
        pixels.copyAlpha(image, alpha,alphaDegree);


        if (!FreeImage_Save(FIF_PNG, alpha.get(), "convert.png", PNG_DEFAULT))
        {
            throw std::runtime_error("Save failed");
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception!\n" << e.what() << std::endl;
    }
}

/*
int main(void)
{
        std::cout << "FreeImage ver. " << FreeImage_GetVersion() << std::endl;
        std::cout << FreeImage_GetCopyrightMessage() << std::endl;

        try {
            // GIF�摜��ǂݍ���
            auto filename = "a.png";
            auto image = std::shared_ptr<FIBITMAP>(
                FreeImage_Load(FIF_PNG, filename, GIF_DEFAULT), FreeImage_Unload);
            if (!image) {
                throw std::runtime_error("Load failed");
            }

            // �O���[�X�P�[���ɕϊ�
            auto greyimg = std::shared_ptr<FIBITMAP>(
                FreeImage_ConvertToGreyscale(image.get()), FreeImage_Unload);
            if (!greyimg) {
                throw std::runtime_error("Convert failed");
            }

            // PNG�Ƃ��ĕۑ�
            if (!FreeImage_Save(FIF_PNG, greyimg.get(), "convert.png", PNG_DEFAULT)) {
                throw std::runtime_error("Save failed");
            }
        }
        catch (std::exception& e) {
            std::cout << "exception!\n" << e.what() << std::endl;
        }
}
*/