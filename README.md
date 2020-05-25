# gstream-to-mjpeg

This project is adapted from the code available on https://github.com/JPery/MJPEGWriter.

To test execute the pipeline *gstreamer*:

*gst-launch-1.0 videotestsrc ! video/x-raw,width=1280,height=720 ! x264enc noise-reduction=10000 tune=zerolatency byte-stream=true bitrate=3000 threads=2 ! h264parse config-interval=1 ! rtph264pay ! udpsink host=localhost port=5000*

**Installing steps:**
```
mkdir build
cd build
cmake ../
make 
```
