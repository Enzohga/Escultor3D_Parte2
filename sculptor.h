#ifndef SCULPTOR_H //Diretiva de compilação condicional 
#define SCULPTOR_H

struct Voxel 
{
  float r,g,b; // Cores
  float a;    // Transparencia
  bool isOn; // Incluso ou não
};

class sculptor 
{
protected:
  Voxel ***v;   // Matriz 3D 
  int nx,ny,nz; // Dimensoes
  float r,g,b,a; //  Cor e parametro alpha (transparencia)
public:		
  sculptor(int _nx, int _ny, int _nz); // Construtor
  ~sculptor(); // Destrutor
  void setColor(float nr, float ng, float nb, float nalpha); // Ativar cores 
  void putVoxel(int x, int y, int z); // Habilita voxel na posição determinada
  void cutVoxel(int x, int y, int z); // Desabilita voxel
  void writeOFF(char* filename); // Grava a escultura no formato OFF no arquivo filename
};

#endif // SCULPTOR_HPP

