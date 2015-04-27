#include <iostream>
#include <stdlib.h>
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
void displayMixtureDistributionBoxMulleri(cv::Mat &inMat, int numItr = 1000000);
void displayCustomDistributioni(cv::Mat &inMat, int numItr = 1000000);
// uniform distribution generator 0 - 1 range
double uniformDistributionRN();

// uniform distribution generator 0 - cP range
int uniformDistributionRNi(int cP);

// gaussian distribution generation -6 - +6 range
double centralLimit();
double boxMuller();

// gaussian distribution generation -cP - +cP range
int gaussianDistributionCentralLimitRNi(int cP);
int gaussianDistributionBoxMullerRNi(int cP);

// mixture distribution generation -cP - +cP range
int mixtureDistribution(int cP);

// a custom distribution
void myCustomDistribution(int cP, int &retX, int &retY);


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

	displayMat = cv::Mat::zeros(C_ROWS, C_COLS, CV_8UC1);
	displayMixtureDistributionBoxMulleri(displayMat);
	cv::imshow("Mixture Distribution Box Muller", displayMat);

	displayMat = cv::Mat::zeros(C_ROWS, C_COLS, CV_8UC1);
	displayCustomDistributioni(displayMat);
	cv::imshow("Custom Distribution", displayMat);


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

void displayMixtureDistributionBoxMulleri(cv::Mat &inMat, int numItr)
{
	int x, y;

	int cx, cy;
	cx = (C_COLS + 1) / 2;
	cy = (C_ROWS + 1) / 2;

	//std::cout << cx << ", " << cy << std::endl;


	for (int i = 0; i < numItr; i++)
	{


		x = mixtureDistribution(cx - 1);
		y = mixtureDistribution(cy - 1);

		//std::cout << x << ", " << y << std::endl;

		// display on image
		if (inMat.at<uchar>(y + cy, x + cx) < 255)
			inMat.at<uchar>(y + cy, x + cx) += 20;

	}
}

void displayCustomDistributioni(cv::Mat &inMat, int numItr)
{
	int x, y;

	int cx, cy;
	cx = (C_COLS + 1) / 2;
	cy = (C_ROWS + 1) / 2;

	//std::cout << cx << ", " << cy << std::endl;


	for (int i = 0; i < numItr; i++)
	{


		myCustomDistribution(cx - 1, x, y);
		//y = myCustomDistribution(cy - 1);

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

double centralLimit()
{
	// implement central limit theorem
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	double nV = 0;
	for (int i = 0; i < 12; i++)
		nV += uniformDistribution();

	nV = nV - 6;

	return nV;
}
int gaussianDistributionCentralLimitRNi(int cP)
{
	
	double nV = centralLimit();
	int retVal = (cP) * (nV / 6);  // normalising the distribution by 6 so the effective range is between -1 to 1 * cP
	
	
	//std::cout << retVal << std::endl;
	
	return retVal;
}

double boxMuller()
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

	return X1;
}
int gaussianDistributionBoxMullerRNi(int cP)
{
	double X1 = boxMuller();

	//std::cout << "u: " << u << ", v: " << v << std::endl;

	// re-normalising so that all the values stay within the limit -1 to 1
	X1 = X1 / 6;

	// converting the values to the defined window size
	int retVal = cP * X1;

	return retVal;
}

int mixtureDistribution(int cP)
{
	startLabel:
	// take two normal distributions and add them with weights and varying mean
	double nD1, nD2;
	nD1 = boxMuller();
	nD2 = boxMuller();

	// adjust the mean for both
	nD1 = nD1 - 1.5 ;
	nD2 = nD2 + 1.5;

	// compute mixture distribution
	double randSel = rand() % 2;
	double mD = 0;

	if( randSel )
		mD = nD1 /3;
	else
		mD = nD2 /3;

	
	if (mD > 1.0 || mD < -1)
		goto startLabel;

	//std::cout << "nD1: " << nD1 << " nD2: " << nD2 << " mD: " << mD << std::endl;

	// get return value
	int retVal = mD * cP;

	return retVal;

}

void myCustomDistribution(int cP, int &retX, int &retY)
{
	double X, Y;

	myCustomStart:
	X = boxMuller();
	Y = boxMuller();

	// re-normalising so that all the values stay within the limit -1 to 1
	//X = X / 2.3;
	//Y = Y / 2.3;

	// Drawing values from the Multivariate normal distribution
	// https://en.wikipedia.org/wiki/Multivariate_normal_distribution
	// A
	cv::Mat covMat = cv::Mat::zeros(2, 2, CV_32FC1);
	covMat.at<float>(0, 0) = 1.0;
	covMat.at<float>(1, 1) = 1.0;

	covMat.at<float>(1, 0) = 0.0;
	covMat.at<float>(0, 1) = 0.0;
	
	// Cholesky() with OpenCV - requires rescaling
	// code take from stack overflow
	// http://stackoverflow.com/questions/7861772/how-to-perform-lu-decomposition-with-opencv
	cv::Mat chol = covMat.clone();
	if(cv::Cholesky(chol.ptr<float>(), chol.step, chol.cols, 0, 0, 0))
	{
		cv::Mat diagElem = chol.diag();
		for( int e = 0; e < diagElem.rows; ++e)
		{
			float elem = diagElem.at<float>(e);
			chol.row(e) *= elem;
			chol.at<float>(e, e) = 1.0f / elem;
		}
	}
	// Cholesky decomposition code finished - we can use chol as A in equation x = mu + Az for multivariate normal distribution generation
	cv::Mat zMat = cv::Mat::zeros(2, 1, CV_32FC1);
	zMat.at<float>(0, 0) = X;
	zMat.at<float>(1, 0) = Y;

	cv::Mat xMat = cv::Mat::zeros(2, 1, CV_32FC1);

	xMat = chol * zMat;

	//std::cout << chol <<std::endl;

	//std::cout << "Original Values: X: " << X << " Y: " << Y << std::endl;
	//std::cout << "MultiVariate Vl: X: " << xMat.at<float>(0,0) << " Y: " << xMat.at<float>(1,0) << std::endl;

	// renormalising the xMat to have a Mat within the range -1 to 1
	xMat = xMat / 2.3;
	//std::cout << xMat << std::endl;

	double centralSpace = 0.05;

	double xO = xMat.at<float>(0, 0);
	double yO = xMat.at<float>(1, 0);

	double radiusCheck = std::sqrt(std::pow(xO, 2) + std::pow(yO, 2));

	if(xO > 1 || xO < -1 || yO > 1 || yO < -1 || (radiusCheck < centralSpace && radiusCheck >-centralSpace))
		goto myCustomStart;
	// converting the values to the defined window size
	retX = cP * xO;
	retY = cP * yO;

	//return retVal;
}