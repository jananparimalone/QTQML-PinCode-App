# Auto-generated deploy QML imports script for target "appPinApp".
# Do not edit, all changes will be lost.
# This file should only be included by qt6_deploy_qml_imports().

set(__qt_opts BUNDLE)
if(arg_NO_QT_IMPORTS)
    list(APPEND __qt_opts NO_QT_IMPORTS)
endif()

_qt_internal_deploy_qml_imports_for_target(
    ${__qt_opts}
    IMPORTS_FILE "/Users/christopher/PinApp/PinApp/build/Qt_6_8_2_for_macOS-Debug/.qt/qml_imports/appPinApp_build.cmake"
    PLUGINS_FOUND __qt_internal_plugins_found
    QML_DIR     "appPinApp.app/Contents/Resources/qml"
    PLUGINS_DIR "appPinApp.app/Contents/PlugIns"
)

if(arg_PLUGINS_FOUND)
    set(${arg_PLUGINS_FOUND} "${__qt_internal_plugins_found}" PARENT_SCOPE)
endif()
