#ifndef _IMAGEPROCESSING_
#define _IMAGEPROCESSING_


class ImageProcessing
{
private:
	float nX,nY;
    float cX, cY;
    float dX, dY;
    float distance;
    float scale;

public:
	ImageProcessing()
	{
		nX = 0;
		nY = 0;
		cX = 0, cY = 0;
		dX = 0, dY = 0;
		distance = 0;
		scale = 0;
	}
	float GetDistance(float,float,float,float,bool);
	void Convex(float,float,float,float,float, float,float*,float*);
	void Concave(float,float,float,float,float, float,float*,float*);
	void Wave(float, float, float,float, float*, float*,bool);
};

#endif