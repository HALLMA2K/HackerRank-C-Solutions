#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
  public:
     Message() {}
        Message(const int &p_ID, const string &p_Message) : p_ID_(p_ID), p_Message_(p_Message){}

        const string& get_text() {
            return p_Message_;
        }

        const int &get_ID() const {
            return p_ID_;
        }
  private:
    int p_ID_;
    string p_Message_;

};

bool operator<(const Message &lhs, const Message &rhs)
{
    return lhs.get_ID() < rhs.get_ID();
}

class MessageFactory {
  public:
    MessageFactory() {}
    Message create_message(const string& p_Text) {
      return {p_id++, p_Text};
    }
  private:
    int p_id = 0;
};

class Recipient {
  public:
    Recipient() {}
    void receive(const Message& msg) {
      messages_.push_back(msg);
    }
    void print_messages() {
      fix_order();
      for (auto& msg : messages_) {
        cout << msg.get_text() << endl;
      }
        messages_.clear();
    }
  private:
    void fix_order() {
      sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
  public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
    random_shuffle(messages.begin(), messages.end());         
    for (auto msg : messages) {
      recipient.receive(msg);
    }
  }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    
    while (getline(cin, text)) {
      messages.push_back(message_factory.create_message(text));
    }
    
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
