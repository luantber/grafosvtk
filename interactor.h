#include "Grafo.h"
class MouseInteractorStyleDoubleClick : public vtkInteractorStyleTrackballCamera
{

  public:


    
    Grafo<tuple<double,double,double>,int> grafo;
    int clicks = 0;
    int clickTubo = 0;
    int * inicio;
    int * destino;
    double x = 0,y = 0, z= 0;
    Actor pickedActor = 0;
    vtkProperty * pickedProperty = vtkProperty::New();
     
    static MouseInteractorStyleDoubleClick* New();
    vtkTypeMacro(MouseInteractorStyleDoubleClick, vtkInteractorStyleTrackballCamera);
 
    virtual void OnMouseMove(){

      //Resetea contador de clicks si se movio el mouse
      clicks = 0;
      
      vtkInteractorStyleTrackballCamera::OnMouseMove();
    }

    virtual void OnRightButtonDown(){
      clicks = 0;
      int * clickPos = this->GetInteractor()->GetEventPosition();
      PropPicker picker = PropPicker::New();

      picker->Pick(clickPos[0],clickPos[1],0,this->GetDefaultRenderer());
      cout<<"posicion "<<clickPos[0]<<endl;

      //Deselecciona
      if(pickedActor){
        pickedActor->GetProperty()->DeepCopy(pickedProperty);
        cout << "Devuelve las propiedades"<<endl;
      }

      pickedActor = picker->GetActor();

      //Selecciona un Actor
      if(pickedActor){
        cout << "colorea rojo"<<endl;
        pickedProperty->DeepCopy(pickedActor->GetProperty());
        pickedActor->GetProperty()->SetColor(1,0,0);
        pickedActor->GetProperty()->SetDiffuse(1);
        pickedActor->GetProperty()->SetSpecular(0);
        
        if (clickTubo == 1)
        {

          picker->Pick(clickPos[0],clickPos[1],0,this->GetDefaultRenderer());
          auto seleccionado = picker->GetActor();
          double * centro = seleccionado->GetCenter();

          cout<<endl;
          cout << centro[0] << " "<< centro[1] << " "<<centro[2] ;
          cout<< x <<" "<<y<<" "<<z<<" Posiciones inciales" <<endl;
          //cout<<picked1[0]<<" "<<picked1[1]<<" "<<endl;
          cout<<endl;
          CrearTubo(x,y,z,centro[0],centro[1],centro[2]);
          clickTubo = 0;

        }

        else if (clickTubo == 0)
        {
          picker->Pick(clickPos[0],clickPos[1],0,this->GetDefaultRenderer());
          auto seleccionado = picker->GetActor();
          double * centro = seleccionado->GetCenter();
          
          x = centro[0];
          y = centro[1];
          z = centro[2];

          clickTubo++;
          cout<<endl;
          inicio = clickPos;
          cout<<"aqui aumenta el tubo posicion inicial"<<inicio[0]<<endl;
          cout<<endl;
        }



      }
      
      vtkInteractorStyleTrackballCamera::OnRightButtonDown();
    }

   	virtual void OnLeftButtonDown() {
   	  //cout<<"Hola mundito :D !!!te queremos ! <3 "<<endl;
      clickTubo = 0;
      clicks++;
      int * clickPos = this->Interactor->GetEventPosition();
      
      //Borra Seleccion
      if(pickedActor){
        pickedActor->GetProperty()->DeepCopy(pickedProperty);
        cout << "Devuelve las propiedades"<<endl;
      }
      

      //Doble Click Crea Esfera
      if(clicks>=2){
        cout << "Doble Click" << endl;
        this->Interactor->GetPicker()->Pick(clickPos[0],clickPos[1],clickPos[2],this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
        double picked[3];
        this->Interactor->GetPicker()->GetPickPosition(picked);

        crearEsfera(picked[0],picked[1],picked[2]);
//        cout<<"esfera   "<<picked[0]<<" "<<picked[1]<<endl;
        clicks=0;
        clickTubo = 0;
      }
      
      //Fin Crear Esfera
    
      vtkInteractorStyleTrackballCamera::OnLeftButtonDown();

    }

void CrearTubo(double x1,double y1, double z1, double x2, double y2, double z2){

  LineSource linea = LineSource::New();
  linea->SetPoint1(x1 ,y1 ,z1);
  linea->SetPoint2(x2 ,y2 ,z2);

  PolyDataMapper lineaMapper = PolyDataMapper::New();
  lineaMapper->SetInputConnection(linea->GetOutputPort());

  Actor lineaActor = Actor::New();
  lineaActor->SetMapper(lineaMapper);

  TubeFilter tubo = TubeFilter::New();
  tubo->SetInputConnection(linea->GetOutputPort());
  tubo->SetRadius(0.6);
  tubo->SetNumberOfSides(50);
  tubo->Update();

  PolyDataMapper tuboMapper = PolyDataMapper::New();
  tuboMapper->SetInputConnection(tubo->GetOutputPort());

  Actor tuboActor = Actor::New();
  tuboActor->SetMapper(tuboMapper);

  this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(tuboActor);
  this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->Render();
  this->Interactor->GetRenderWindow()->Render();



}


  void crearEsfera(double x,double y,double z){

    tuple<double,double,double> nuevo = make_tuple(x,y,z);
    grafo.addNodo(nuevo);

    SphereSource sphereSource = SphereSource::New();

    sphereSource->SetCenter(get<0>(nuevo), get<1>(nuevo), get<2>(nuevo));
    sphereSource->SetRadius(5.0);
    sphereSource->SetPhiResolution(11);
    sphereSource->SetThetaResolution(21);
    sphereSource->Update();

    add(sphereSource->GetOutputPort());

  }


  void add(AlgorithmOutput data){
      
    PolyDataMapper  mapper = PolyDataMapper ::New();

    mapper->SetInputConnection(data);

    Actor actorEsfera = Actor ::New();

    double r,g,b;
    r = vtkMath::Random(0.5,2.5);
    g = vtkMath::Random(0.5,2.5);
    b = vtkMath::Random(0.5,2.5);

    actorEsfera->GetProperty()->SetDiffuseColor(r,g,b);
    actorEsfera->GetProperty()->SetDiffuse(0.4);
    actorEsfera->GetProperty()->SetSpecular(.5);
    actorEsfera->GetProperty()->SetSpecularColor(0.5,0.5,0.5);
    actorEsfera->GetProperty()->SetSpecularPower(20.0);

    actorEsfera->SetMapper(mapper);
    
    this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(actorEsfera);
    this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->Render();
    this->Interactor->GetRenderWindow()->Render();
    }


};


