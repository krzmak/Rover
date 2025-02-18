cmake_minimum_required(VERSION 3.14)

# Opcja do włączania/wyłączania testów
option(ENABLE_TESTS "Enable unit tests" OFF)  # Domyślnie testy są wyłączone

if(ENABLE_TESTS)
    # Pliki testowe
    set(TESTFILES main.cpp)
    
    # Nazwa testowego pliku wykonywalnego
    set(TEST_MAIN unit_tests)
    set(TEST_RUNNER_PARAMS "-V")

    # Tworzenie testowego pliku wykonywalnego
    add_executable(${TEST_MAIN} ${TESTFILES})
    target_link_libraries(${TEST_MAIN} PRIVATE ${LIBRARY_NAME} doctest)
    
    # Ustawienia właściwości dla testowego pliku wykonywalnego
    set_target_properties(${TEST_MAIN} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
        CXX_STANDARD 17 
        CXX_STANDARD_REQUIRED YES 
        CXX_EXTENSIONS NO
    )
    
    target_set_warnings(${TEST_MAIN} ENABLE ALL AS_ERROR ALL DISABLE Annoying)

    # Rejestracja testu
    add_test(
        NAME ${LIBRARY_NAME}.${TEST_MAIN}
        COMMAND ${TEST_MAIN} ${TEST_RUNNER_PARAMS}
    )

    # Dodanie celu 'fulltest', który uruchamia wszystkie testy
    add_custom_target(fulltest
        ${TEST_MAIN} -s
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

    # Coverage (jeśli jest włączone)
    include(CodeCoverage)

endif()

