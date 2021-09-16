#include <iostream>
#include "figurageometrica.h"
#include "interpretador.h"
#include <vector>

using namespace std;

int main()
{
    sculptor *s1; 

    vector<FiguraGeometrica*> figs;

    Interpretador parser; 

    figs = parser.parse("C:/Escultor3D/dados2.txt");

    s1 = new sculptor(parser.getDimx(),parser.getDimy(),parser.getDimz());

    for(size_t i=0; i<figs.size(); i++)
	{ 
        cout<<"Draw"<<endl;
        figs[i]->draw(*s1);
    }

    s1->writeOFF((char*)"C:/Escultor3D/Figura2.off"); 

    for(size_t i=0; i<figs.size(); i++)
	{
        delete figs[i];
    }

    delete s1;

    cout << "Fim!!!!";
    return 0;
}
