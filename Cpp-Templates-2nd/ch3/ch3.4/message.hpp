template <auto T>
class Message
{
public:
    void print() const {
        std::cout << T << std::endl;
    }
};

template <decltype(auto) N>
class CAuto{
public:
    void print() const {
        std::cout << N << std::endl;
    }
};