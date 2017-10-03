set(SRC_CPP_FILES

)

set(INTERNAL_CPP_FILES
    svHelloData.cxx
    svMask.cxx
    svMaskInteractor.cxx
    svHelloDataPluginActivator.cxx
)

set(MOC_H_FILES
    src/internal/svHelloData.h
    src/internal/svMask.h
    src/internal/svMaskInteractor.h
    src/internal/svHelloDataPluginActivator.h
)

set(UI_FILES
    src/internal/svHelloData.ui
)

set(CACHED_RESOURCE_FILES
  plugin.xml
  resources/hello.png
  resources/interactions/config.xml
  resources/interactions/statemachine.xml
)

set(QRC_FILES

)

set(CPP_FILES )

foreach(file ${SRC_CPP_FILES})
  set(CPP_FILES ${CPP_FILES} src/${file})
endforeach(file ${SRC_CPP_FILES})

foreach(file ${INTERNAL_CPP_FILES})
  set(CPP_FILES ${CPP_FILES} src/internal/${file})
endforeach(file ${INTERNAL_CPP_FILES})
