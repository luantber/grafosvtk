#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkAlgorithmOutput.h>
#include <vtkSphereSource.h>
#include <vtkWorldPointPicker.h>

#include <vtkVectorText.h>
#include <vtkFollower.h>



#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRendererCollection.h>
#include <vtkPointPicker.h>
#include <vtkCoordinate.h>
//typedef vtkSmartPointer VSP;

typedef vtkSmartPointer<vtkPolyDataMapper> PolyDataMapper;
typedef vtkSmartPointer<vtkActor> Actor;
typedef vtkSmartPointer<vtkRenderWindow> RenderWindow;
typedef vtkSmartPointer<vtkRenderWindowInteractor> RenderWindowInteractor;
typedef vtkSmartPointer<vtkRenderer> Renderer;
typedef vtkSmartPointer<vtkAlgorithmOutput> AlgorithmOutput;
typedef vtkSmartPointer<vtkSphereSource> SphereSource;
typedef vtkSmartPointer<vtkWorldPointPicker> WorldPointPicker;

typedef vtkSmartPointer<vtkVectorText> VectorText;
typedef vtkSmartPointer<vtkFollower> Follower;


typedef vtkSmartPointer<vtkInteractorStyleTrackballCamera> InteractorStyleTrackballCamera;
typedef vtkSmartPointer<vtkRendererCollection> RendererCollection;
typedef vtkSmartPointer<vtkPointPicker> PointPicker;
typedef vtkSmartPointer<vtkCoordinate> Coordinate;