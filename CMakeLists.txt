cmake_minimum_required(VERSION 3.20)  # ✅ Исправлено
project(LAB2 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(LAB2
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    # Только cpp файлы и файлы ресурсов
)

# Добавляем заголовки для отображения в IDE
target_sources(LAB2 PRIVATE
    include/MainWindow.h
    include/WindowInt.h
    include/Sequence.h
    include/ArraySequence.h
    include/ListSequence.h
    include/LinkedList.h
    include/DynamicArray.h
    include/Exceptions.h
    include/MapUtils.h
)

target_link_libraries(LAB2
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS LAB2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET LAB2
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})