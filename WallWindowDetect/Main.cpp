#include"iostream"
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("test.jpg", CV_LOAD_IMAGE_COLOR);
	MatIterator_<Vec3b> it, end;
	int i;
	int BlueMin = 255, BlueMax = 0;
	int GreenMin = 255, GreenMax = 0;
	int RedMin = 255, RedMax = 0;
	for (it = image.begin<Vec3b>(),i=0;i<300; it++,i++)
	{
		//cout << "Blue: " << (int)(*it)[0] << " Green: " << (int)(*it)[1] << " Red: " << (int)(*it)[2] << endl;
		if ((int)(*it)[0] < BlueMin)
			BlueMin = (int)(*it)[0];
		if ((int)(*it)[0] > BlueMax)
			BlueMax = (int)(*it)[0];
		if ((int)(*it)[1] < GreenMin)
			GreenMin = (int)(*it)[1];
		if ((int)(*it)[1] > GreenMax)
			GreenMax = (int)(*it)[1];
		if ((int)(*it)[2] < RedMin)
			RedMin = (int)(*it)[2];
		if ((int)(*it)[2] > RedMax)
			RedMax = (int)(*it)[2];
		//waitKey();
	}

	cout << "BlueMin:" << BlueMin << " BlueMax" << BlueMax << endl;
	cout << "GreenMin:" << GreenMin << " GreenMax:" << GreenMax << endl;
	cout << "RedMin:" << RedMin << " RedMax:" << RedMax << endl;


	waitKey();

	return 0;
}