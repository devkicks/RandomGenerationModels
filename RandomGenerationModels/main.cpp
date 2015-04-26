#include <iostream>

#include "include\opencv\cv.h"
#include "include\opencv\highgui.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

#define C_ROWS 501
#define C_COLS 501
#define C_RANDSIZE 1001
void displayUniformDistrbution(cv::Mat &inMat, int numItr = 1000000);

void displayUniformDistrbutioni(cv::Mat &inMat, int numItr = 1000000);
void displayGaussianDistrbutionCentralLimiti(cv::Mat &inMat, int numItr = 1000000);
void displayGaussianDistrbutionBoxMulleri(cv::Mat &inMat, int numItr = 1000000);

// uniform distribution generator 0 - 1 range
double uniformDistributionRN();

// uniform distribution generator 0 - cP range
int uniformDistributionRNi(int cP);

// gaussian distribution generation -cP - +cP range
int gaussianDistributionCentralLimitRNi(int cP);
int gaussianDistributionBoxMullerRNi(int cP);

int main ()
{
	cv::Mat displayMat;

	displayMat = cv::Mat::zeros(C_ROWS, C_COLS, CV_8UC1);
	displayUniformDistrbutioni(displayMat);
	cv::imshow("Uniform Distribution", displayMat);

	displayMat = cv::Mat::zeros(C_ROWS, C_COLS, CV_8UC1);
	displayGaussianDistrbutionCentralLimiti(displayMat);
	cv::imshow("Gaussian Distribution Central Limit", displayMat);


	displayMat = cv::Mat::zeros(C_ROWS, C_COLS, CV_8UC1);
	displayGaussianDistrbutionBoxMulleri(displayMat);
	cv::imshow("Gaussian Distribution Box Muller", displayMat);

	cv::waitKey(0);

	return 1;
}

void displayUniformDistrbution(cv::Mat &inMat, int numItr)
{
	int x, y;

	double cx, cy;
	cx = (double)(C_COLS+1)/2.0;
	cy = (double)(C_ROWS+1)/2.0;

	//std::cout << cx << ", " << cy << std::endl;


	for (int i = 0; i < numItr; i++)
	{
		

		x = (int)(uniformDistributionRN() * (cx-1));
		y = (int)(uniformDistributionRN() * (cy-1));

		//std::cout << x << ", " << y << std::endl;

		// display on image
		if (inMat.at<uchar>(y + cy, x + cx) < 255)
			inMat.at<uchar>(y + cy, x + cx) += 20;

	}
}


void displayUniformDistrbutioni(cv::Mat &inMat, int numItr)
{
	int x, y;

	int cx, cy;
	cx = (C_COLS + 1) / 2;
	cy = (C_ROWS + 1) / 2;

	//std::cout << cx << ", " << cy << std::endl;


	for (int i = 0; i < numItr; i++)
	{


		x = uniformDistributionRNi(cx-1);
		y = uniformDistributionRNi(cy-1);

		//std::cout << x << ", " << y << std::endl;

		// display on image
		if (inMat.at<uchar>(y + cy, x + cx) < 255)
			inMat.at<uchar>(y + cy, x + cx) += 20;

	}
}

// Central limit method for gaussian distribution generation
void displayGaussianDistrbutionCentralLimiti(cv::Mat &inMat, int numItr)
{
	int x, y;

	int cx, cy;
	cx = (C_COLS + 1) / 2;
	cy = (C_ROWS + 1) / 2;

	//std::cout << cx << ", " << cy << std::endl;


	for (int i = 0; i < numItr; i++)
	{


		x = gaussianDistributionCentralLimitRNi(cx - 1);
		y = gaussianDistributionCentralLimitRNi(cy - 1);

		//std::cout << x << ", " << y << std::endl;

		// display on image
		if (inMat.at<uchar>(y + cy, x + cx) < 255)
			inMat.at<uchar>(y + cy, x + cx) += 20;

	}
}

// box muller method for gaussian distribution generation
void displayGaussianDistrbutionBoxMulleri(cv::Mat &inMat, int numItr)
{
	int x, y;

	int cx, cy;
	cx = (C_COLS + 1) / 2;
	cy = (C_ROWS + 1) / 2;

	//std::cout << cx << ", " << cy << std::endl;


	for (int i = 0; i < numItr; i++)
	{


		x = gaussianDistributionBoxMullerRNi(cx - 1);
		y = gaussianDistributionBoxMullerRNi(cy - 1);

		//std::cout << x << ", " << y << std::endl;

		// display on image
		if (inMat.at<uchar>(y + cy, x + cx) < 255)
			inMat.at<uchar>(y + cy, x + cx) += 20;

	}
}



double uniformDistributionRN()
{
	double retVal = (-1 + (1 + 1)*((double)(std::rand()%C_RANDSIZE) / (double)C_RANDSIZE));
	//std::cout << retVal << std::endl;

	return retVal;
}

int uniformDistributionRNi(int cP)
{
	int retVal = -cP + (std::rand() % (2*cP));
	//std::cout << retVal << std::endl;

	return retVal;
}

double uniformDistribution()
{
	double retVal = ((double)(std::rand()) / (double)RAND_MAX);
	//std::cout << retVal << std::endl;

	return retVal;
}
int gaussianDistributionCentralLimitRNi(int cP)
{
	// implement central limit theorem
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	double nV = 0;
	for (int i = 0; i < 12; i++)
		nV += uniformDistribution();

	nV = nV - 6;

	int retVal = (cP) * (nV / 6);  // normalising the distribution by 6 so the effective range is between -1 to 1 * cP
	
	
	//std::cout << retVal << std::endl;
	
	return retVal;
}

int gaussianDistributionBoxMullerRNi(int cP)
{
	// implement box-muller method to convert uniform distribution to normal distribution
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	double u = uniformDistribution();
	double v = uniformDistribution();

	// box muller method takes u, v in range (0,1) hence we need to check for this
	while (u == 0 || u == 1)
		u = uniformDistribution();

	while (v == 0 || v == 1)
		v = uniformDistribution();

		

	// box muller acutally generates two values X1 and X2
	// for efficiency we can store the second value and return on second call
	// however since that is not the objective of this tutorial therefore I am just ignoring X2
	double X1 = sqrt(-2 * log(u)) * cos(2 * M_PI * v); 
	//double X2 = sqrt(-2 * log(u)) * sin(2 * M_PI * v);

	//std::cout << "u: " << u << ", v: " << v << std::endl;

	// re-normalising so that all the values stay within the limit -1 to 1
	X1 = X1 / 6;

	// converting the values to the defined window size
	int retVal = cP * X1;

	return retVal;
}