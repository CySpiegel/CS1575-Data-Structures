/*
Pure virtual class
Make the Android class immediately below here.
It should inherit Operating_system.
It's purpose should be default-constructed to: "Uploading your converstations to google"
It should have no parameterized consructor.
It should have one private variable, a boolean, named pretend_encryption
It should have one function called set_pretend_encryption(), with void return type. It should swap the value of pretend_ercryption, and print out either:
If the bool is switched to 1, then cout: "Your device is now securely encrypted"
If the bool is switched to 0, then cout: "Encryption is now off"
*/
class Android: public Operating_system
{
private:
  bool pretend_encryption;
public:
  Android();
  void set_pretend_encryption();
};