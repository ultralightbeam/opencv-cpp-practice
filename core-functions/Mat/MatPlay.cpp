
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

static void help()
{
    cout << "\nThis program prints sample Mat\n" << endl;
}

int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{help | | }{@input | | }");
    
    if(parser.has("help")) {
        help();
        return 1;
    }
    
    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    cout << "M = " << endl << " " << M << endl << endl;
 
    return 0;
}
