/*
 * Key idea:
 *
 *   An effective way to get a compiler to show a type it has deduced is to use
 *   that type in a way that leads to compilation problems.  The error message
 *   reporting the problem is virtually sure to mention the type that's causing
 *   it.
 */

template<typename T>  // declaration only for TD;
class TD;             // TD = "Type Displayer"

const int theAnswer = 42;

auto x = theAnswer;
auto y = &theAnswer;

// TD<decltype(x)> xType;  // elicit errors containing
// TD<decltype(y)> yType;  // x's and y's types

class Widget {
public:
  Widget() {};
  Widget(int x) {};

  Widget(int i, bool b) {};    // ctors not declaring
  Widget(int i, double d) {};  // std::initializer_list params

// Default initialization values for non-static data members.
private:
  int x{0};   // fine, x's default value is 0
  int y = 0;  // also fine
  //int z(0);   // error!

};

Widget w2;

TD<decltype(w2)> w2Type;