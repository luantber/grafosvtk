#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRendererCollection.h>
#include <vtkPointPicker.h>
#include <vtkCoordinate.h>

class MouseInteractorStyleDoubleClick : public vtkInteractorStyleTrackballCamera
{
  public:
     
    static MouseInteractorStyleDoubleClick* New();
    vtkTypeMacro(MouseInteractorStyleDoubleClick, vtkInteractorStyleTrackballCamera);
 
   	virtual void OnLeftButtonDown() {
   		cout<<"Hola mundito :D !!!te queremos ! <3 "<<endl;
      
      //this->Interactor->GetPicker()->Pick(this->Interactor->GetEventPosition()[0], 
      //                   this->Interactor->GetEventPosition()[1], 
      //                   0,  // always zero.
      //                   this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());

      //double picked[3];
      //this->Interactor->GetPicker()->GetPickPosition(picked);
      //cout << picked[0] << " " << picked[1] << " " << picked[2] << endl;

      vtkSmartPointer<vtkCoordinate> coordinate = 
        vtkSmartPointer<vtkCoordinate>::New();
      coordinate->SetCoordinateSystemToDisplay();
      coordinate->SetValue(this->Interactor->GetEventPosition()[0],this->Interactor->GetEventPosition()[1],0);
 
      // This doesn't produce the right value if the sphere is zoomed in???
      double* world = coordinate->GetComputedWorldValue(this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
      std::cout << "World coordinate: " << world[0] << ", " << world[1] << ", " << world[2] << std::endl;
 



      tuple<double,double,double> nuevo = make_tuple(world[0],world[1],world[2]);

      //grafo.addNodo(nuevo);

    vtkSmartPointer<vtkSphereSource> sphereSource = 
      vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetCenter(get<0>(nuevo), get<1>(nuevo), get<2>(nuevo));
      sphereSource->SetRadius(5.0);
    sphereSource->Update();

    vtkSmartPointer<vtkPolyDataMapper> mapper = 
    vtkSmartPointer<vtkPolyDataMapper>::New();

    mapper->SetInputConnection(sphereSource->GetOutputPort());


    vtkSmartPointer<vtkActor> actor = 
    vtkSmartPointer<vtkActor>::New();

    actor->SetMapper(mapper);

    this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(actor);
    this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->Render();
    //this->Interactor->GetRenderWindow()->Render();

   


   		vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
   	}
};

