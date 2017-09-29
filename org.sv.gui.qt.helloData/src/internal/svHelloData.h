#ifndef SVHELLODATA_H
#define SVHELLODATA_H

#include <QmitkFunctionality.h>
#include <QString>
#include "svDataNodeOperationInterface.h"
namespace Ui {
class svHelloData;
}

class svHelloData : public QmitkFunctionality
{
    Q_OBJECT

public:

    svHelloData();

    virtual ~svHelloData();

    void UpdateImageList();

    void UpdateMaskList();

    virtual void CreateQtPartControl(QWidget *parent) override;

    static const QString EXTENSION_ID;

public slots:
    void printDataNodes();

    void printDataTypeNode();

    void CreateNewMask();

public:

protected:

  QString hello_str;

  Ui::svHelloData *ui;

  QWidget *m_parent;

  QmitkStdMultiWidget* m_DisplayWidget;

  svDataNodeOperationInterface* m_Interface;
};

#endif // SVHELLODATA_H
