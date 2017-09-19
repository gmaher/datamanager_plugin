#ifndef SVHELLODATAPLUGINACTIVATOR_H
#define SVHELLODATAPLUGINACTIVATOR_H

#include <ctkPluginActivator.h>

class svHelloDataPluginActivator :
        public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org_sv_gui_qt_helloData")
    Q_INTERFACES(ctkPluginActivator)

public:

//    static ctkPluginContext* GetContext();
//    static svPathPlanningPluginActivator* GetInstance();

    void start(ctkPluginContext* context) override;
    void stop(ctkPluginContext* context) override;

private:

};

#endif // SVHELLODATAPLUGINACTIVATOR_H
