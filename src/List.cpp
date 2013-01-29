
template<class T> class List {
public:
	virtual void put(T el) = 0;
	virtual T get(int i) = 0;
	virtual void remove(int i) = 0;
	virtual int size() = 0;
};
