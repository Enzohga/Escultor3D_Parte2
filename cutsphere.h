#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class cutSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~cutSphere();
	void draw(sculptor &t);
};

#endif // CUTSPHERE_H
