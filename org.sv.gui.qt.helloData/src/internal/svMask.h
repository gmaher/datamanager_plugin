#ifndef SVMASK_H
#define SVMASK_H

#include <iostream>
#include <vector>
#include "mitkBaseData.h"
#include "mitkImage.h"
#include <QListView>

class svMask : public mitk::BaseData {

public:

  mitkClassMacro(svMask, mitk::BaseData);
  itkFactorylessNewMacro(Self)
  itkCloneMacro(Self)

  void CreateInitialMask(mitk::Image *image);

  itk::Image<int,3>* GetImage();


  //virtual methods, that need to be implemented due to mitk::BaseData inheriting
  //from itk::DataObject
  //however if we dont intend to use this object with an itk filter we can leave them
  //empty
  virtual void UpdateOutputInformation() {};
  virtual void SetRequestedRegionToLargestPossibleRegion() {};
  virtual bool RequestedRegionIsOutsideOfTheBufferedRegion() { return false;};
  virtual bool VerifyRequestedRegion() { return true;};
  virtual void SetRequestedRegion(const itk::DataObject *data) {};

protected:

  mitkCloneMacro(Self);
  svMask();
  svMask(const svMask& other);
  virtual ~svMask();

private:

  itk::Image<int,3>::Pointer m_mask;
};

#endif //SVMASK_H
