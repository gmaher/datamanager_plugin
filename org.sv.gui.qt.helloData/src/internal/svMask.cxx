#include "svMask.h"

svMask::svMask(){
  m_mask = mitk::Image();
};

svMask::svMask(const svMask& other){
:BaseData(other);
  m_mask = mitk::Image(other->GetImage());
};

svMask::~svMask(){

};

void setImage(mitk::Image *image){

};

mitk::Image getImage(){
  return *m_mask;
};
