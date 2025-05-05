project(MachineLib)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14)

set(SOURCE_FILES
        pch.h
        IMachineSystem.h
        MachineSystemFactory.cpp MachineSystemFactory.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h
        Const.cpp
        Const.h
        MachineSystemStandin.h
        MachineSystemStandin.cpp
        MachineStandin.cpp
        MachineStandin.h
        Polygon.cpp
        Polygon.h
        MachineSystem.cpp
        MachineSystem.h
        Machine.cpp
        Machine.h
        MachineCFactory.cpp
        Component.cpp
        Component.h
        Shape.cpp
        Shape.h
        Motor.cpp
        Motor.h
        RotationSource.cpp
        RotationSource.h
        RotationSink.cpp
        RotationSink.h
        Pulley.cpp
        Pulley.h
        Flag.cpp
        Flag.h
        Bubbles.cpp
        Bubbles.h
        BubbleBlower.cpp
        BubbleBlower.h
        Machine2Factory.cpp
        Machine2Factory.h

)

# Removed:
# Motor.cpp Motor.h Pulley.cpp Pulley.h

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
