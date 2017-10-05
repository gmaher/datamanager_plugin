#include "svMaskInteractor.h"

svMaskInteractor::svMaskInteractor(){

}

svMaskInteractor::~svMaskInteractor(){

}

void svMaskInteractor::ConnectActionsAndFunctions(){
  std::cout << "connecting actions and functions\n";
  CONNECT_FUNCTION("paint",paint);
  CONNECT_FUNCTION("press_a",press_a);
}

void svMaskInteractor::paint(mitk::StateMachineAction*, mitk::InteractionEvent*){
  std::cout << "painting\n";
}

void svMaskInteractor::press_a(mitk::StateMachineAction*, mitk::InteractionEvent*){
  std::cout << "a pressed\n";
}
