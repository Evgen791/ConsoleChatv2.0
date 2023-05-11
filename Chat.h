#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include "User.h"
#include "Message.h"
  
class Chat
{
public:
    // Конструктор класса Chat, инициализирующий поля класса
    Chat() :
        current_user(NULL) // Необходимо явно инициализировать указатель нулевым значением, в данном случае - NULL
    {}

    // Регистрация нового пользователя в системе
    void register_user(const std::string& name, const std::string& password)
    {
        if (usernames.find(name) == usernames.end())
        {
            users[name] = User(name, password);
            usernames.insert(name);
        }
    }

    // Логин пользователя в систему
    bool login(const std::string& name, const std::string& password)
    {
        auto it = users.find(name);
        if (it != users.end() && it->second.verify_password(password))
        {
            it->second.set_online(true);
            current_user = &it->second;
            return true;
        }
        return false;
    }

    // Логаут пользователя из системы
    void logout()
    {
        if (current_user)
        {
            current_user->set_online(false);
            current_user = NULL;
        }
    }

    // Проверка, есть ли пользователь в системе
    bool is_logged_in() const
    {
        return current_user != NULL;
    }

    // Отправка сообщения от залогиненного пользователя
    void send_message(const std::string& text)
    {
        if (current_user)
        {
            messages.push_back(Message(current_user->get_name(), text));
        }
    }

    // Получение списка сообщений
    std::vector<Message> get_messages() const
    {
        return messages;
    }

    // Получение списка пользователей, которые в данный момент онлайн
    std::vector<User> get_users() const
    {
        std::vector<User> online_users;
        for (const auto& it : users)
        {
            if (it.second.is_online())
            {
                online_users.push_back(it.second);
            }
        }     
        return online_users;
    }

private:
    std::set<std::string> usernames; // Множество зарегистрированных пользователей
    std::vector<Message> messages; // Вектор сообщений
    std::map<std::string, User> users; // Ассоциативный массив пользователей (ключ - имя пользователя)
    User* current_user; // Указатель на залогиненного пользователя

    std::set<Message>::const_reverse_iterator find_last_message_by_user(const std::string& username) const;
};

#endif // CHAT_H