#ifndef SVMASKINTERACTOR_H
#define SVMASKINTERACTOR_H
#include "svMask.h"

#include <mitkDataInteractor.h>
class svMaskInteractor : public mitk::DataInteractor
{
public:
  mitkClassMacro(svMaskInteractor, mitk::DataInteractor)
  itkFactorylessNewMacro(Self)
  itkCloneMacro(Self)

protected:
  svMaskInteractor();
  ~svMaskInteractor();

  virtual void ConnectActionsAndFunctions() override;

  virtual void paint(mitk::StateMachineAction*, mitk::InteractionEvent*);

  virtual void press_a(mitk::StateMachineAction*, mitk::InteractionEvent*);

  svMask* m_mask;

private:
};

#endif // SVMASKINTERACTOR_H
