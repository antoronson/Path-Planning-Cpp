#include <iostream>
//#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <tuple>


//#define PI 3.1415925
//const double pi = 4. * atan(1.);
#define pi acos(-1.0)

using namespace std;
using std::vector;

//Base Class - to set the dimension of the room (rectangular or square)
class Room
{
	public:
		void setDimension(double l, double w, double x_h, double y_h, double x_t, double y_t);
	protected:
		double length;	// Length of the room
		double width;	// Width of the room
		double x_home, y_home;// My Home position
		double x_target, y_target;// My target position

};

class Circle: public Room
{
	public:
		double path(void);// function to calculate the path

	protected:

		int theta = 0;// minimum distance theta
		double x_pos, y_pos;// current position of me
		//vector <double> x_cor, y_cor;// my trajectory
		
};

void Room::setDimension(double l, double w, double x_h, double y_h, double x_t, double y_t)
{
	length = l;
	width = w;
	x_home = x_h;
	y_home = y_h;
	x_target = x_t;
	y_target = y_t;
	//double pos[2][360] = {{0}};// The nearest distance around me where i can move
	//double dist[360] = {0};// euler distance from my next possible moves
	//double temp_smallest = 0;// smallest distance
	//double x_temp_pos = 0, y_temp_pos = 0;// temporary position of me. Useful when loop terminates inbetween radius
}

double Circle::path(void)
{
	cout<< "Hello";
	x_pos = x_home;
	y_pos = y_home;
	double pos[2][360] = {{0}};// The nearest distance around me where i can move
			double radius[10] = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1};// variable radius to form circle. Furure for collision detection
	double dist[360];
					vector <double> x_cor, y_cor;// my trajectory
	double temp_smallest = 0;
	double x_temp_pos = 0, y_temp_pos = 0;
	

	while ((x_home != x_target) && (y_home != y_target))// When I am not overshooted
	{
		int n = sizeof(radius);
		for (int i = 0; i<n; i++)// To navigate inside the variable radius
		{ cout<<i;
			for(int j = 0; j < 360; j++)// To construct nearby position for different radius
			{
				pos[0][j] = x_pos + (radius[i] * cos(j * pi/180));//x position
				pos[1][j] = y_pos + (radius[i] * sin(j * pi/180));// y position 
				dist[j]	 = pow((pow(pos[0][j],2) + pow(pos[i][j],2) ),0.5);// euler distance 
				if (j == 0)
				{
					temp_smallest = dist[j];
				}
				if (dist[j] < temp_smallest)
				{
					temp_smallest = dist[j];
					theta = j;
				}
			}
			if(temp_smallest == 0)// When euler distance is zero
				{
					break;
				}
			else
			{
				x_temp_pos = pos[0][theta];
				y_temp_pos = pos[1][theta];
			}	
					
		}
				x_pos = pos[0][theta];
				y_pos = pos[1][theta];
				if ( x_pos > x_target && y_pos > y_target)// When i Overshooted. 
				{
				x_cor.push_back(x_temp_pos);
				y_cor.push_back(y_temp_pos);	
				break;
				}
				x_cor.push_back(x_pos);// X position vector. 
				y_cor.push_back(y_pos);// Y position vector. 
				
				
		
	}
	//return  make_tuple(x_cor, y_cor);
	//for (int i = 0; i < x_cor.size(); i++)
	//{
	//	cout<<x_cor[i]<<"\t"<<y_cor[i];
	//}
}

int main ()
{
//vector <double> x_position, y_position;
Circle C;
C.setDimension(10,10,1,1,5,5);
cout<<"the dimensions are::";
C.path();
//tie(x_position, y_position) = C.path();

return 0;
}
