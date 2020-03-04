#include "BigInteger.h"
#include <ctype.h>


BigInteger::BigInteger()
{
  isNegative = false;
}

BigInteger::BigInteger(std::string really_big_number)
{
  isNegative = false;
  bool firstDigitNotZeroFound = false;

  for (int i = 0; i < really_big_number.length(); i++)
  {
    if (!isdigit(really_big_number[i]))
    {
      //cout << "Is not a digit" << endl;
      if (really_big_number[0] == '-')
      {
        isNegative = true;
      }
      else if (really_big_number[0] == '+')
      {
        isNegative = false;
      }
      else
      {
        digit_list.clear();
        throw BigIntException();
      }

      if (i != 0)
      {
        digit_list.clear();
        throw BigIntException();
      }
    }
    else
    {
      if (really_big_number[i] != '0' || firstDigitNotZeroFound)
      {
        firstDigitNotZeroFound = true;
        digit_list.push_back(really_big_number[i] - 48);
      }
    }
  }
  if (!firstDigitNotZeroFound)
  {
    digit_list.clear();
    isNegative = false;
    digit_list.push_back(0);

  }
}

std::string BigInteger::to_string()
{
  std::string really_big_number;
  int size = digit_list.size();

  for (int i = 0; i < size; i++)
  {
    really_big_number.insert(0, 1, '0' + digit_list.back());
    digit_list.pop_back();
  }

  if (isNegative == true)
  {
    really_big_number.insert(0, 1, '-');
  }
  else
  {
    really_big_number.insert(0, 1, '+');
  }
  return really_big_number;
}

// Speed tested for bonus points.
// https://en.wikipedia.org/wiki/Primality_test
bool is_prime();

BigInteger operator+(const BigInteger &bi1, const BigInteger &bi2)
{
  BigInteger bi3 = bi1;
  BigInteger bi4 = bi2;
  std::string left = bi3.to_string();
  std::string right = bi4.to_string();
  std::string strReasult;

  int differance = 0;
  int barrow = 0;
  int cary = 0;
  int sum = 0;
  int select = 0;
  bool leftLarger = false;
  bool absValueIdentical = false;

  /*
  Filter sides to find out what is degative
  if both numbers a possative then addition happens normaly
  */
  if (left[0] == '+' && right[0] == '+')
  {
    //Normal addition
    select = 0;
  }
  else if (left[0] == '+' && right[0] == '-')
  {
    select = 1;
  }
  else if (left[0] == '-' && right[0] == '+')
  {
    select = 2;
  }
  else if (left[0] == '-' && right[0] == '-')
  {
    select = 3;
  }



  if (left.length() > right.length())
  {
    leftLarger = true;
    differance = left.length() - right.length();
    right.insert(1, differance, '0');
  }
  else if (left.length() < right.length())
  {
    leftLarger = false;
    differance = right.length() - left.length();
    left.insert(1, differance, '0');
  }
  else if (left.length() == right.length())
  {
    for (int i = 1; i < left.length(); i++)
    {
      if (left[i] > right[i])
      {
        leftLarger = true;
        absValueIdentical = false;

        break;
      }
      else if (left[i] < right[i])
      {
        leftLarger = false;
        absValueIdentical = false;
        break;
      }
      else
      {
        absValueIdentical = true;
      }
    }
  }

  switch (select)
  {
    //Possative + Possative
  case 0:
    cary = 0;
    sum = 0;

    for (int i = left.length() - 1; i > 0; i--)
    {
      sum = (((left[i] - '0') + (right[i] - '0')) + cary) % 10;
      cary = (((left[i] - '0') + (right[i] - '0')) + cary) / 10;
      strReasult.insert(0, 1, '0' + sum);
    }
    if (cary == 1)
    {
      strReasult.insert(0, 1, '0' + cary);
    }
    strReasult.insert(0, 1, '+');
    break;
    //Possative + Negative
  case 1:
    if (leftLarger)
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((left[i] - '0') - (right[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }
    }
    else
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((right[i] - '0') - (left[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }
      strReasult.insert(0, 1, '-');
    }

    break;
    //Negative + Possative
  case 2:
    if (leftLarger)
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((left[i] - '0') - (right[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }
      strReasult.insert(0, 1, '-');
    }
    else
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((right[i] - '0') - (left[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }

    }
    break;
  case 3:
    cary = 0;
    sum = 0;

    for (int i = left.length() - 1; i > 0; i--)
    {
      sum = (((left[i] - '0') + (right[i] - '0')) + cary) % 10;
      cary = (((left[i] - '0') + (right[i] - '0')) + cary) / 10;
      strReasult.insert(0, 1, '0' + sum);
    }
    if (cary == 1)
    {
      strReasult.insert(0, 1, '0' + cary);
    }
    strReasult.insert(0, 1, '-');
    break;
  default:
    break;
  }
  BigInteger answer(strReasult);
  return answer;
}

BigInteger operator-(const BigInteger &bi1, const BigInteger &bi2)
{
  BigInteger bi3 = bi1;
  BigInteger bi4 = bi2;
  std::string left = bi3.to_string();
  std::string right = bi4.to_string();
  std::string strReasult;

  int differance = 0;
  int barrow = 0;
  int cary = 0;
  int sum = 0;
  int select = 0;
  bool leftLarger = false;
  bool absValueIdentical = false;
  /*
  Filter sides to find out what is degative
  if both numbers a possative then addition happens normaly
  */
  if (left[0] == '+' && right[0] == '+')
  {
    //Normal addition
    select = 0;
  }
  else if (left[0] == '+' && right[0] == '-')
  {
    select = 1;
  }
  else if (left[0] == '-' && right[0] == '+')
  {
    select = 2;
  }
  else if (left[0] == '-' && right[0] == '-')
  {
    select = 3;
  }

  if (left.length() > right.length())
  {
    leftLarger = true;
    differance = left.length() - right.length();
    right.insert(1, differance, '0');
  }
  else if (left.length() < right.length())
  {
    leftLarger = false;
    differance = right.length() - left.length();
    left.insert(1, differance, '0');
  }
  else if (left.length() == right.length())
  {
    for (int i = 1; i < left.length(); i++)
    {
      if (left[i] > right[i])
      {
        leftLarger = true;
        absValueIdentical = false;

        break;
      }
      else if (left[i] < right[i])
      {
        leftLarger = false;
        absValueIdentical = false;
        break;
      }
      else
      {
        absValueIdentical = true;
      }
    }
  }

  switch (select)
  {
    //Possative - possative
  case 0:
    if (leftLarger)
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((left[i] - '0') - (right[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }
    }
    else
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((right[i] - '0') - (left[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }
      strReasult.insert(0, 1, '-');
    }
    break;
    //Possative - negative
  case 1:
    cary = 0;
    sum = 0;

    for (int i = left.length() - 1; i > 0; i--)
    {
      sum = (((left[i] - '0') + (right[i] - '0')) + cary) % 10;
      cary = (((left[i] - '0') + (right[i] - '0')) + cary) / 10;
      strReasult.insert(0, 1, '0' + sum);
    }
    if (cary == 1)
    {
      strReasult.insert(0, 1, '0' + cary);
    }
    strReasult.insert(0, 1, '+');
    break;
    //Negative - Possative
  case 2:
    cary = 0;
    sum = 0;

    for (int i = left.length() - 1; i > 0; i--)
    {
      sum = (((left[i] - '0') + (right[i] - '0')) + cary) % 10;
      cary = (((left[i] - '0') + (right[i] - '0')) + cary) / 10;
      strReasult.insert(0, 1, '0' + sum);
    }
    if (cary == 1)
    {
      strReasult.insert(0, 1, '0' + cary);
    }
    strReasult.insert(0, 1, '-');

    break;
    //Negative - Negative
  case 3:
    if (leftLarger)
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((left[i] - '0') - (right[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }
      strReasult.insert(0, 1, '-');
    }
    else
    {
      for (int i = left.length() - 1; i > 0; i--)
      {
        sum = (((right[i] - '0') - (left[i] - '0')) - barrow);
        if (sum < 0)
        {
          sum += 10;
          barrow = 1;
        }
        else
        {
          barrow = 0;
        }
        strReasult.insert(0, 1, '0' + sum);
      }
    }
    break;
  default:
    break;
  }//End of switch

  BigInteger answer(strReasult);
  return answer;
}

BigInteger operator*(const BigInteger &bi1, const BigInteger &bi2)
{

}

BigInteger operator/(const BigInteger &bi1, const BigInteger &bi2)
{

}

// Recursion is a good idea from here down, especiall for speed on the exp:

// Speed tested for bonus points.
BigInteger gcd(const BigInteger dividend, const BigInteger divisor)
{

}
// Speed tested for bonus points.
// We made this a friend to allow use of recursion.
BigInteger gefficient_exp(const BigInteger base, long long power)
{

}