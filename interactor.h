
#include "Grafo.h"
class MouseInteractorStyleDoubleClick : public vtkInteractorStyleTrackballCamera
{


  public:
    
    Grafo<tuple<double,double,double>,int> grafo;
     
    static MouseInteractorStyleDoubleClick* New();
    vtkTypeMacro(MouseInteractorStyleDoubleClick, vtkInteractorStyleTrackballCamera);
 
   	virtual void OnLeftButtonDown() {
   	cout<<"Hola mundito :D !!!te queremos ! <3 "<<endl;
   
 
    this->Interactor->GetPicker()->Pick(this->Interactor->GetEventPosition()[0], 
                         this->Interactor->GetEventPosition()[1], 
                         0,  // always zero.
                         this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
      double picked[3];
      this->Interactor->GetPicker()->GetPickPosition(picked);
      std::cout << "Picked value: " << picked[0] << " " << picked[1] << " " << picked[2] << std::endl;

      crearEsfera(picked[0],picked[1],picked[2]);

    
    vtkInteractorStyleTrackballCamera::OnLeftButtonDown();

    }




  void crearEsfera(double x,double y,double z){

    tuple<double,double,double> nuevo = make_tuple(x,y,z);
    grafo.addNodo(nuevo);

    SphereSource sphereSource = SphereSource::New();

    sphereSource->SetCenter(get<0>(nuevo), get<1>(nuevo), get<2>(nuevo));
    sphereSource->SetRadius(5.0);
    sphereSource->Update();

    add(sphereSource->GetOutputPort());

  }


  void add(AlgorithmOutput data){
      
    PolyDataMapper  mapper = PolyDataMapper ::New();

    mapper->SetInputConnection(data);

    Actor actor = Actor ::New();

    actor->SetMapper(mapper);
    
    this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(actor);
    this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->Render();

    }


};

