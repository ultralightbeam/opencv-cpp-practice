#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

static void help() {
    cout << "\nThis program performs a simple image display\n" << endl;
}

	
int main(int argc, char** argv )
{
    CommandLineParser parser(argc, argv, "{help h | | }{ @input | | }");
    if (parser.has("help"))
    {
        help();
        return 0;
    }
    
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    
    
    Mat image = imread( parser.get<string>(0), 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}
