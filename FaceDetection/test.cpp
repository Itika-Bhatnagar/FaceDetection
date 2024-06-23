#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
using namespace std;
using namespace cv;


/*
void main() {
	string path = "1718280956569.jpg";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}
*/

void main()
{
	VideoCapture video(0);
	Mat img;
	while (true) {
		video.read(img);
		imshow("Frame", img);
		waitKey(1);

	}
}
