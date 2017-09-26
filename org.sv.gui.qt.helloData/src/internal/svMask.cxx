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
  std::cout << "making pixel type\n";
  mitk::PixelType ptype =
    mitk::MakePixelType< itk::Image< int, 3 > >();

  std::cout << "initializing image\n";
  m_mask->Initialize(ptype, 3, image->GetDimensions());
  std::cout << "Done initializing image\n";
};

mitk::Image* svMask::GetImage(){
  return m_mask;
};
