#include "compress.h"

Widget w;

using namespace std::placeholders;

auto compressRateB = std::bind(compress, w, _1); // w stored by value

auto compressRateB = std::bind(compress, std::ref(w), _1); // w stored by ref

int main()
{
    compressRateB(CompLevel::High);    // how is arg
                                       // passed?
}
