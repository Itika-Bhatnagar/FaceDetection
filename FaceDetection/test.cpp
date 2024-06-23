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
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontal_default.xml");

	

	


	
	while (true) {
		video.read(img);

		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.2, 5);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
		}



		imshow("Frame", img);
		waitKey(1);

	}
}
