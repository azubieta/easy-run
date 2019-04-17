# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

add_executable(rundialog-qt main.cpp MainDialog.h MainDialog.cpp MainDialog.ui)
target_link_libraries(rundialog-qt Qt5::Core Qt5::Widgets Qt5::Gui)

install(TARGETS rundialog-qt RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
