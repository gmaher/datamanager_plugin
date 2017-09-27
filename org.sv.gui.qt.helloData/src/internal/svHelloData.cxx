#include "svHelloData.h"
#include "ui_svHelloData.h"
#include <mitkNodePredicateDataType.h>
#include "svMask.h"

#include "svDataNodeOperation.h"

#include <mitkDataStorage.h>
#include <mitkDataNode.h>
#include <mitkNodePredicateDataType.h>
#include <mitkUndoController.h>
#include <mitkImage.h>

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
  connect(ui->CreateMaskPushButton, SIGNAL(clicked()), this, SLOT(CreateNewMask()) );

  UpdateImageList();
  std::cout <<"Making operation interface\n";
  m_Interface= new svDataNodeOperationInterface();
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

void svHelloData::UpdateImageList(){
  mitk::NodePredicateDataType::Pointer TypeCondition = mitk::NodePredicateDataType::New("Image");

  mitk::DataStorage::SetOfObjects::ConstPointer rs=GetDataStorage()->GetSubset(TypeCondition);

  if (rs->size() == 0){
    std::cout << "No images found, cannot create mask\n";
    return ;
  }
  ui->svHelloDataImageListView->clear();

  for (int i = 0; i < rs->size(); i++){
    mitk::DataNode::Pointer Node=rs->GetElement(i);
    std::cout << i << ": " << Node->GetName() << "\n";
    ui->svHelloDataImageListView->addItem(Node->GetName().c_str());
  }

}

void svHelloData::CreateNewMask(){
  std::cout << "create new mask clicked\n";
  QListWidgetItem* currentImage = ui->svHelloDataImageListView->currentItem();

  if (currentImage == NULL){
    MITK_ERROR << "No Image selected, please select an image" << std::endl;
    return;
  }

  const char* image_name = currentImage->text().toStdString().c_str();

  mitk::DataNode::Pointer image_node = GetDataStorage()->GetNamedNode(image_name);

  if (image_node.IsNull()){
    MITK_ERROR << "Image " << image_name << " not found" << std::endl;
    return;
  }

  //check that no current mask already exists with the specified name
  std::string mask_name = ui->CreateMaskLineEdit->text().toStdString();
  mitk::DataNode * mask_node_existing = GetDataStorage()->GetNamedNode(mask_name);
  if (!(mask_node_existing == NULL)){
    MITK_ERROR << "Mask with name " << mask_name << " already exists, use a\
      different name\n";
  }

  std::cout <<"making mask\n";
  svMask::Pointer mask = svMask::New();
  std::cout <<"creating initial mask\n";
  mitk::Image* image_data = dynamic_cast<mitk::Image*>(image_node->GetData());

  if (image_data == NULL){
    MITK_ERROR << "Image data is null, cannot create mask\n";
  }
  mask->CreateInitialMask(image_data);

  std::cout <<"adding mask to data manager\n";

  mitk::DataNode::Pointer mask_node = mitk::DataNode::New();
  mask_node->SetName(mask_name);

  std::cout <<"Setting node data\n";
  mask_node->SetData(mask);



  std::cout <<"making operation\n";

  mitk::OperationEvent::IncCurrObjectEventId();
  std::cout <<"eventid\n";
  bool undoEnabled=true;
  svDataNodeOperation* doOp = new svDataNodeOperation(svDataNodeOperation::OpADDDATANODE,
    GetDataStorage(),mask_node,image_node);
  std::cout <<"if statement\n";
  if(undoEnabled)
  {
      svDataNodeOperation* undoOp = new svDataNodeOperation(
        svDataNodeOperation::OpREMOVEDATANODE,GetDataStorage(),mask_node,image_node);
      mitk::OperationEvent *operationEvent = new mitk::OperationEvent(
        m_Interface, doOp, undoOp, "Add DataNode");
      mitk::UndoController::GetCurrentUndoModel()->SetOperationEvent( operationEvent );
  }
  std::cout <<"executing operation\n";

  m_Interface->ExecuteOperation(doOp);
  std::cout <<"operation executed\n";

}
