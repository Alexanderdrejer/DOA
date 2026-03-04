# =============================================================================
# CMakeLists.txt - Multi-projekt C++ skabelon
# =============================================================================
# STRUKTUR:
#   projects/
#   ├── week1/
#   │   ├── opgave1/
#   │   │   ├── src/main.cpp
#   │   │   └── include/
#   │   └── opgave2/
#   │       ├── src/main.cpp
#   │       └── include/
#   └── week2/
#       └── ...
#
# SÅDAN TILFØJER DU EN NY OPGAVE:
#   1. Opret mappen: projects/week1/opgave3/
#   2. Opret undermapper: src/ og include/
#   3. Tilføj main.cpp i src/
#   4. Gem - CMake finder det automatisk!
#
# SÅDAN KØRER DU I VSCODE:
#   - Vælg target (f.eks. "week1_opgave1") nederst i statuslinjen
#   - Tryk F5 for at køre
# =============================================================================

cmake_minimum_required(VERSION 3.20)

# ─────────────────────────────────────────────────────────────────────────────
# PROJEKT OPSÆTNING
# ─────────────────────────────────────────────────────────────────────────────
project(AlgoritmerOgDatastrukturer)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ─────────────────────────────────────────────────────────────────────────────
# COMPILER WARNINGS - Hjælper dig med at finde fejl
# ─────────────────────────────────────────────────────────────────────────────
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wuninitialized")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

# ─────────────────────────────────────────────────────────────────────────────
# DELT KODE (valgfrit) - Kode der bruges af flere projekter
# ─────────────────────────────────────────────────────────────────────────────
# Læg fælles kode i shared/src/ og shared/include/
# Eksempel: Hjælpefunktioner du bruger i flere uger

set(SHARED_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/shared/include)
file(GLOB SHARED_SOURCES "shared/src/*.cpp")

if(SHARED_SOURCES)
    add_library(shared_lib STATIC ${SHARED_SOURCES})
    target_include_directories(shared_lib PUBLIC ${SHARED_INCLUDE_DIR})
endif()

# ─────────────────────────────────────────────────────────────────────────────
# AUTOMATISK PROJEKT OPDAGELSE
# ─────────────────────────────────────────────────────────────────────────────
# Scanner: projects/{uge}/{opgave}/src/main.cpp
# Bygger:  {uge}_{opgave}.exe

file(GLOB WEEK_DIRS "projects/*")

foreach(WEEK_DIR ${WEEK_DIRS})
    if(IS_DIRECTORY ${WEEK_DIR})
        get_filename_component(WEEK_NAME ${WEEK_DIR} NAME)

        # Find alle opgave-mapper i denne uge
        file(GLOB ASSIGNMENT_DIRS "${WEEK_DIR}/*")

        foreach(ASSIGNMENT_DIR ${ASSIGNMENT_DIRS})
            # Tjek om det er en opgave med src/main.cpp
            if(IS_DIRECTORY ${ASSIGNMENT_DIR} AND EXISTS "${ASSIGNMENT_DIR}/src/main.cpp")
                get_filename_component(ASSIGNMENT_NAME ${ASSIGNMENT_DIR} NAME)

                # Byg navn: week1_opgave1
                set(TARGET_NAME "${WEEK_NAME}_${ASSIGNMENT_NAME}")

                # Find alle .cpp filer
                file(GLOB ASSIGNMENT_SOURCES "${ASSIGNMENT_DIR}/src/*.cpp")

                # Opret executable
                add_executable(${TARGET_NAME} ${ASSIGNMENT_SOURCES})

                # Tilføj lokal include mappe
                if(EXISTS "${ASSIGNMENT_DIR}/include")
                    target_include_directories(${TARGET_NAME} PRIVATE "${ASSIGNMENT_DIR}/include")
                endif()

                # Link til delt kode
                if(SHARED_SOURCES)
                    target_link_libraries(${TARGET_NAME} PRIVATE shared_lib)
                    target_include_directories(${TARGET_NAME} PRIVATE ${SHARED_INCLUDE_DIR})
                endif()

                message(STATUS "Fundet: ${TARGET_NAME}")
            endif()
        endforeach()
    endif()
endforeach()

# ─────────────────────────────────────────────────────────────────────────────
# INFO
# ─────────────────────────────────────────────────────────────────────────────
message(STATUS "")
message(STATUS "════════════════════════════════════════════════════════")
message(STATUS "  Ny opgave: Opret projects/weekX/opgaveY/src/main.cpp")
message(STATUS "════════════════════════════════════════════════════════")
