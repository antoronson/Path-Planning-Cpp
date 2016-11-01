#incude <iostream>
#include <math.h>
#include <stdlib>
#include <cmath>

#define PI 3.1415925

using namespace std;

//Base Class - to set the dimension of the room (rectangular or square)
class Room
{
	public:
		void setDimension(float l, float w, float x_h, float y_h, float x_t, float y_t);
	protected:
		float length;
		float width;
		float x_home, y_home;
		float x_target, y_target;

};

class Circle: public Room
{
	public:
		float path();
	protected:
		float radius[10] = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1};
		float theta;
		float x_pos, y_pos;
		vector <float> x_cor, y_cor;
		
};

void setDimension(float l, float w, float x_h, float y_h, float x_t, float y_t)
{
	length = l;
	width = w;
	x_home = x_h;
	y_home = y_h;
	x_target = x_t;
	y_target = y_t;
}