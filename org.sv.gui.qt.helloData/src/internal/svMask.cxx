#include "svMask.h"
#include "mitkPixelType.h"

svMask::svMask(){

};

svMask::svMask(const svMask& other)
  :BaseData(other)
{

  m_mask = other.GetImage()->Clone();


};

svMask::~svMask(){

};

void svMask::CreateInitialMask(mitk::Image *image){
  m_mask = itk::Image<int,3>::New();
  std::cout << "Made mask";
  itk::Image<int,3>::SizeType size;
  std::cout << "Getting Dimensions\n";
  unsigned int* dims = image->GetDimensions();
  std::cout << "Got Dimensions\n";
  size[0] = dims[0];
  size[1] = dims[1];
  size[2] = dims[2];

  itk::Image<int,3>::IndexType start;
  start[0] = 0;
  start[1] = 0;
  start[2] = 0;

  std::cout << "Setting region\n";
  itk::Image<int,3>::RegionType region;
  region.SetSize(size);
  region.SetIndex(start);

  std::cout << "allocating image\n";
  m_mask->SetRegions(region);
  m_mask->Allocate();
  m_mask->FillBuffer(0);
};

itk::Image<int,3>* svMask::GetImage(){
  return m_mask;
};
