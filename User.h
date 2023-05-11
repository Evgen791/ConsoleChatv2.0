#ifndef USER_H 
#define USER_H

#include <string>
  
class User
{
public: User ():online (false)
  {
  }
  
 
User (const std::string & n, const std::string & p):
name (n),
    
password (p), 
online (false) 
  {
  } 
 
void set_online (bool value)
  {
    
online = value;
  
} 
 
bool is_online ()const
  {
    
return online;
  
}
   

const std::string & get_name () const
  {
    
return name;
  
}
   

bool verify_password (const std::string & input_password) const
  {
    
return input_password == password;
  
}
private:  std::string name;
  std::string password;
  bool online;
};


 
#endif // USER_H
