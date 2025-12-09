Приложение с плагинами

Для компиляции плагина:
gcc -shared -o plugin.dll plugin.c -Wl,--out-implib,libplugin.a

Загрузчик компилируется по обычному
