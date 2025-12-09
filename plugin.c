#include <stdio.h>

__declspec(dllexport)
void plugin_hello() {
    printf("Hello from DLL!\n");
}

__declspec(dllexport)
int plugin_add(int a, int b) {
    return a + b;
}