# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/main/cpp)

SET(jnisrc "src/main/cpp/")

SET(LIB_SRC src/main/cpp/native-lib.cpp  src/main/cpp/advanced_test.cpp  src/main/cpp/log4z.cpp src/main/cpp/fast_test.cpp)

IF(${ANDROID_ABI} STREQUAL "x86")

MESSAGE("这是x86的设置")
ELSEIF(${ANDROID_ABI} STREQUAL "armeabi-v7a")
MESSAGE("这是armeabi-v7a的设置")
ENDIF(${ANDROID_ABI} STREQUAL "x86")


MESSAGE(${ANDROID_ABI})
add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
           ${LIB_SRC})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )