#include <iostream>

using namespace std;

// 1
int idCnt = 0;

template <class T>
class MovableClass
{
private:
    T *_ressource;
    int _id;

public:

    //2
    MovableClass(T *ptr = nullptr)
    {
        _ressource = ptr;
        _id = ++idCnt;
        cout << _id << " Constructor " << sizeof(*ptr) << " byte\n";
    }

	// 3
    ~MovableClass()
    {
        cout << _id << " Destructor " << (_ressource != nullptr ? "(delete)\n" : "\n");
        delete _ressource;
    }

    // 4
    MovableClass(const MovableClass &source)
    {
        if (source._ressource != nullptr) {
            _ressource = new T;
            *_ressource = *source._ressource;
        }
        _id = ++idCnt;
        cout << _id << " Copy Constr. from " << source._id << "\n";
    }

    // 5
    MovableClass(MovableClass &&source)
    {
        _ressource = source._ressource;
        source._ressource = nullptr;

        _id = ++idCnt;
        cout << _id << " Move Constr. from " << source._id << "\n";
    }

    // 6
    MovableClass &operator=(const MovableClass &source)
    {
        cout << _id << " Copy Assignm. from " << source._id << "\n";

        if (&source == this)
            return *this;

        delete _ressource;
        _ressource = nullptr;

        if (source._ressource != nullptr) {
            _ressource = new T;
            *_ressource = *source._ressource;
        }

        return *this;
    }
	
    // 7
    MovableClass &operator=(MovableClass &&source)
    {
        cout << _id << " Move Assigm. from " << source._id << "\n";

        if (&source == this)
            return *this;

        _ressource = source._ressource;
        source._ressource = nullptr;

        return *this;
    }

    void printValueAndHandle()
    {
        cout << _id << " heap=" << _ressource;
        cout << ", *heap=" << (_ressource != nullptr ? *_ressource : 0.0) << endl;
    }
};

template <class T>
void moveObjectHere1(MovableClass<T> &&obj)
{
    obj.printValueAndHandle();
}

template <class T>
void moveObjectHere2(MovableClass<T> obj)
{
    obj.printValueAndHandle();
}

int main()
{
  // 1
  MovableClass<double> mc_d(new double{10});
  moveObjectHere1<double>(std::move(mc_d));
	moveObjectHere1<double>(std::move(mc_d));

  // 2
  moveObjectHere2<double>(std::move(mc_d));
  moveObjectHere2<double>(std::move(mc_d));

  return 0;
}