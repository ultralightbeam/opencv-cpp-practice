#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

static void help()
{
    cout << "\nThis program loads an image and saves a version of it.\n" << endl;
}

int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{help h | | }{@input | | }");
    
    if (argc != 2) {
        cout << "not a valid argc" << endl;
        return -1;
    }
    
    if (parser.has("help")) {
		help();
	}
    
    string filename = parser.get<string>(0);
    Mat im = imread(filename, 1);
    Mat gray;
    cvtColor(im, gray, COLOR_BGR2GRAY);
    
    imwrite("gray_image.jpg", gray);
    
    namedWindow("raw", WINDOW_AUTOSIZE);
    namedWindow("gray", WINDOW_AUTOSIZE);
    imshow("raw", im);
    imshow("gray", gray);
    
    waitKey(0);
    
	return 0;
}
