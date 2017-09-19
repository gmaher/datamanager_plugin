#include "svHelloDataPluginActivator.h"
#include "svHelloData.h"

void svHelloDataPluginActivator::start(ctkPluginContext* context)
{

    BERRY_REGISTER_EXTENSION_CLASS(svHelloData, context)

}

void svHelloDataPluginActivator::stop(ctkPluginContext* context)
{

}
