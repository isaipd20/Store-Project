#include <string>

namespace Vendor{
    class vendor {
        private:
            int id;
            int quantity;
            double price;
            std::string name;

        public:
            void addItems();
            void removeItems();
            void changeItems();
            void itemStatus();
        };

}