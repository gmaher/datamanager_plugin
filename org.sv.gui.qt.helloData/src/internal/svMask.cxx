#include "svMask.h"

svMask::svMask(){
  m_mask = mitk::Image::New();
};

svMask::svMask(const svMask& other)
  :BaseData(other)
{
  m_mask = mitk::Image::New();
  m_mask->Initialize(itk::ImageIOBase::INT,
    *(other.GetImage()->GetUpdatedGeometry()));
};

svMask::~svMask(){

};

void CreateInitialMask(mitk::Image *image){

};

mitk::Image* GetImage(){
  return m_mask;
};
