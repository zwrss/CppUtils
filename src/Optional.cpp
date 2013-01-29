
template<class T> class Optional{
public:
	virtual T get(T e) = 0;
	virtual bool isSet() = 0;
};

template<class T> class Yes : public Optional<T>{
public:
	T x;
	Yes(T x):x(x){}

	T get(T e){
		return x;
	}

	bool isSet(){
		return true;
	}
};

template<class T> class No : public Optional<T>{
public:
	No(){}

	T get(T e){
		return e;
	}

	bool isSet(){
		return false;
	}
};
