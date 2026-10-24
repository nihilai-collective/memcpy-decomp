# SPDX-License-Identifier: MIT
# Copyright (c) 2026 Nihilai Collective Corp
# https://github.com/nihilai-collective/memcpy-decomp
# CMakeLists.txt
cmake_minimum_required (VERSION 3.31)

set(CMAKE_CXX_STANDARD 20)

project (
    memcpy-decomp
    LANGUAGES CXX
)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install/)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)

include(FetchContent)
include(GetCommitHash.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/GetCommitHash.cmake)
FetchContent_Declare(
  benchmarksuite
  GIT_REPOSITORY https://github.com/nihilai-collective/benchmarksuite.git
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(benchmarksuite)
getCommitHash(${benchmarksuite_SOURCE_DIR} BNCH_SWT_COMMIT_HASH)

FetchContent_Declare(
  rt-ut
  GIT_REPOSITORY https://github.com/nihilai-collective/rt-ut.git
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(rt-ut)

add_executable (memcpy-decomp "memcpy-decomp.cpp")

target_link_libraries(
	${PROJECT_NAME} PUBLIC 
	benchmarksuite::benchmarksuite
	rt-ut::rt-ut
)

set(MEMCPY_DECOMP_MSVC_COMPILER_OPTIONS
    /O2
    /Oi
    /Ot
    /Ob3
    /GL
    /GS-
    /Gy
    /Gw
    /fp:precise
    /arch:AVX2
    /Zc:inline
    /favor:blend
)

set(MEMCPY_DECOMP_CLANG_COMPILER_OPTIONS
    -O3
    -march=native
    -mtune=native
    -fomit-frame-pointer
    -funroll-loops
    -fmerge-all-constants
    -fstrict-aliasing
    -fno-semantic-interposition
    -fvectorize
    -fslp-vectorize
)

set(MEMCPY_DECOMP_MSVC_LINKER_OPTIONS
    /LTCG
    /OPT:REF
    /OPT:ICF
)

set(MEMCPY_DECOMP_APPLE_CLANG_COMPILER_OPTIONS
    ${MEMCPY_DECOMP_CLANG_COMPILER_OPTIONS}
)

if(APPLE)
    set(MEMCPY_DECOMP_GCC_LTO)
    set(MEMCPY_DECOMP_GCC_TARGET_OPTIONS -mcpu=native)
else()
    set(MEMCPY_DECOMP_GCC_LTO -flto=auto -ffat-lto-objects)
    set(MEMCPY_DECOMP_GCC_TARGET_OPTIONS -march=native -mtune=native)
endif()

set(MEMCPY_DECOMP_GCC_COMPILER_OPTIONS
    -O3
    ${MEMCPY_DECOMP_GCC_TARGET_OPTIONS}
    -fomit-frame-pointer
    -funroll-loops
    -fmerge-all-constants
    -fstrict-aliasing
    -fno-semantic-interposition
    -ftree-vectorize
    ${MEMCPY_DECOMP_GCC_LTO}
)

target_compile_options(
    ${PROJECT_NAME} PUBLIC
    $<$<CXX_COMPILER_ID:Clang>:${MEMCPY_DECOMP_CLANG_COMPILER_OPTIONS}>
    $<$<CXX_COMPILER_ID:AppleClang>:${MEMCPY_DECOMP_APPLE_CLANG_COMPILER_OPTIONS}>
    $<$<CXX_COMPILER_ID:GNU>:${MEMCPY_DECOMP_GCC_COMPILER_OPTIONS}>
    $<$<CXX_COMPILER_ID:MSVC>:${MEMCPY_DECOMP_MSVC_COMPILER_OPTIONS}>
)

target_link_options(
    ${PROJECT_NAME} PUBLIC
    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<NOT:$<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>>>:-fuse-ld=lld;-Wl,-O2;-Wl,--gc-sections;-Wl,-z,now>
    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>>:-Wl,-dead_strip>
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<NOT:$<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>>>:-Wl,-O2;-Wl,--gc-sections;-Wl,-z,now>
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>>:-Wl,-dead_strip>
    $<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>>:-Wl,-dead_strip>
    $<$<CXX_COMPILER_ID:MSVC>:${MEMCPY_DECOMP_MSVC_LINKER_OPTIONS}>
)

target_compile_definitions(
	${PROJECT_NAME} PUBLIC 
	"BASE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}\""
    "BNCH_SWT_COMMIT=\"${BNCH_SWT_COMMIT_HASH}\""
    MCD_CI_RUN=$<BOOL:${MCD_CI_RUN}>
)

install(
    TARGETS memcpy-decomp
    DESTINATION bin
)