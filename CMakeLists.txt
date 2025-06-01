cmake_minimum_required(VERSION 3.16)
project(FactoryComputer)

set(CMAKE_CXX_STANDARD 11)

# Установка версии пакета
if(NOT DEFINED PACKAGE_VERSION)
    set(PACKAGE_VERSION "1.0.0")
endif()

set(CPACK_PACKAGE_VERSION "${PACKAGE_VERSION}")
message(STATUS "Package version: ${PACKAGE_VERSION}")

# Настройка Google Test
option(INSTALL_GTEST "Install Google Test" OFF)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

# Основная библиотека
add_library(ComputerFactoryLib STATIC
    src/Computer.cpp
    src/ConcreteComputers.cpp
    src/ComputerFactories.cpp
)
target_include_directories(ComputerFactoryLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Исполняемый файл
add_executable(factory_computer main.cpp)
target_link_libraries(factory_computer ComputerFactoryLib)

# Тесты
enable_testing()
add_executable(computer_tests
    tests/test_computers.cpp
    src/Computer.cpp
    src/ConcreteComputers.cpp
    src/ComputerFactories.cpp
)
target_link_libraries(computer_tests
    gtest_main
    ComputerFactoryLib
)
target_include_directories(computer_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_test(NAME ComputerTests COMMAND computer_tests)

include(GoogleTest)
gtest_discover_tests(computer_tests)

# Установка для CPack
install(TARGETS factory_computer DESTINATION bin)
install(TARGETS ComputerFactoryLib DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Создание deb-пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14), libgcc-s1 (>= 3.0), libstdc++6 (>= 5.2)")

# Установка
install(TARGETS factory_computer DESTINATION bin)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/Computer.h
              ${CMAKE_CURRENT_SOURCE_DIR}/include/ConcreteComputers.h
              ${CMAKE_CURRENT_SOURCE_DIR}/include/ComputerFactories.h
        DESTINATION include/FactoryComputer)
include(CPack)
