#include <iostream>
#include "ventana.h"
//VTK

#include <vtkObjectFactory.h>

using namespace std;


vtkStandardNewMacro(MouseInteractorStyleDoubleClick);

int main(){

	Ventana ventana1;

	ventana1.renderWindowInteractor->Start();

	return 0;
}