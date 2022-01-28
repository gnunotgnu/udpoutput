//sugar.cpp

#include "sugar.hpp"

namespace cpp_sugar {
    using std::cout;
    using std::endl;
    using std::string;

    class PrintDebugMessage {


        template<typename T>
        void print(const string &msg, T value, const string &label = "default", int line = 0) {
            cout << "[" << label << "] <" << line << "> " << msg << value << endl;
        }

    public:
        void operator()() {

        }
    };
}

//EOF
