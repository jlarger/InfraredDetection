#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>



using namespace cv;
using namespace std;

const int fps = 20;


int main(int argc, char** argv)
{

	Mat output;
	Mat gray;
	Mat dst;
	Mat detected_edges;

	Mat frame = imread("ANOTHER.jpg", 1);

	//Mat frame;

	//VideoCapture vid(0);

	/*if (!vid.isOpened())
	{
		return -1;
	}
	
	while (vid.read(frame))
	{*/
		

		//if (waitKey(1000 / fps) >= 0) break;


		
		cvtColor(frame, gray, COLOR_BGR2GRAY);

		Mat thresh;

		//threshold(gray, dst, 177, 215, 3);

		threshold(gray, detected_edges, 177, 215, 3);

		//imshow("yeet", dst);

		//-------------------------------------------------------------------

		

		blur(gray, detected_edges, Size(3, 3));

		//Canny(detected_edges, detected_edges, 177, 210*1.5, 3);
		Canny(detected_edges, detected_edges, 177, 215 * 1.5, 3);

		dst = Scalar::all(0);

		frame.copyTo(dst, detected_edges);







		//------------------------------------------------------------------


		vector<vector<Point>> contours;
		vector<Vec4i> hierarchy;

		findContours(detected_edges, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

		Mat outputH = frame.clone();




		//-----------------------------------------------------------------

		vector<Rect> boundRect(contours.size());



		for (size_t j = 0; j < contours.size(); j++)
		{
			//approxPolyDP(Mat(contours[j]), contours_poly[j], 3, true);

			boundRect[j] = boundingRect(Mat(contours[j]));
			cout << boundRect[j].br() << ' ';
		}


		for (int i = 0; i < contours.size(); i++)
		{

			cout << contourArea(contours[i]) << ' ' << "next" << ' ';


			//rectangle(outputH, boundRect[i].tl(), boundRect[i].br(), (200, 143, 134), 2, 8, 0);

			drawContours(outputH, contours, i, (0, 0, 255), 2, 8, hierarchy, 0);








		}



		imshow("Video", frame);

		imshow("yeet", outputH);

		waitKey(0);

	





















		/*
		vector<vector<Point> > contours;



		vector<Vec4i> hierarchy;



		Mat Outputframe;
		Mat canny_output;
		inRange(frame,Scalar(170,170,170), Scalar(210,210,210), Outputframe);






		Canny(Outputframe, canny_output, 175, 210, 3);



		Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);

		threshold(canny_output, drawing, 175, 210, THRESH_BINARY);

		findContours(drawing, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));




		vector<vector<Point> > contours_poly(contours.size());







		*/
		/*
		for (size_t j = 0; j < contours.size(); j++)
		{
			//approxPolyDP(Mat(contours[j]), contours_poly[j], 3, true);
			boundRect[j] = boundingRect(Mat(contours[j]));
		}

		vector<Moments> mu(contours.size());
		for (int yeet = 0; yeet < contours.size(); yeet++)
		{
			mu[yeet] = moments(contours[yeet], false);
		}

		vector<Point2f> mc(contours.size());
		for (int yeet1 = 0; yeet1 < contours_poly.size(); yeet1++)
		{

			mc[yeet1] = Point2f(mu[yeet1].m10 / mu[yeet1].m00, mu[yeet1].m01 / mu[yeet1].m00);


		}

		for (size_t i = 0; i < contours.size(); i++)
		{

			//drawContours(frame, contours, (int)i, (200, 143, 134), 2, 8, hierarchy, 0, Point());\



			circle(frame, mc[i], 5, (200, 143, 134), 2, 8, 0);

		}


		for (int p = 0; p < contours_poly.size(); p++)
		{
			//rectangle(frame, boundRect[p].tl(), boundRect[p].br(), (200, 143, 134), 2, 8, 0);
		}*/






	return 0;
}


