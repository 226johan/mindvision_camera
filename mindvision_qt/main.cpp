#include "CameraApi.h"  //相机SDK的API头文件

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

//#include "CameraApi.h"
//#include "CameraDefine.h"
//#include "CameraStatus.h"

#include "camera_mindvision_running.h"
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/types_c.h>
#include <stdio.h>

using namespace cv;

unsigned char* g_pRgbBuffer;  //处理后数据缓存区

int main()
{
    MindvisionCamera camera;
    Mat              src;
    camera.runCamera();
    // camera.VideoStart();
    while (1)
    {

        camera.Do();

        camera.getImage(src);
        std::cout << "src::" << src.rows << std::endl;

        imshow("src", src);
        waitKey(10);
        std::cout << "222" << std::endl;
    }
    //    camera.VideoStop();
    CameraUnInit(camera.hCamera);
    //注意，现反初始化后再free
    free(camera.g_pRgbBuffer);
}
