#include <vtkInteractorStyleTrackballCamera.h>


class MouseInteractorStyleDoubleClick : public vtkInteractorStyleTrackballCamera
{
  public:
     
    static MouseInteractorStyleDoubleClick* New();
    vtkTypeMacro(MouseInteractorStyleDoubleClick, vtkInteractorStyleTrackballCamera);
 
   	virtual void OnLeftButtonDown() {
   		cout<<"Hola mundito :D !!!te queremos ! <3 "<<endl;
   		vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
   	}
};

