
cmake_minimum_required(VERSION 2.8)

PROJECT(grafosvtk)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(grafosvtk MACOSX_BUNDLE grafosvtk)
set_property(TARGET grafosvtk PROPERTY CXX_STANDARD 11)

if(VTK_LIBRARIES)
  target_link_libraries(grafosvtk ${VTK_LIBRARIES})
else()
  target_link_libraries(grafovtk vtkHybrid vtkWidgets)
endif()
