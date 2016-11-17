#include "vtkHeaders.h"
#include "interactor.h"

class Ventana
{
public:
	Ventana(){

        cout<<"Iniciando Grafos VTK ('Holi Boli')"<<endl;

        renderWindow->AddRenderer(renderer);
        renderWindowInteractor->SetInteractorStyle( style );
        renderWindowInteractor->SetRenderWindow ( renderWindow );
        renderWindowInteractor->SetPicker(worldPointPicker);
        renderWindowInteractor->Initialize();

        //Texto
        PolyDataMapper mapper =   PolyDataMapper::New();
        Follower follower = Follower::New();
        follower->SetMapper( mapper );

        VectorText textSource = VectorText::New();
        textSource->SetText( "Grafos VTK" );

        mapper->SetInputConnection( textSource->GetOutputPort() );
        renderer->AddActor(follower);

        style->SetDefaultRenderer(renderer);


        // Fin Constructor

	}

	WorldPointPicker worldPointPicker = WorldPointPicker::New();
    Renderer renderer = Renderer::New();
    RenderWindow renderWindow = RenderWindow::New();
    RenderWindowInteractor renderWindowInteractor = RenderWindowInteractor::New();
    vtkSmartPointer<MouseInteractorStyleDoubleClick> style = vtkSmartPointer<MouseInteractorStyleDoubleClick>::New();
	
};
