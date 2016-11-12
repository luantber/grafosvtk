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
#include <vtkWorldPointPicker.h>


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
		  renderWindowInteractor->SetPicker(worldPointPicker);

	}

	

	//vtkSmartPointer<vtkWorldPointPicker> worldPointPicker = 
    //vtkSmartPointer<vtkWorldPointPicker>::New();

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

    vtkSmartPointer<vtkSphereSource> sphereSource = 
    vtkSmartPointer<vtkSphereSource>::New();

    sphereSource->SetCenter(get<0>(nuevo), get<1>(nuevo), get<2>(nuevo));
    sphereSource->SetRadius(5.0);
    sphereSource->Update();

    add(sphereSource->GetOutputPort());

  }


  void add(vtkSmartPointer<vtkAlgorithmOutput> data){
      
    vtkSmartPointer<vtkPolyDataMapper> mapper = 
    vtkSmartPointer<vtkPolyDataMapper>::New();

    mapper->SetInputConnection(data);

    vtkSmartPointer<vtkActor> actor = 
    vtkSmartPointer<vtkActor>::New();

    actor->SetMapper(mapper);

    renderer->AddActor(actor); 
    renderWindow->Render();

    //this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(actor);
    //this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->Render();

    }


	
};