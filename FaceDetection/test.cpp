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


int main() {
    // Open the default camera
    VideoCapture video(0);
    if (!video.isOpened()) {
        cerr << "Error: Cannot open camera" << endl;
        return -1;
    }
    else {
        cout << "Camera opened successfully" << endl;
    }

    // Load the cascade classifier
    CascadeClassifier facedetect;
    if (!facedetect.load("haarcascade_frontalface_default.xml")) {
        cerr << "Error: Could not load cascade classifier" << endl;
        return -1;
    }
    else {
        cout << "Cascade classifier loaded successfully" << endl;
    }

    Mat img;
    while (true) {
        // Read frame from the camera
        video >> img;
        if (img.empty()) {
            cerr << "Error: Frame is empty!" << endl;
            break;
        }

        // Convert the frame to grayscale
        Mat gray;
        cvtColor(img, gray, COLOR_BGR2GRAY);

        // Detect faces
        vector<Rect> faces;
        try {
            facedetect.detectMultiScale(gray, faces, 1.2, 5);
        }
        catch (cv::Exception& e) {
            cerr << "OpenCV Exception: " << e.what() << endl;
            continue; // Skip this frame and continue with the next
        }

        // Log the number of faces detected
        cout << "Number of faces detected: " << faces.size() << endl;

        // Draw rectangles around detected faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
            rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
            putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
        }

        // Display the frame
        imshow("Frame", img);
        if (waitKey(1) == 27) // Exit on ESC key
            break;
    }

    video.release();
    return 0;
}
