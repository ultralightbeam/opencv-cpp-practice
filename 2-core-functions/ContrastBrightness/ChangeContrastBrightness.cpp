#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;

double alpha; /*< Simple contrast control */
int beta;  /*< Simple brightness control */
int main( int argc, char** argv )
{
    if (argc != 2) {
        return -1;
    }
    
    Mat image = imread( argv[1] );
    Mat new_image = Mat::zeros( image.size(), image.type() );
    cout << " Basic Linear Transforms " << endl;
    cout << "-------------------------" << endl;
    cout << "* Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;
    if (alpha < 1.0 || alpha > 3.0) {
        cout << "not a valid alpha value" << endl;
        return -1;
    }
    cout << "* Enter the beta value [0-100]: ";
    cin >> beta;
    if (beta < 0.0 || beta > 100.0) {
        cout << "not a valid beta value" << endl;
        return -1;
    }
    for( int y = 0; y < image.rows; y++ ) {
        for( int x = 0; x < image.cols; x++ ) {
            for( int c = 0; c < 3; c++ ) {
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("New Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);
    imshow("New Image", new_image);
    waitKey();
    return 0;
}
