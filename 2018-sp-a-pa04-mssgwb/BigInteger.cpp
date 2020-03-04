#include "BigInteger.h"
#include <ctype.h>


BigInteger::BigInteger()
{
  digit_vector[0] = 0;
  isNegative = false;
}


//BigInteger readin
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
        digit_vector.clear();
        throw BigIntException();
      }

      if (i != 0)
      {
        digit_vector.clear();
        throw BigIntException();
      }
    }
    else
    {
      if (really_big_number[i] != '0' || firstDigitNotZeroFound)
      {
        firstDigitNotZeroFound = true;
        digit_vector.push_back(really_big_number[i] - 48);
      }
    }
  }
  if (!firstDigitNotZeroFound)
  {
    digit_vector.clear();
    isNegative = false;
    digit_vector.push_back(0);

  }
}


std::string BigInteger::BigInteger::to_string()
{
  std::string really_big_number;

  if (isNegative == true)
  {
    for (int i = 0; i < digit_vector.size(); i++)
    {
      if (i == 0)
        really_big_number.push_back('-');
      really_big_number.push_back('0' + digit_vector[i]);
    }
  }
  else
  {
    for (int i = 0; i < digit_vector.size(); i++)
    {
      if (i == 0)
        really_big_number.push_back('+');
      really_big_number.push_back('0' + digit_vector[i]);
    }
  }
  return really_big_number;
}


//Adition
BigInteger operator+(BigInteger &bi1, BigInteger &bi2)
{
  std::string left = bi1.to_string();
  std::string right = bi2.to_string();
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

//Subtraction
BigInteger operator-(BigInteger &bi1, BigInteger &bi2)
{
  std::string left = bi1.to_string();
  std::string right = bi2.to_string();
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