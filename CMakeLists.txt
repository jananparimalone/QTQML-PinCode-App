cmake_minimum_required(VERSION 3.16)

project(PinApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia Widgets)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_resources(RESOURCES resources.qrc)

qt_add_executable(appPinApp
    main.cpp
    ${RESOURCES}
)

qt_add_qml_module(appPinApp
    URI PinApp
    VERSION 1.0
    QML_FILES
        Main.qml
        Welcome.qml
    SOURCES
        passcodevalidator.h
        passcodevalidator.cpp
        FileReader.cpp
        FileReader.h
        videohandler.h
        videohandler.cpp
)

set_target_properties(appPinApp PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPinApp
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Widgets
    PRIVATE Qt6::Multimedia
)

if(APPLE)
    add_custom_target(run
        COMMAND ${CMAKE_BINARY_DIR}/appPinApp
        ENVIRONMENT "QML_XHR_ALLOW_FILE_READ=1"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

include(GNUInstallDirs)
install(TARGETS appPinApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
