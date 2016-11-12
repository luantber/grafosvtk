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

#include "Grafo.h"
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

	Grafo<tuple<double,double,double>,int> grafo;

	vtkSmartPointer<vtkWorldPointPicker> worldPointPicker = 
    vtkSmartPointer<vtkWorldPointPicker>::New();

    vtkSmartPointer<vtkRenderer> renderer = 
    vtkSmartPointer<vtkRenderer>::New();

    vtkSmartPointer<vtkRenderWindow> renderWindow = 
    vtkSmartPointer<vtkRenderWindow>::New();

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
    vtkSmartPointer<vtkRenderWindowInteractor>::New();


    vtkSmartPointer<MouseInteractorStyleDoubleClick> style =
    vtkSmartPointer<MouseInteractorStyleDoubleClick>::New();
 	
 	void crearEsfera(double x,double y,double z){


	 	tuple<double,double,double> nuevo = make_tuple(x,y,z);

	 	grafo.addNodo(nuevo);

	 	vtkSmartPointer<vtkSphereSource> sphereSource = 
	    vtkSmartPointer<vtkSphereSource>::New();
	 	sphereSource->SetCenter(get<0>(nuevo), get<1>(nuevo), get<2>(nuevo));
	  	sphereSource->SetRadius(5.0);
	 	sphereSource->Update();

	 	this->add(sphereSource->GetOutputPort());

 	}


    void add(vtkSmartPointer<vtkAlgorithmOutput> data){
    	
		vtkSmartPointer<vtkPolyDataMapper> mapper = 
		vtkSmartPointer<vtkPolyDataMapper>::New();

		mapper->SetInputConnection(data);

		vtkSmartPointer<vtkPolyDataMapper> mapper2 = 
		vtkSmartPointer<vtkPolyDataMapper>::New();

		vtkSmartPointer<vtkActor> actor = 
		vtkSmartPointer<vtkActor>::New();

		actor->SetMapper(mapper);

		renderer->SetBackground(1,1,1); // Background color white
		renderer->AddActor(actor); 

		renderWindow->Render();
		//renderWindowInteractor->Start();
		renderer->ResetCamera();
    }

	
};