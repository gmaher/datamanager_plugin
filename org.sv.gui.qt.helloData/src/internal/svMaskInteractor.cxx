#include "svMaskInteractor.h"

svMaskInteractor::svMaskInteractor(){

}

svMaskInteractor::~svMaskInteractor(){

}

void svMaskInteractor::ConnectActionsAndFunctions(){
  std::cout << "connecting actions and functions\n";
  CONNECT_FUNCTION("paint",paint_);
  CONNECT_FUNCTION("press_a",press_a_);
}

void svMaskInteractor::paint_(mitk::StateMachineAction* a, mitk::InteractionEvent* e){
  std::cout << "painting\n";

  e->GetSender()->GetTimeStep(GetDataNode()->GetData());
  const mitk::InteractionPositionEvent* positionEvent = dynamic_cast<const mitk::InteractionPositionEvent*>(interactionEvent);
  if (positionEvent != NULL)
  {
      mitk::Point3D Point;
      Point = positionEvent->GetPositionInWorld();

      Itk::Image<int,3>::IndexType pixelIndex;

      const bool isInside =
        image->TransformPhysicalPointToIndex( Point, pixelIndex );
      if ( isInside )
        {
          Itk::Image<int,3>::PixelType pixelValue = image->GetPixel( pixelIndex );
          pixelValue = 1;
          image->SetPixel( pixelIndex, pixelValue );
        }
  }
}

void svMaskInteractor::press_a_(mitk::StateMachineAction* a, mitk::InteractionEvent* e){
  std::cout << "a pressed\n";
  e->GetSender()->GetRenderingManager()->RequestUpdateAll();
}
