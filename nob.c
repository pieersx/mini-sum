#include <string.h>

#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h" 
// La idea de implementación es de un desarrollador de software https://github.com/tsoding/nobuild

#define CFLAGS "-Wall", "-Wextra", "-std=c++17", "-pedantic"
#define LIBS "plug.cpp"

void create_build_directory()
{
#ifndef _WIN32
    if (access("build", F_OK) == -1) {
        CMD("mkdir", "build");
    }
#else
#include <io.h>
    if (access("build", F_OK) == -1) {
        CMD("cmd", "/c", "mkdir", "build");
    }
#endif // _WIN32
}

void compile_cpp(const char *filename)
{
    Cstr src_path = PATH("src", filename);
    Cstr build_path = PATH("build", NOEXT(filename));

#ifndef _WIN32
    CMD("cc", CFLAGS, "-o", build_path, src_path);
#else
    CMD("g++.exe", CFLAGS, "-o", build_path, src_path);
#endif // _WIN32
}

void compile_link_cpp(const char *main_file, const char *lib_file)
{
    Cstr src_path = PATH("src", main_file);
    Cstr lib_src_path = PATH("src", lib_file);
    Cstr build_path = PATH("build", NOEXT(main_file));

#ifndef _WIN32
    CMD("cc", CFLAGS, "-o", build_path, src_path, lib_src_path);
#else
    CMD("g++.exe", CFLAGS, "-o", build_path, src_path, lib_src_path);
#endif // _WIN32
}

void copy_txt(const char *filename)
{
    Cstr src_path = PATH("src", filename);
    Cstr build_path = PATH("build", filename);

#ifndef _WIN32
    CMD("cp", src_path, build_path);
#else
    CMD("cmd", "/c", "copy", src_path, build_path);
#endif // _WIN32
}

void compile_cpp_files()
{
    FOREACH_FILE_IN_DIR(filename, "src", {
        if (ENDS_WITH(filename, ".cpp")) {
            if (strcmp(filename, "main.cpp") == 0) {
                compile_link_cpp("main.cpp", LIBS);
            } else if (strcmp(filename, LIBS) != 0) {
                compile_cpp(filename);
            }
        } else if (ENDS_WITH(filename, ".txt")) {
            copy_txt(filename);
        }    
    });
}

int main(int argc, char **argv) 
{
    GO_REBUILD_URSELF(argc, argv);

    create_build_directory();
    compile_cpp_files();

    return 0;
}