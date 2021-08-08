/*
 * Key idea:
 *
 *   Here, we want to make sure that text's value doesn't get changed by
 *   sign.setText, because we want to use that value when we call
 *   signHistory.add.  Ergo the use of std::forward on only the final use of the
 *   universal reference.
 */

// TODO:
//  fix sign and signHistory

#include <chrono>
#include <utility>

#include <iostream>
#include <string>
#include <typeinfo>
#include <boost/type_index.hpp>


template<typename T>                       // text is
void setSignText(T&& text)                 // univ. reference
{
  // sign.setText(text);                      // use text, but
                                           // don't modify it

    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    // show T
    cout << "T =     "                        //T =     int
        << type_id_with_cvr<T>().pretty_name()
        << '\n';

    // show param's type
    cout << "param = "                        //param = int&&
        << type_id_with_cvr<decltype(text)>().pretty_name() << '\n'
        << "addr = " << &text <<'\n';         // ok

    const int&  inc =0;
    // show param's type
    cout << "inc = "                        //param = int&&
        << type_id_with_cvr<decltype(std::move(inc))>().pretty_name() << '\n'
        << "addr = " << &text <<'\n';         // ok

  auto now =                               // get current time
    std::chrono::system_clock::now();

  // signHistory.add(now,
  //                 std::forward<T>(text));  // conditionally cast
}                                          // text to rvalue


void fcr(const int& w)
{
    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    // show param's type
    cout << "w = "                        //param = int&&
        << type_id_with_cvr<decltype(w)>().pretty_name() << '\n'
        << "addr = " << &w <<'\n';         // ok
}

int main(){
  int x = 15;
  setSignText(x);
  // T =     int&
  // param = int&
  // addr = 0x7ffdb5bdaf84

  setSignText(15);
  // T =     int
  // param = int&&
  // addr = 0x7ffcbff69390

  fcr(x);
  return 0;
}