/**
main
====

Solve the main input and output here.
Within the main loop of your program, you must use the same polymorphic pointer to an Operating_system to manage multiple objects of type Cluster and Personal_surveillance_device.
Do not reference the objects directly.
Note: only a small fraction of your cpp implementations are tested in main.
**/

#include "managing_hierarchies.h"

#include<typeinfo>

int main()
{
  const string TYP_CLUSTER = "cluster";
  const string TYP_PHONE = "phone";
  const string EXITNOW = "0";
  const string ENCRYPT_YES = "yes";
  const string ENCRYPT_NO = "no";
  const short MY_SHORT_MAX = 32766;
  const long MY_LONG_MAX = 2147483646;
  const short MAX_TRY = 5;


  // Write your main here.
  bool runProgram = true;
  bool phoneNumberCorrect = true;

  string device;
  string myPhoneNumber;
  string encrypt;

  short usrSelected;
  short psdOSversion;

  //Max phone number input addtempts the system will accept before moving on
  short counter = 0;
  //short imeiAttempts = 0;

  int cluVersion;

  long imei;

  //pointers
  Operating_system *os;

  

  while (runProgram)
  {

    try
    {
      cout << "\nWhat devices do you need to manage (choose one or enter 0 to exit): phone, cluster" << endl;
      cin.clear();
      cin >> device;
      //make input lowercase
      if (device != "0")
      {
        for (short i = 0; i < device.length(); i++)
        {
          device[i] = std::tolower(device[i]);
        }
      }

      if (device == TYP_CLUSTER)
      {
        usrSelected = 1;
      }
      else if (device == TYP_PHONE)
      {
        usrSelected = 2;
      }
      else if (device == EXITNOW)
      {
        usrSelected = 3;
      }
      else
      {
        throw MyException();
      }


      //Selting selector
      switch (usrSelected)
      {
        //Cluster
      case 1:
        os = new Cluster;
        ((Cluster*)os)->get_func_purpose();
        try
        {
          cout << "What is the version number of your operating system?";
          cin >> cluVersion;
          ((Cluster*)os)->set_version_number(cluVersion);
          cout << "\nYour OS version number is: ";
          ((Cluster*)os)->get_version_number();
          cout << endl;
        }
        catch (const MyException &e)
        {
          cout << e.what() << endl;
        }
        delete ((Cluster*)os);
        break;

      //Phone
      case 2:

        os = new Personal_surveillance_device;
        cout << "What is your IMEI?" << endl;

        try
        {
          try
          {
            cin >> imei;
            if (imei > 0 && imei <= MY_LONG_MAX)
            {
              *((Personal_surveillance_device*)os)->my_IMEI = imei;
              ((Personal_surveillance_device*)os)->get_func_purpose();
            }
            else
            {
              throw MyException();
            }
          }
          catch (const MyException &e)
          {
            cout << e.what() << endl;
          }

          try
          {
            cout << "What is the version number of your operating system?" << endl;
            cin >> psdOSversion;
            ((Personal_surveillance_device*)os)->set_version_number(psdOSversion);
            cout << "Your OS version number is: ";
            ((Personal_surveillance_device*)os)->get_version_number();
            cout << endl;
          }
          catch (const MyException &e)
          {
            cout << e.what() << endl;
          }


          //getting phone number input
          cout << "What is your phone number?" << endl;
          cin.ignore();
          do
          {
            try
            {
              std::getline(cin, myPhoneNumber, '\n');
              ((Personal_surveillance_device*)os)->set_phone_number(myPhoneNumber);

              phoneNumberCorrect = true;
            }
            catch (const MyException &e)
            {
              phoneNumberCorrect = false;
              cout << "That was not a valid phone number, please try again." << endl;
            }
            //Counter only needed if you want to limit attempts
            //counter++;
          } while (phoneNumberCorrect == false);

          cout << "Your phone number is ";
          ((Personal_surveillance_device*)os)->get_phone_number();

          cout << "Would you like to encrypt your phone (type yes or no)?" << endl;
          cin >> encrypt;
          for (short i = 0; i < encrypt.length(); i++)
          {
            encrypt[i] = std::tolower(encrypt[i]);
          }
          if (encrypt == ENCRYPT_YES)
          {
            ((Personal_surveillance_device*)os)->set_pretend_encryption();
          }
          else if (encrypt == ENCRYPT_NO)
          {

          }
          else
          {
            throw MyException();
          }
        }
        catch (const MyException &e)
        {
          cout << e.what() << endl;
        }
        delete ((Personal_surveillance_device*)os);
        break;
        //Entered 0
      case 3:
        runProgram = false;
        cout << "Exiting now" << endl;
        break;
      default:
        cout << "Something has gone wrong.";
        runProgram = false;
      }
    }
    catch (const MyException &e)
    {
      cout << e.what() << endl;
    }
  }//End of While loop

  return 0;
}
