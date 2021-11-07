cmake_minimum_required (VERSION 3.19.0)

project(ECX_Maths)

set (SOURCES    ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Maths.h 
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Functions.h
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Vec2f.h     
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Vec3f.h     
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Vec4f.h     
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Mat2f.h     
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Mat3f.h     
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Mat4f.h
                ${CMAKE_CURRENT_SOURCE_DIR}/include/ECX_Quaternionf.h
    )
    
add_library(ECX_Maths INTERFACE ${SOURCES})

