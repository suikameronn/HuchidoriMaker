#include<iostream>
#include<vector>
#include"FreeImage.h"
#include"IO.h"
#include"GetPixelData.h"
#include"ImageProcess.h"

#include<time.h>

int main(void)
{
    FreeImage_Initialise();

    try
    {
        clock_t start = clock();    // �X�^�[�g����
        char path[] = "a.png";

        IO io;
        std::shared_ptr<FIBITMAP> image = std::shared_ptr<FIBITMAP>(io.GenericLoader(path, 0), FreeImage_Unload);
        if (!image)
        {
            throw std::runtime_error("Load failed");
        }

        GetPixelData pixels(FreeImage_GetWidth(image.get()), FreeImage_GetHeight(image.get()));

        std::vector<int> edgeLoc(pixels.getWidth() * pixels.getHeight());
        pixels.copyAlpha(image.get(), edgeLoc);

        ImageProcess ip;
        ip.Huchidori(image.get(), edgeLoc, pixels.getWidth(), pixels.getHeight());

        clock_t end = clock();

        std::cout << "duration = " << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

        io.GenericWriter(image.get(), "convert.png", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "exception!\n" << e.what() << std::endl;
    }
}

//�G�b�W���o 0.033sec
// �G�b�W���o ���|�C���^ 0.026sec
//����� 0.148sec
// ����� 0.144sec
//�S�̂�0.21sec