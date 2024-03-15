cmake_minimum_required(VERSION 3.22.1)
project(shellcode_run)

include(CheckIncludeFiles)

check_include_files("sys/mman.h" HAVE_SYS_MMAN_H)
check_include_files("windows.h" HAVE_WINDOWS_H)
check_include_files("memoryapi.h" HAVE_MEMORYAPI_H)

if(HAVE_SYS_MMAN_H)
    set(osdep_sources ${osdep_sources} src/osdep/posix.c)
elseif(HAVE_WINDOWS_H AND HAVE_MEMORYAPI_H)
    set(osdep_sources ${osdep_sources} src/osdep/win.c)
else()
    message(FATAL_ERROR "unable to find headers to implement os-dependent functions!")
endif()

add_executable(sc_run src/sc_run.c ${osdep_sources})