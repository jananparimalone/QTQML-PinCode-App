cmake_minimum_required(VERSION 3.16)

project(PinApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the necessary Qt modules
find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia Widgets)

qt_standard_project_setup(REQUIRES 6.5)

# Add Qt resource file
qt_add_resources(RESOURCES resources.qrc)  # Ensure the .qrc is processed

# Add executable
qt_add_executable(appPinApp
    main.cpp
    ${RESOURCES}  # Include the resources in the final executable
)

# Add QML module
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

# Set bundle properties for macOS
set_target_properties(appPinApp PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Link necessary Qt modules
target_link_libraries(appPinApp
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Widgets     # Ensure Widgets is linked
    PRIVATE Qt6::Multimedia  # Multimedia is linked for QMediaPlayer
)

# Copy the PinApp directory containing QML files into the app bundle's MacOS directory
file(COPY ${CMAKE_SOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR}/appPinApp.app/Contents/MacOS)

# Set up custom target for running with environment variable
if(APPLE)
    add_custom_target(run
        COMMAND ${CMAKE_BINARY_DIR}/appPinApp
        ENVIRONMENT "QML_XHR_ALLOW_FILE_READ=1"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

# Install rules (optional)
include(GNUInstallDirs)
install(TARGETS appPinApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
