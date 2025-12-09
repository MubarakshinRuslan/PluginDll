#include <windows.h>
#include <stdio.h>

typedef void (*func_hello)();
typedef int (*func_add)(int, int);

int main() {
    HMODULE h = LoadLibraryA("plugin.dll");
    if (!h) {
        printf("Failed to load plugin.dll\n");
        return 1;
    }

    func_hello hello = (func_hello)GetProcAddress(h, "plugin_hello");
    func_add add = (func_add)GetProcAddress(h, "plugin_add");

    if (!hello || !add) {
        printf("Failed to load functions\n");
        FreeLibrary(h);
        return 1;
    }

    hello();

    int r = add(5, 7);
    printf("add(5,7) = %d\n", r);

    FreeLibrary(h);
    return 0;
}