#include "MJPEGWriter.h"
int main()
{
    MJPEGWriter test(7777);

    VideoCapture cap;
    bool ok = cap.open("udpsrc port=5000 ! application/x-rtp, encoding-name=H264,payload=96 !  rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! appsink");

    if (!ok)
    {
        printf("no cam found ;(.\n");
        pthread_exit(NULL);
    }
    
    Mat frame;
    cap >> frame;
    test.write(frame);
    frame.release();
    test.start();
    while(cap.isOpened()){cap >> frame; test.write(frame); frame.release();}
    test.stop();
    exit(0);

}