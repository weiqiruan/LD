#include "pdw.h" 

int main()
{
	cv::Mat src;
	cv::VideoCapture capture("..\\data\\20170904162520.avi");//20170831153608_clip.avi20170904162520  20170831153608_clip.avi
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 720);

	int key = 0;
	Pdw pdw;

	while (key != 27)
	{
		capture >> src;
		pdw.frame = src;

		pdw.Detect();

		// Êä³ö±¨¾¯
		if (pdw.warnFlag == 0x01)
		{
			printf("\a");
			char dist[400];
			string distPrint;
			Point pos;
			sprintf_s(dist, "P warning");
		    distPrint = dist;
			pos = Point(700, 200);
			putText(src, distPrint, pos, CV_FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 3);

			pdw.warnFlag = 0;
		}
		if (pdw.result_out.size() != 0)
		{
			cout << pdw.result_out.size() << endl;
		}
		
		for (size_t i = 0; i < pdw.result_out.size(); i++)
		{
			rectangle(src, pdw.result_out[i], Scalar(255, 0, 0), 3);
			//cout << pdw.result_out[i] << endl;
		}

		imshow("res", src);
		key = waitKey(1);
	}

    return 0;
}

