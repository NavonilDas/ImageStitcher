#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <iostream>


int calcHomographyMat(cv::Mat img1, cv::Mat img2,cv::Mat &result) {
	cv::Mat gray1;
	cv::Mat gray2;
	cv::cvtColor(img1, gray1, cv::COLOR_BGR2GRAY);
	cv::cvtColor(img2, gray2, cv::COLOR_BGR2GRAY);
	if(!gray1.data || !gray2.data) {

	}
	return 0; // Sucessfully Calculated
}

int main(int argc, char** argv)
{
	cv::Mat result;
	std::vector<cv::String> filenames;
	std::vector< cv::Mat > imgs = std::vector< cv::Mat >();
	cv::String dir = "E:\\InputImages";
	cv::glob(dir, filenames);
	int64 start = 0, end = 0;

	for (int i = 0; i < filenames.size(); i++) {
		cv::Mat src = cv::imread(filenames[i], cv::IMREAD_COLOR);
		//if (src.data) {
			imgs.push_back(src);
		// }
	}
	cv::Stitcher stitcher = cv::Stitcher::createDefault(true);
	
	start = cv::getTickCount();
	cv::Stitcher::Status status = stitcher.stitch(imgs, result);
	end = cv::getTickCount();


	std::cout << "Processing Time : " << ((end - start) / cv::getTickFrequency()) << std::endl;
	if (cv::Stitcher::OK == status) 
	{
		std::cout << "Image Saved";
		cv::imwrite("E:\\result.jpg",result);
	}
	else {
		std::cerr << "Can't be Stiched";
	}

//	while (true);
	return 0;
}