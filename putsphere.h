#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class putSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~putSphere();
    void draw(sculptor &t);
};

#endif // PUTSPHERE_H
