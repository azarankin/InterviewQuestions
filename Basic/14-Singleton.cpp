class Singleton {
    private:
        Singleton() {} // בנאי פרטי
        static Singleton* instance;
    
    public:
        static Singleton* getInstance() {
            if (!instance)
                instance = new Singleton();
            return instance;
        }
    };
    
    Singleton* Singleton::instance = nullptr;
    


    int main()
    {

        Singleton* a = Singleton::getInstance();
        Singleton* b = Singleton::getInstance();

        if (a == b) {
            std::cout << "אותו מופע בדיוק\n";
        }
    }