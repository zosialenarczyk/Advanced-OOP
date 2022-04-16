cmake_minimum_required(VERSION 3.13)
project(net_simulation)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Werror=switch)

include_directories(include)
set(SOURCE_FILES src/package.cpp src/storage_types.cpp
        src/nodes.cpp src/helpers.cpp src/factory.cpp src/reports.cpp src/simulation.cpp)
add_executable(netsim ${SOURCE_FILES} main.cpp)

# == Unit testing using Google Testing Framework ==

# Ustaw zmienną `SOURCES_FILES_TESTS`, która będzie przechowywać ścieżki do
# plików źródłowych z testami jednostkowymi.
set(SOURCES_FILES_TESTS
        test/test/nodes_test.cpp
        test/test/test_Factory.cpp
        test/test/test_nodes.cpp
        test/test/test_package.cpp
        test/test/test_storage_types.cpp

        test/test/test_factory_io.cpp
        test/test/test_reports.cpp
        test/test/test_simulate.cpp
        )

# Dodaj konfigurację typu `Test`.
add_executable(netsim_test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/test/main_gtest.cpp)

# Dodaj katalogi z plikami nagłówkowymi wyłącznie do konkretnej konfiguracji (tu: `Test`).
target_include_directories(netsim_test PUBLIC
        googletest-master/googlemock/include
        googletest-master/googletest/include
        test/mocks
        )

# Dodaj podkatalog `googletest-master`.
add_subdirectory(googletest-master)

# Podlinkuj bibliotekę o identyfikatorze `gmock` (w pliku CMake) wyłącznie do konkretnej
# konfiguracji (tu: `Test`).
target_link_libraries(netsim_test gmock)