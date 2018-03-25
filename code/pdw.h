#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <string>
#include <cmath>
#include <vector>
#include <stdio.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#pragma comment(lib, "winmm.lib")

using namespace cv;
using namespace std;

class Pdw
{
public:
	Pdw();

	vector<Rect> result_out;
	int curWarnFlag, preWarnFlag, warnFlag;  //±®æØ–≈∫≈
	Mat frame;			         // ‰»ÎÕº

	void Detect();
};
