#include<iostream>
#include"FreeImage.h"
#include"IO.h"
#include"GetPixelData.h"
#include"ImageProcess.h"

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

        std::shared_ptr<FIBITMAP> alpha = std::shared_ptr<FIBITMAP>(FreeImage_Allocate(pixels.getWidth(), pixels.getHeight(), FreeImage_GetBPP(image.get())),FreeImage_Unload);
        std::shared_ptr<unsigned char[]> alphaDegree(new unsigned char[(pixels.getWidth() - 2) * (pixels.getHeight() - 2)]);
        pixels.copyAlpha(image, alphaDegree);

        ImageProcess ip;
        std::shared_ptr<FIBITMAP> output = std::shared_ptr<FIBITMAP>(FreeImage_Allocate(pixels.getWidth(), pixels.getHeight()
            , FreeImage_GetBPP(image.get())), FreeImage_Unload);
        ip.Huchidori(image, alphaDegree, output, pixels.getWidth(), pixels.getHeight());

        if (!FreeImage_Save(FIF_PNG, output.get(), "convert.png", PNG_DEFAULT))
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
            // GIF画像を読み込み
            auto filename = "a.png";
            auto image = std::shared_ptr<FIBITMAP>(
                FreeImage_Load(FIF_PNG, filename, GIF_DEFAULT), FreeImage_Unload);
            if (!image) {
                throw std::runtime_error("Load failed");
            }

            // グレースケールに変換
            auto greyimg = std::shared_ptr<FIBITMAP>(
                FreeImage_ConvertToGreyscale(image.get()), FreeImage_Unload);
            if (!greyimg) {
                throw std::runtime_error("Convert failed");
            }

            // PNGとして保存
            if (!FreeImage_Save(FIF_PNG, greyimg.get(), "convert.png", PNG_DEFAULT)) {
                throw std::runtime_error("Save failed");
            }
        }
        catch (std::exception& e) {
            std::cout << "exception!\n" << e.what() << std::endl;
        }
}
*/