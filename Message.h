#ifndef MESSAGE_H 
#define MESSAGE_H
#include <string>
#include <ctime>
  
class Message
{
public:Message ()
  {
  }
  
 
Message (const std::string & s, const std::string & t):
sender (s),
    
text (t) 
  {
    
timestamp = std::time (nullptr);
  
} 
 
const std::string & get_sender () const
  {
    
return sender;
  
}
   

const std::string & get_text () const
  {
    
return text;
  
}
   

std::time_t get_timestamp () const
  {
    
return timestamp;
  
}
private:  std::string sender;
  std::string text;
  std::time_t timestamp;
};


 
#endif // MESSAGE_H
