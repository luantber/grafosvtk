#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkAlgorithmOutput.h>
#include <vtkSphereSource.h>
#include <vtkWorldPointPicker.h>
#include <tuple>


#include "interactor.h"

class Ventana
{
public:
	Ventana(){

		cout<<"aquiiii"<<endl;

		renderWindow->AddRenderer(renderer);
		renderWindowInteractor->SetInteractorStyle( style );
		renderWindowInteractor->SetRenderWindow ( renderWindow );
		renderWindowInteractor->Initialize();

	}

	

	//vtkSmartPointer<vtkWorldPointPicker> worldPointPicker = 
    //vtkSmartPointer<vtkWorldPointPicker>::New();

    vtkSmartPointer<vtkRenderer> renderer = 
    vtkSmartPointer<vtkRenderer>::New();

    vtkSmartPointer<vtkRenderWindow> renderWindow = 
    vtkSmartPointer<vtkRenderWindow>::New();

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
    vtkSmartPointer<vtkRenderWindowInteractor>::New();


    vtkSmartPointer<MouseInteractorStyleDoubleClick> style =
    vtkSmartPointer<MouseInteractorStyleDoubleClick>::New();
 	
 	

	
};