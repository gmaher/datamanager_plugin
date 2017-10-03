#include "svMaskInteractor.h"

svMaskInteractor::svMaskInteractor(){

}

svMaskInteractor::~svMaskInteractor(){

}

void svMaskInteractor::ConnectActionsAndFunctions(){

  CONNECT_FUNCTION("paint",paint);
}

void svMaskInteractor::paint(mitk::StateMachineAction*, mitk::InteractionEvent*){
  std::cout << "painting\n";
}
