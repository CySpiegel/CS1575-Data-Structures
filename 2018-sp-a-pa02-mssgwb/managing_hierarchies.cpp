/**
.cpp
====

This is the .cpp you should define and implement the functions and classes that are declared in the .h file.
Add any non-required functions here.
**/

#include "managing_hierarchies.h"
const short MY_SHORT_MAX = 32767;
const long MY_LONG_MAX = 2147483647;



//Set identity
void get_identity(string my_id[])
{
  // Implement your function here.
  my_id[0] = "Matthew Stroble";
  my_id[1] = "_";
}

//custom error message
const char * MyException::what() const throw()
{
  return "Custom error has occured";
}


//Machine class deffinition
// This is provided as an example of scoping and defining a class function
string Machine::get_function()
{
  cout << my_function;
  return my_function;
}



//Implamenting X86 Class functions
//Default Constructor
X86::X86()
{
  my_function = "Backward compatibile";
  num_cores = new bool[2];
}

//Param Default constructor
X86::X86(string init_function, int init_cores)
{
  my_function = init_function;
  try
  {
    if ((init_cores & 1) == 1)
      throw MyException();
    num_cores = new bool[init_cores];
  }
  catch (const MyException &e)
  {
    cout << e.what() << endl;
  }
}

//X86 Destructor
X86::~X86()
{
  delete[] num_cores;
  num_cores = NULL;
}

//X86 Set core possition
void X86::set_core_pos(int position, bool value)
{
  num_cores[position] = value;
  return;
}

//get core possition
bool X86::get_core_pos(int index)
{
  return num_cores[index];
}



//ARM class deffinitions
//ARM default constructor
ARM::ARM()
{
  my_function = "Reduced Instruction Set";
  num_bits = 64;
}

//ARM Param default constructor
ARM::ARM(string init_function, short init_bits)
{
  my_function = init_function;
  try
  {
    if (init_bits != 32 && init_bits != 64)
      throw MyException();
    num_bits = init_bits;
  }
  catch (const MyException &e)
  {
    cout << e.what() << endl;
  }
}

//ARM set number of bits
void ARM::set_num_bits(short set_bits)
{
  num_bits = set_bits;
  return;
}

//ARM get number of bits
short ARM::get_num_bits()
{
  cout << num_bits << endl;
  return num_bits;
}



//Operationg_system deffinitions
//returns purpose
string Operating_system::get_purpose()
{
  cout << purpose;
  return purpose;
}

//sets version number

void Operating_system::set_version_number(int set_ver_num)
{
  if (set_ver_num < 0)
    throw MyException();
  version_number = set_ver_num;
  return;
}

//Returns version number
int Operating_system::get_version_number()
{
  return version_number;
}



//Linux class Definition
//Default constructor
Linux::Linux()
{
  purpose = "Anything you want";
}

//Param Default constructor
Linux::Linux(string init_purpose)
{
  purpose = init_purpose;
}



//Android class deffinition
Android::Android()
{
  purpose = "Uploading your converstations to google";
  pretend_encryption = false;
}

void Android::set_pretend_encryption()
{
  pretend_encryption = !pretend_encryption;
  if (pretend_encryption == true)
  {
    cout << "Your device is now securely encrypted" << endl;
  }
  else
  {
    cout << "Encryption is now off" << endl;
  }
  return;
}



//Cluster deffinition
string Cluster::get_func_purpose()
{
  string cluMyFunction, cluMyPurpose, catSentiance;

  cout << "Your cluster architecture is ";
  cluMyFunction = get_function();
  cout << ", its purpose is ";
  cluMyPurpose = get_purpose();
  cout << ", and lots of it!" << endl;

  catSentiance = "Yout cluster architecture is " + cluMyFunction
    + ", its purpose is " + cluMyPurpose + ", and lots of it!";
  return cluMyPurpose;
}

void Cluster::set_version_number(int set_ver_num)
{
  try
  {
    if (set_ver_num > MY_SHORT_MAX || set_ver_num < 0)
      throw MyException();

    version_number = set_ver_num;
  }
  catch (const MyException &e)
  {
    cout << e.what() << endl;
  }
  return;
}

int Cluster::get_version_number()
{
  cout << version_number;
  return version_number;
}

//Personal survallance device deffinitions
//Default constructor
Personal_surveillance_device::Personal_surveillance_device()
{
  /*
  Directions states = 0000
  but I would use NULL instead.
  */
  my_IMEI = new long;
  *my_IMEI = 0000;
}

Personal_surveillance_device::Personal_surveillance_device(long input_my_IEMI)
{
  my_IMEI = new long;
  *my_IMEI = input_my_IEMI;
}

Personal_surveillance_device::~Personal_surveillance_device()
{
  delete my_IMEI;
  my_IMEI = NULL;
}

Personal_surveillance_device::Personal_surveillance_device(const Personal_surveillance_device &source)
{
  delete my_IMEI;
  my_IMEI = new long(*source.my_IMEI);
  my_phone_number = source.my_phone_number;
  my_function = source.my_function;
  purpose = source.purpose;

}


Personal_surveillance_device & Personal_surveillance_device::operator=(const Personal_surveillance_device &rhs)
{
  
  delete my_IMEI;
  my_IMEI = new long;
  *my_IMEI = *rhs.my_IMEI;
  my_phone_number = rhs.my_phone_number;
  my_function = rhs.my_function;
  purpose = rhs.purpose;

  return *this;
}


void Personal_surveillance_device::set_phone_number(string init_phone)
{
  const short ARR_SIZE = 10;
  bool inputCorrect = true;
  bool isNumberFound = false;

  char isNumber[ARR_SIZE] = { '0','1', '2', '3', '4' , '5', '6', '7' , '8', '9' };

  //string validNumber[15] = {'+',''}

  //try
  {
    /*
    Validity Checking Phone Number
    Valid phone numbers can not have an area code that begins with 0 or 1
    */
    if (init_phone.length() == 16)
    {
      if (init_phone[0] != '+' || init_phone[1] != '1' || init_phone[2] != '('
        || init_phone[3] == '0' || init_phone[3] == '1' || init_phone[6] != ')'
        || init_phone[7] != '-' || init_phone[11] != '-')
      {

        inputCorrect = false;
        throw MyException();
      }

      //number testing last two digits of the area code
      for (short i = 4; i < 6; i++)
      {
        isNumberFound = false;
        for (short k = 0; k < ARR_SIZE; k++)
        {
          if (init_phone[i] == isNumber[k])
          {
            isNumberFound = true;
          }
        }
        if (isNumberFound == false)
        {
          inputCorrect = false;
          throw MyException();
        }
      }
      //Checking the first 3 digits of phone number
      for (short i = 8; i < 11; i++)
      {
        isNumberFound = false;
        for (short k = 0; k < ARR_SIZE; k++)
        {
          if (init_phone[i] == isNumber[k])
          {
            isNumberFound = true;
          }
        }
        if (isNumberFound == false)
        {
          inputCorrect = false;
          throw MyException();
        }
      }
      //Checking last 4 digits of Phone number.
      for (short i = 12; i < 16; i++)
      {
        isNumberFound = false;
        for (short k = 0; k < ARR_SIZE; k++)
        {
          if (init_phone[i] == isNumber[k])
          {
            isNumberFound = true;
          }
        }
        if (isNumberFound == false)
        {
          inputCorrect = false;
          throw MyException();
        }
      }
    }
    else
    {
      inputCorrect = false;
      throw MyException();
    }

    if (inputCorrect)
    {
      my_phone_number = init_phone;
    }
  }
  return;
}

string Personal_surveillance_device::get_phone_number()
{
  cout << my_phone_number << endl;
  return my_phone_number;
}

void Personal_surveillance_device::set_version_number(int set_ver_num)
{
  if (set_ver_num < 0)
    throw MyException();
  version_number = set_ver_num;
  return;
}

int Personal_surveillance_device::get_version_number()
{
  cout << version_number;
  return version_number;
}

string Personal_surveillance_device::get_func_purpose()
{
  string psdMyFunction, psdMyPurpose, psdSentiance;

  cout << "Your phone architecture is ";
  psdMyFunction = get_function();
  cout << ", its purpose is ";
  psdMyPurpose = get_purpose();
  cout << ", and it follows you around!" << endl;

  psdSentiance = "Yout phone architecture is " + psdMyFunction
    + ", its purpose is " + psdMyPurpose + ", it follows you around!";
  return psdSentiance;
}