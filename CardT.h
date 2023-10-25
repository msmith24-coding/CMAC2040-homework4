#ifndef CARDT_H_
#define CARDT_H_

template<typename T>
class CardT
{
    private:
        T value;
    public:
        CardT() = default;
        CardT(T _value);
        ~CardT() = default;
    public: /* Getter/Setter Methods  */
        void setValue(T _value);
        T getValue() const;
};

template <typename T>
CardT<T>::CardT(T _value)
{
    this->value = _value;
}

template <typename T>
void CardT<T>::setValue(T _value)
{
    this->value = _value;
}

template <typename T>
T CardT<T>::getValue() const
{
    return this->value;
}

#endif
