cmake_minimum_required(VERSION 3.7)
project(j2ae)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(EXECUTABLE_NAME "j2ae")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES
        main.cpp
        src/Engine/Game.cpp
        src/Engine/GameObject.cpp
        src/Game/Components/PhysicsComponent.cpp
        src/Game/Components/SpriteComponent.cpp
        src/Game/GameState/PausedGameState.cpp
        src/Game/GameState/PlayableGameState.cpp
        src/Game/GameState/TitleSequenceGameState.cpp
        src/Engine/Components/Component.cpp
        src/Engine/Systems/System.cpp
        src/Game/Systems/PhysicsSystem.cpp
        src/Game/Systems/UserMovementInputSystem.cpp
        src/Game/Systems/GraphicsSystem.cpp
        src/Game/Systems/UserCameraSystem.cpp
        src/Engine/Utility/ComponentCollection.cpp
        src/Engine/ObjectFactory.cpp
        src/Game/ObjectCreators/PlayerObjectCreator.cpp
        src/Engine/World/Scene.cpp
        src/Engine/World/SceneBuilder.cpp
        src/Game/Systems/CollisionSystem.cpp
        src/Game/Map/Map.cpp
        src/Game/Map/Systems/MapSystem.cpp
        src/Game/Map/Systems/MapRenderSystem.cpp
        src/Game/Map/MapLoader.cpp
        src/Game/Map/Systems/MapBoundaryCollisionSystem.cpp src/Game/ObjectCreators/SignObjectCreator.cpp src/Game/Systems/TitleSequenceSystem.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_subdirectory("lib/pugixml-1.8")
set(EXTERNAL_LIBS pugixml)

include_directories("lib/pugixml-1.8/src")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
add_executable(${EXECUTABLE_NAME}-dbg ${SOURCE_FILES})

find_package(SFML 2.4 REQUIRED system window graphics)

target_link_libraries(${EXECUTABLE_NAME} ${EXTERNAL_LIBS} ${SFML_LIBRARIES})