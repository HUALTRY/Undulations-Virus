#include "Undulations.h"



float ImageProcessing::GetDistance(float x,float y,float w,float h,bool mode = true)
{
	nX = (x - (w / 2));
    nY = (y - (h / 2));
	if(mode)
	{
        return (float)sqrt((nX * nX) + (nY * nY));
	}
	else
	{
		float a = 1.f;
		float b = h / w; 
		return (float)sqrt(((nX * nX) / (a * a)) + ((nY * nY) / (b * b)));
	}
}


void ImageProcessing::Convex(float x,float y,float w,float h,float strength, float distance,float *_x,float *_y)
{
    cX = w / 2;
    cY = h / 2;
    dX = x - cX;
    dY = y - cY;

    scale = 1.f - (strength * (float)exp(-distance / (w / 10.f)));

    *_x = cX + (scale * dX);
    *_y = cY + (scale * dY);
}


void ImageProcessing::Concave(float x,float y,float w,float h,float strength,float distance,float *_x,float *_y)
{
    cX = w / 2;
    cY = h / 2;
    dX = x - cX;
    dY = y - cY;

    scale = 1.f - (strength * distance / (float)_hypot((double)cX, (double)cY));

    *_x = cX + (scale * dX);
    *_y = cY + (scale * dY);
}


void ImageProcessing::Wave(float strength, float d,float wavenum,float step, float* _x, float* _y, bool mode = true)
{
    *_x = (float)(mode ? strength * sin((d / wavenum) - step) : strength * tan((d / wavenum) - step));
    *_y = (float)(mode ? strength * cos((d / wavenum) - step) : 0);
}
