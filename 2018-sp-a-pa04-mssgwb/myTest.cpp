/* Sample tester
 * We've included vector below to show you how your types should behave.
 * You can use that for debugging.
 * As in the assignment description, if you use the std::vector for your submitted code,
 * you will get a 0.
 */


#include "BigInteger.h"
#include "MyVector.h"


int main()
{
  MyVector<int> v;

  std::string psychoticNumber;

  //for (int i = 0; i < 100; i++)
    //psychoticNumber.push_back('7');

  cout << "String has 100 million, moving to setting BigInteger" << endl;
  //cout << psychoticNumber << endl;

  //cout << psychoticNumber << endl;
  //for (int i = 0; i < 1000000000; i++)
  //  v.push_back(1);
  //v.reserve(1);
  //cout << "Capacity: " << v.capacity() << endl << endl;
 
  //for (int i = 0; i < 1000000000; i++)
  //  v.pop_back();
  //cout << "Capacity: " << v.capacity() << endl << endl;
  //
  std::string init_string("+10");
  std::string init_string2("-10");

  //BigInteger my_big_int(init_string);
  BigInteger my_big_int(init_string);
  //cout << my_big_int.to_string() << endl;
  BigInteger another_big_int = my_big_int;
  //cout << "another_big_int: " << another_big_int.to_string() << endl;
  BigInteger yet_another_big_int(init_string2);
  //cout << "yet_another_big_int: " << yet_another_big_int.to_string() << endl;

  cout << "Adding big int" << endl;

  my_big_int = another_big_int + yet_another_big_int;
  cout << "BigInt Addition: " << my_big_int.to_string() << endl;
  my_big_int = another_big_int - yet_another_big_int;
  cout << "BigInt Subtraction: " << my_big_int.to_string() << endl;
  my_big_int = another_big_int = yet_another_big_int - another_big_int;
  cout << "BigInt Subtraction: " << my_big_int.to_string() << endl;
   
  return 0;
}

