add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(${PROJECT_NAME}
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

set(HDR_DEPS_CHK_FOLDER "${CMAKE_BINARY_DIR}/check_deps_headers")
file (MAKE_DIRECTORY "${HDR_DEPS_CHK_FOLDER}")
list(APPEND CHK_QTMVVM)
file(GLOB_RECURSE ALL_HPP "qtmvvm/*.hpp")
foreach(HDR ${ALL_HPP})
    get_filename_component(HDR_NAME ${HDR} NAME)
    file(COPY ${HDR} DESTINATION "${HDR_DEPS_CHK_FOLDER}")
    file(RENAME "${HDR_DEPS_CHK_FOLDER}/${HDR_NAME}" "${HDR_DEPS_CHK_FOLDER}/${HDR_NAME}.cpp")
    list(APPEND CHK_QTMVVM "${HDR_DEPS_CHK_FOLDER}/${HDR_NAME}.cpp")
endforeach()

# The EXCLUDE_FROM_ALL property prevents check_deps from being included in the default target
add_library(check_deps OBJECT EXCLUDE_FROM_ALL ${CHK_QTMVVM})

# We don't need to actually run the whole compiler. We're just checking that all the includes are valid
# So here we ask for only the syntax checking mode to be used.
# We also don't mind that there might be unused constant variables when doing deps checking.
target_compile_options(check_deps PUBLIC -Wno-unused-const-variable $<IF:$<CXX_COMPILER_ID:MSVC>,/Zs,-fsyntax-only>)

target_link_libraries(check_deps PUBLIC ${PROJECT_NAME})

install(DIRECTORY . DESTINATION include FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h")