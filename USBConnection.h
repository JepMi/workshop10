#include <stack>
#include <memory>

class USBConnection {
private:
    int id;
    static std::stack<int> ids; 
    USBConnection(int id) : id(id) {}

public:

    static std::shared_ptr<USBConnection> create() {
        if (!ids.empty()) {
            int newId = ids.top();
            ids.pop();
            return std::shared_ptr<USBConnection>(new USBConnection(newId));
        } else {
            return nullptr; 
        }
    }

    
    ~USBConnection() {
        ids.push(id);
    }
};



std::stack<int> USBConnection::ids({3, 2, 1});
