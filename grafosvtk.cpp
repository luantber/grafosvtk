#include <iostream>



#include "ventana.h"
//VTK


#include <vtkPointPicker.h>
#include <vtkCamera.h>
#include <vtkObjectFactory.h>

using namespace std;


vtkStandardNewMacro(MouseInteractorStyleDoubleClick);

int main(){

	Ventana ventana1;
	ventana1.crearEsfera(3,4,5);
	ventana1.crearEsfera(2,0.5,23);
	ventana1.crearEsfera(0,0,0);

	ventana1.renderWindowInteractor->Start();

	return 0;
}