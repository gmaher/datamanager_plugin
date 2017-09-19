#include "svHelloData.h"
#include "ui_svHelloData.h"
#include <mitkNodePredicateDataType.h>

const QString svHelloData::EXTENSION_ID = "org.sv.views.hello";

svHelloData::svHelloData() :
  ui(new Ui::svHelloData)
{


}

svHelloData::~svHelloData(){
  delete ui;
}

void svHelloData::CreateQtPartControl(QWidget *parent){
  m_Parent=parent;
  ui->setupUi(parent);

  m_DisplayWidget=GetActiveStdMultiWidget();

  if(m_DisplayWidget==NULL)
  {
      parent->setEnabled(false);
      MITK_ERROR << "Plugin Hello Init Error: No QmitkStdMultiWidget!";
      return;
  }

  connect(ui->helloPushButton, SIGNAL(clicked()), this, SLOT(printDataNodes()) );
  connect(ui->helloPushType, SIGNAL(clicked()), this, SLOT(printDataTypeNode()) );

}

void svHelloData::printDataNodes(){
  mitk::DataStorage::SetOfObjects::ConstPointer rs=GetDataStorage()->GetAll();
  for (int i = 0; i < rs->size(); i++){
    mitk::DataNode::Pointer Node=rs->GetElement(i);
    std::cout << i << ": " << Node->GetName() << "\n";
  }
}

void svHelloData::printDataTypeNode(){
  std::string str = ui->helloLineEdit->text().toStdString();
  const char* cstr = str.c_str();
  mitk::NodePredicateDataType::Pointer TypeCondition = mitk::NodePredicateDataType::New(cstr);

  mitk::DataStorage::SetOfObjects::ConstPointer rs=GetDataStorage()->GetSubset(TypeCondition);

  if (rs->size() == 0){
    std::cout << "No nodes found with type " << str << "\n";
  }
  else{
    for (int i = 0; i < rs->size(); i++){
      mitk::DataNode::Pointer Node=rs->GetElement(i);
      std::cout << i << ": " << Node->GetName() << "\n";
    }
  }
}
