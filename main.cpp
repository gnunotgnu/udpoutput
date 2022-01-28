#include <iostream>
#include <clocale>

#include "colors.hpp"
#include "udp_class/udp_client_server.hpp"
#include "udp_class/udp_client_server.cpp"

#include "cpp_sugar/sugar.hpp"
#include "cpp_sugar/sugar.cpp"

void clear_buf(char *buf, const size_t &sz) {
    for (size_t i = 0; i < sz; i++) {
        buf[i] = 0;
    }
}
void clear_eol_buf(char *buf, const size_t &sz) {
    for (size_t i = 0; i < sz; i++) {
        if (buf[i] == '\n') buf[i] = 0;
    }
}

int main() {
    std::cout << "current locale: " << setlocale(LC_ALL, nullptr) << std::endl;
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::cout << "{setlocale(LC_ALL, \"ru_RU.UTF-8\");}" << std::endl;
    std::cout << "current locale: " << setlocale(LC_ALL, nullptr) << std::endl;
    std::cout << "DEFAULT_LOCALE = " << DEFAULT_LOCALE << std::endl;


    std::cout << FBLU("I'm blue.") << std::endl;
    std::cout << BOLD(FBLU("I'm blue-bold.")) << std::endl;

    using namespace udp_client_server;

    udp_server s = udp_server("127.0.0.1" , 6667);
    char buf[1024];
    std::string msg{"empty"};
    while (msg[0] != 'q') {
        clear_buf(buf, 1024);
        s.recv(buf, 1024);
        clear_eol_buf(buf, 1024);
        std::cout<< FBLU("[server]") << BOLD(" << ") << std::string{buf} << std::endl;
        msg = std::string{buf};
    }

    return 0;
}
