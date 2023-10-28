#ifndef CARDT_H_
#define CARDT_H_

template<typename T>
class CardT
{
    private:
        T value;
        bool isFlipped;
    public:
        CardT() = default;
        CardT(T _value);
        ~CardT() = default;
    public: /* Getter/Setter Methods  */
        void setValue(T _value);
        T getValue() const;
        void toggleFlip();
        void setFlipped(bool _isFlipped);
        bool getFlipped();
};

template <typename T>
CardT<T>::CardT(T _value)
{
    this->value = _value;
    this->isFlipped = false;
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

template <typename T>
void CardT<T>::toggleFlip()
{
    this->isFlipped = !this->isFlipped;
}

template <typename T>
void CardT<T>::setFlipped(bool _isFlipped)
{
    this->isFlipped = _isFlipped;
}

template <typename T>
bool CardT<T>::getFlipped()
{
    return this->isFlipped;
}

#endif
