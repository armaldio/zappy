cmake_minimum_required(VERSION 3.7)
project(clientqt)

# Force debug mode without parameters
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Programme Name
set(EXECUTABLE_NAME clientqt)

# Version C++
set(CMAKE_CXX_STANDARD 11)

# Add local cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

###
# Find SFML
###

find_package(SFML 2 REQUIRED audio graphics window system)

###
# Find QT
###

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

##
# Find Thread
##

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Sources
set(SOURCE_FILES
        src/main.cpp
        src/QSFML/QSFMLWidget.cpp
        src/RenderCanvas.cpp
        include/QSFML/QSFMLWidget.hpp
        include/RenderCanvas.hpp
        src/QSFML/KeyConverter.cpp
        include/QSFML/KeyConverter.hpp
        src/MainWindow.cpp
        include/MainWindow.hpp
        src/Scene/SceneManager.cpp
        include/Scene/SceneManager.hpp
        src/Scene/Scene.cpp
        include/Scene/Scene.hpp
        src/Scene/SplashScene.cpp
        include/Scene/SplashScene.hpp
        include/Singleton.hpp
        include/Game/Inventaire.hpp
        src/Scene/GameScene.cpp
        include/Scene/GameScene.hpp
        src/Network/TCPSocket.cpp
        include/Network/TCPSocket.hpp
        src/Network/Network.cpp
        include/Network/Network.hpp
        include/Network/SafeQueue.hpp
        include/Game/GameExeception.hpp
        src/Game/Inventaire.cpp
        include/Game/Inventaire.hpp
        src/Game/Player.cpp
        include/Game/Player.hpp
        src/Game/Tile.cpp
        include/Game/Tile.hpp
        src/Game/Game.cpp
        include/Game/Game.hpp
        src/Game/Team.cpp
        include/Game/Team.hpp src/Game/Egg.cpp include/Game/Egg.hpp src/Game/Animation.cpp include/Game/Animation.hpp src/Model/TeamTableModel.cpp include/Model/TeamTableModel.hpp src/Model/PlayerTableModel.cpp include/Model/PlayerTableModel.hpp src/Model/EggTableModel.cpp include/Model/EggTableModel.hpp src/Model/TileTableModel.cpp include/Model/TileTableModel.hpp src/Model/MessageTableModel.cpp include/Model/MessageTableModel.hpp)

qt5_wrap_ui(UI_SRC src/UI/MainWindow.ui)

# Includes directory
include_directories(${CMAKE_BINARY_DIR} ${SFML_INCLUDE_DIR} "include")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES} ${UI_SRC} ${MOC_SRCS} ${RES_SOURCES} ${UI_HEADERS})

# Linkage
# build it (link libraries)
target_link_libraries(${EXECUTABLE_NAME} Qt5::Widgets)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(${EXECUTABLE_NAME} Threads::Threads)

if (UNIX)
    target_link_libraries(${EXECUTABLE_NAME} "-lX11")
endif(UNIX)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR} COMPONENT copyAssets)