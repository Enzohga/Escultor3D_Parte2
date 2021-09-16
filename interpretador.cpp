#include "interpretador.h"

Interpretador::Interpretador()
{

}

vector <FiguraGeometrica*> Interpretador::parse(string filename)
{
    vector <FiguraGeometrica*> figs;
    ifstream fin;
    stringstream ss;
    string s, token;

    fin.open(filename.c_str());

    if(!fin.is_open())
	{ 
        cout<<"\"" <<filename <<"\" "<< "- Nao foi encontrado!"<<endl;
        exit(0);
    }

    while(getline(fin, s)){  
        ss.clear(); 
        ss.str(s); 
        ss>>token;
        if(token.compare("dim") == 0)
		{
            ss >> dimx >> dimy >> dimz;
        }
        else if(token.compare("putvoxel") == 0)
		{
            int x0, y0, z0;
            ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
            figs.push_back(new putVoxel(x0,y0,z0,r,g,b,a));
        }
        else if(token.compare("putbox") == 0)
		{
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));

        }
        else if(token.compare("putsphere") == 0)
		{
            int x0, y0, z0, radius;
            ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> a;
            figs.push_back(new putSphere(x0,y0,z0,radius,r,g,b,a));

        }
        else if(token.compare("putellipsoid") == 0)
		{
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
            figs.push_back(new putEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,a));
        }
        else if(token.compare("cutvoxel") == 0)
		{
            int x0, y0, z0;
            ss >> x0 >> y0 >> z0;
            figs.push_back(new cutVoxel(x0,y0,z0));
        }
        else if(token.compare("cutbox") == 0)
		{
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1; 
            figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        }
        else if(token.compare("cutsphere") == 0)
		{
            int x0, y0, z0, radius;
            ss >> x0 >> y0 >> z0 >> radius;
            figs.push_back(new cutSphere(x0,y0,z0,radius));
        }
        else if(token.compare("cutellipsoid") == 0)
		{
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz;
            figs.push_back(new cutEllipsoid(x0,y0,z0,rx,ry,rz));
        }
    }

    fin.close();

    return figs;
 }
 int Interpretador::getDimx()
{
    return dimx;
}

int Interpretador::getDimy()
{
    return dimy;
}

int Interpretador::getDimz()
{
    return dimz;
}
