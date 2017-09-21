#include <iostream>
#include <vector>
#include "mitkBaseData.h"

class svMask : public mitk::BaseData {
public:

svMask();
svMask(const svMask& other);
virtual ~svMask();

//public virtual methods inherited from mitk::BaseData that we need to write
virtual std::vector<std::string> GetClassHierarchy() override;
protected:

private:

}
