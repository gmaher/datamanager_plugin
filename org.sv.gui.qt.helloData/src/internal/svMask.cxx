#include "svMask.h"
#include "mitkPixelType.h"

svMask::svMask(){
  m_mask = mitk::Image::New();
};

svMask::svMask(const svMask& other)
  :BaseData(other)
{
  m_mask = mitk::Image::New();

  CreateInitialMask(other.GetImage());


};

svMask::~svMask(){

};

void svMask::CreateInitialMask(mitk::Image *image){
  mitk::PixelType ptype = mitk::MakeScalarPixelType<int>();
  m_mask->Initialize(ptype,
    *(image->GetUpdatedGeometry()));
};

mitk::Image* svMask::GetImage(){
  return m_mask;
};
