cmake_minimum_required(VERSION 3.6.0)

project("vscore")
add_link_options(-Wl,-z,max-page-size=16384)
# ==============================================================================
# USER CONFIGURATION - Update these values to match your Android project
# ==============================================================================

# Your Java/Kotlin package path (using '/' separators)
# Example: com/example/yourapp/mldsa/vscore
set(JAVA_MODULE_PATH com/silencelaboratories/godilithium)

# Your Java/Kotlin package name (using '.' separators) — must match JAVA_MODULE_PATH
# Example: com.example.yourapp.mldsa.vscore
set(JAVA_PACKAGE_NAME com.silencelaboratories.godilithium)

# Path where SWIG-generated Java sources will be placed (adjust to your project layout)
# Typical Android: ${PROJECT_ROOT}/app/build/generated/java/${JAVA_MODULE_PATH}
set(GENERATED_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../java/${JAVA_MODULE_PATH})

# Path where SWIG-generated C++ wrapper will be placed (adjust to your project layout)
# Typical Android: ${PROJECT_ROOT}/app/build/generated/cpp/
set(SWIG_WRAPPER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Path to the prebuilt libvscore.so per ABI
# Typical Android: ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libvscore.so
set(LIBVSCORE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/${ANDROID_ABI}/libvscore.so)

# ==============================================================================
# Build configuration — no changes needed below unless customizing further
# ==============================================================================

find_package(SWIG REQUIRED)
include(UseSWIG)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# SWIG interface
set(SWIG_INTERFACE vscore.i)
set(CMAKE_SWIG_FLAGS -package ${JAVA_PACKAGE_NAME})
set(SWIG_OUTPUT_DIR ${GENERATED_SOURCES_DIR})

file(MAKE_DIRECTORY ${SWIG_WRAPPER_DIR})
file(MAKE_DIRECTORY ${SWIG_OUTPUT_DIR})

set_property(SOURCE vscore.i PROPERTY SWIG_MODULE_NAME vscore)

# Import prebuilt libvscore
add_library(libvscore SHARED IMPORTED)
set_target_properties(libvscore PROPERTIES IMPORTED_LOCATION ${LIBVSCORE_PATH})

# JNI helper libraries
add_library(tss_buffer_util SHARED ${CMAKE_CURRENT_SOURCE_DIR}/tssBufferUtil.c)
add_library(go_slice_util SHARED ${CMAKE_CURRENT_SOURCE_DIR}/goSliceUtil.c)

# Create SWIG wrapper and link
swig_add_library(
        vscoreswig
        LANGUAGE java
        SOURCES ${SWIG_INTERFACE}
        OUTFILE_DIR ${SWIG_WRAPPER_DIR}
        OUTPUT_DIR ${SWIG_OUTPUT_DIR}
)

target_link_libraries(vscoreswig libvscore tss_buffer_util go_slice_util ${log-lib})
